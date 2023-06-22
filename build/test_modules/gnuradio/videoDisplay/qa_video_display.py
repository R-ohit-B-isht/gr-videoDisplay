#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2023 gr-videoDisplay author.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from gnuradio import gr, gr_unittest
from PyQt5 import Qt
import sip

# from gnuradio import blocks
try:
  from gnuradio.videoDisplay import video_display
except ImportError:
    import os
    import sys
    dirname, filename = os.path.split(os.path.abspath(__file__))
    sys.path.append(os.path.join(dirname, "bindings"))
    from gnuradio.videoDisplay import video_display

class qa_video_display(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_instance(self):
        itemsize = gr.sizeof_int  
        parent = None 
        instance = video_display(itemsize ,parent)
        b = sip.wrapinstance(instance.qwidget(),Qt.QWidget)

    def test_001_descriptive_test_name(self):
        # set up fg
        self.tb.run()
        # check data


if __name__ == '__main__':
    gr_unittest.run(qa_video_display)
