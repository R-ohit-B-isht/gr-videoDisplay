#!/usr/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay
export GR_CONF_CONTROLPORT_ON=False
export PATH="/home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay":"$PATH"
export LD_LIBRARY_PATH="":$LD_LIBRARY_PATH
export PYTHONPATH=/home/rohit/Videos/video/gr/gr-videoDisplay/build/test_modules:$PYTHONPATH
/home/rohit/radioconda/bin/python /home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay/qa_video_display.py 
