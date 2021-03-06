[![Build Status](https://semaphoreci.com/api/v1/jpcima/freemajor/branches/master/badge.svg)](https://semaphoreci.com/jpcima/freemajor)

[:floppy_disk: Automatic development build for Windows](http://jpcima.sdf1.org/software/development/FreeMajor/FreeMajor-dev-win32.zip)  
[:floppy_disk: Automatic development build for Mac OS](http://jpcima.sdf1.org/software/development/FreeMajor/FreeMajor-dev-mac.zip) (requires [libcxx](https://trac.macports.org/wiki/LibcxxOnOlderSystems) from MacPorts on macOS 10.8 or earlier)

### Useful links

- [G-Major manual :us: :jp: :it: :de: :es: :fr:](https://www.tcelectronic.com/Categories/Tcelectronic/Guitar/Effects-Processors/G-MAJOR/p/HE066/Downloads)
- [Linux MAO :fr:](http://linuxmao.org/FreeMajor)
- [LibraZiK-2 :fr:](http://librazik.tuxfamily.org/doc2/logiciels/freemajor)

### Dependencies
FreeMajor is mostly tested on [LibraZiK-2](http://librazik.tuxfamily.org/), a Debian Stretch based OS.
The build dependencies on this OS are:
```
cmake
build-essential
libasound2-dev
libjack-jackd2-dev
libfltk1.3-dev
gettext
```
Note that you might need to install `git` as well to fetch the sources.

### First compilation

```
git clone --recursive https://github.com/linuxmao-org/FreeMajor.git
mkdir FreeMajor/build
cd FreeMajor/build
cmake ..
cmake --build .
cd ..
./build/FreeMajor
```
### Build after some modifications

```
cd FreeMajor
git pull
cmake --build build
./build/FreeMajor
```
