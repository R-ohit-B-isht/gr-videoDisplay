# CMake generated Testfile for 
# Source directory: /home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay
# Build directory: /home/rohit/Videos/video/gr/gr-videoDisplay/build/python/videoDisplay
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(qa_video_display "/usr/bin/sh" "qa_video_display_test.sh")
set_tests_properties(qa_video_display PROPERTIES  _BACKTRACE_TRIPLES "/home/rohit/radioconda/lib/cmake/gnuradio/GrTest.cmake;119;add_test;/home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay/CMakeLists.txt;42;GR_ADD_TEST;/home/rohit/Videos/video/gr/gr-videoDisplay/python/videoDisplay/CMakeLists.txt;0;")
subdirs("bindings")
