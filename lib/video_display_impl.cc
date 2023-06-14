/* -*- c++ -*- */
/*
 * Copyright 2023 gr-videoDisplay author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "video_display_impl.h"
#include <gnuradio/io_signature.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QDebug>

#ifdef HAVE_IO_H
#include <io.h>
#endif
#ifdef O_BINARY
#define OUR_O_BINARY O_BINARY
#else
#define OUR_O_BINARY 0
#endif

// should be handled via configure
#ifdef O_LARGEFILE
#define OUR_O_LARGEFILE O_LARGEFILE
#else
#define OUR_O_LARGEFILE 0
#endif

namespace gr {
namespace videoDisplay {

video_display::sptr
video_display::make(size_t itemsize, const char* filename, QWidget* parent)
{
    return gnuradio::make_block_sptr<video_display_impl>(itemsize, filename, parent);
}

video_display_impl::video_display_impl(size_t itemsize,
                                       const char* filename,
                                       QWidget* parent)
    : gr::sync_block("video_display",
                     gr::io_signature::make(1, 1, itemsize),
                     gr::io_signature::make(0, 0, 0)),
      d_itemsize(itemsize),
      d_filename(filename),
      d_parent(parent)
{
    d_argv = nullptr;
    d_qApplication = nullptr;

    if (qApp != nullptr) {
        d_qApplication = qApp;
    } else {
        int argc = 1;
        d_argv = new char;
        d_argv[0] = '\0';
        d_qApplication = new QApplication(argc, &d_argv);
    }

    int flags = O_WRONLY | O_CREAT | O_TRUNC | OUR_O_LARGEFILE | OUR_O_BINARY;
    // truncate the file to zero bytes
    int fd = open(d_filename, flags, 0666);
    if (fd < 0) {
        qWarning() << "Could not open file " << d_filename;
        return;
    }
    close(fd);
    // open the file for appending
    d_fp = std::fopen(d_filename, "ab+");
    if (!d_fp) {
        qWarning() << "Could not open file " << d_filename;
        return;
    }
    // QFile file(d_filename);
    // file.open(QIODevice::ReadOnly);
    // QByteArray videoBuffer = file.readAll();
    d_video_player = new video_player(d_parent, d_filename);
    // d_video_player_signal = new video_player_signal();

    // QObject::connect(d_video_player_signal,
    //                  &video_player_signal::data_send,
    //                  d_video_player,
    //                  &video_player::data_read);
}

video_display_impl::~video_display_impl() {}

void video_display_impl::exec_() { d_qApplication->exec(); }

QWidget* video_display_impl::qwidget() { return (QWidget*)d_video_player; }

int video_display_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    const char* inbuf = static_cast<const char*>(input_items[0]);

    int nwritten = 0;

    if (!d_fp)
        return noutput_items; // drop output on the floor

    while (nwritten < noutput_items) {
        const int count = fwrite(inbuf, d_itemsize, noutput_items - nwritten, d_fp);
        if (count == 0) {
            if (ferror(d_fp)) {
                std::stringstream s;
                s << "file_sink write failed with error " << fileno(d_fp) << std::endl;
                throw std::runtime_error(s.str());
            } else {
                break;
            }
        }
        nwritten += count;
        inbuf += count * d_itemsize;
    }

    fflush(d_fp);

    // if inbuf not empty, send signal to video_player
    // if (inbuf != nullptr && *inbuf != '\0') {
    //     QFile file(d_filename);
    //     file.open(QIODevice::ReadOnly);
    //     QByteArray videoBuffer = file.readAll();
    //     // emit d_video_player_signal->data_send(videoBuffer);
    // }


    return noutput_items;
}

} /* namespace videoDisplay */
} /* namespace gr */
