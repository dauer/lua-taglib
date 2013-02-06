lua-taglib
==========

Lua library for reading metadata from audio files

The library uses the TagLib (http://taglib.github.com/) C++ library.
Not all TagLib funtionality has been implemented, you can only read metadata not write etc. etc.

lua-taglib is very early in development, expect errors!

## Requirements ##
* lua5.2
* liblua5.2-0-dev
* TagLib

## Documentation ##
Build the library using the Makefile in the ./src folder.

Then have a look at the 'example.lua' file to see how to use the library.

## TODO ##

Add Lua support for more of the TagLib library functions

More testing...
I have only testet the library with using a single mp3 file on my Ubuntu 12.10 Linux...
