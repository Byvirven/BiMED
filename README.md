BiMED
=====

BiMED :This is an encoder/decoder for the Binary MPEG format for XML (BiM aka MPEG-B (ISO/IEC 23001))


Compile with pkg-config
=======================

export PKG_CONFIG_PATH=/usr/lib64/pkgconfig/:/usr/share/pkgconfig/:/usr/local/lib/pkgconfig/
export LD_LIBRARY_PATH=/usr/local/lib/

c++ -std=c++11 *.cpp -o demo-linux64 `pkg-config --libs --cflags gtkmm-3.0 gdkmm-3.0 xerces-c libMXF-1.0 libMXF++-1.0 bmx-0.1 ebu-mxfsdk-1.0` -W -Wall
