# Mix-in

A mix-in is a class that implements properties for another class. It
often doesn't even have a (public) constructor.  These properties are
cross-cutting in the sense that they are shared by potentially many
other classes.

## What is it?

1. `point.h`: definition of a point in two dimensions.
1. `color.h`: definition of a mix-in for a color property.
1. `pixel.h`: defintion of a pixel, i.e., a point with
   associated color.
1. `paint.h`: definition of paint, which shares only its
   color property with a pixel.
1. `main.cpp`: main function for the application.
1. `CMakeLists.txt`: CMake file to build the application(s).
