/* -*- c++ -*- */
/*
 * Copyright 2023 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
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
 * \brief A video display block for displaying video in a Qt widget.
 * \ingroup videoDisplay
 *
 * \details
 * This block displays video in a Qt widget. The widget is created
 * in the constructor and can be accessed with the qwidget() method.
 * The widget is a QWidget and can be used as a child widget in
 * other Qt widgets.
 *
 */
class VIDEODISPLAY_API video_display : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<video_display> sptr;

    /*!
     * \brief Build a video display block.
     *
     * \param itemsize The size of the items in the video stream.
     * \param parent The parent widget.
     *
     * \returns A shared_ptr to a new video_display block.
     */
    static sptr make(size_t itemsize, QWidget* parent = nullptr);
    virtual void exec_() = 0;
    virtual QWidget* qwidget() = 0;
};

} // namespace videoDisplay
} // namespace gr

#endif /* INCLUDED_VIDEODISPLAY_VIDEO_DISPLAY_H */
