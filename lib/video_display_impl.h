/* -*- c++ -*- */
/*
 * Copyright 2023 gr-videoDisplay author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_IMPL_H
#define INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_IMPL_H

#include "video_player.h"
#include <gnuradio/videoDisplay/video_display.h>
#include <QtCore/QTemporaryFile>
#include <qapplication.h>
#include <QByteArray>
#include <QDataStream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

namespace gr {
namespace videoDisplay {

class video_display_impl : public video_display
{
private:
    const size_t d_itemsize;
    FILE* d_fp;
    char* d_argv;
    const char* d_filename;
    video_player* d_video_player;
    QWidget* d_parent;
    video_player_signal* d_video_player_signal;

public:
    video_display_impl(size_t itemsize, const char* filename, QWidget* parent = nullptr);
    ~video_display_impl();

    void exec_() override;
    QApplication* d_qApplication;
    QWidget* qwidget() override;

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items) override;
};

} // namespace videoDisplay
} // namespace gr

#endif /* INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_IMPL_H */
