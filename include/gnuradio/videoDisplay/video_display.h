/* -*- c++ -*- */
/*
 * Copyright 2023 gr-videoDisplay author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_H
#define INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_H

#include <gnuradio/sync_block.h>
#include <gnuradio/videoDisplay/api.h>
#include <qapplication.h>
#include <QWidget>

namespace gr {
namespace videoDisplay {

/*!
 * \brief <+description of block+>
 * \ingroup videoDisplay
 *
 */
class VIDEODISPLAY_API video_display : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<video_display> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of videoDisplay::video_display.
     *
     * To avoid accidental use of raw pointers, videoDisplay::video_display's
     * constructor is in a private implementation
     * class. videoDisplay::video_display::make is the public interface for
     * creating new instances.
     */
    static sptr make(size_t itemsize, const char* filename, QWidget* parent = nullptr);
    virtual void exec_() = 0;
    virtual QWidget* qwidget() = 0;
};

} // namespace videoDisplay
} // namespace gr

#endif /* INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_H */
