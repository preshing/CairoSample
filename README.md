A simple project to render an image to `spiral.png`. It's meant as an example of using [Cairo DLLs for Windows](https://github.com/preshing/cairo-windows). You can build it on Windows, MacOS or Linux.

![](http://preshing.com/images/cairo-spiral.png)

## Requirements

### Windows (Visual Studio)

CairoSample expects to find the Cairo header files, import libraries and DLLs in a subfolder named `extern\cairo-windows-1.15.12`. You can download and extract the package automatically by running the Python 3 script `setup-win32.py`. If you don't have Python installed, [download and extract the package by hand](https://github.com/preshing/cairo-windows/releases).

### MacOS (Xcode)

Install the Cairo headers and libraries using [MacPorts](https://www.macports.org/).

    sudo port install cairo
    
### Ubuntu

Install the Cairo headers and libraries.

    sudo apt install libcairo2-dev
    
## Build Instructions

For build instructions, see the blog post [How to Build a CMake-Based Project](http://preshing.com/20170511/how-to-build-a-cmake-based-project).
