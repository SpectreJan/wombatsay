# wombatsay
Wombatsay is a small little nonsense program that draws heavy inspiration from the popular [cowsay] (https://en.wikipedia.org/wiki/Cowsay) program.

## Installing
### Prerequisites
If you want to build it for yourself, you will either need the compiler of your choice, Make and CMake.
### Building
I haven't gotten around to writing an install script yet. So probably the best way is to git clone the repo
```
git clone https://github.com/SpectreJan/wombatsay.git
```

Create a build directory, configure cmake and then build it using make. The binary/exe wombatsay will be in build/src

```
mkdir build
cd build
cmake ../
make
```
### Installing
Since I have not gotten around to write an install script. So just take the binary/exe you build, and copy it to the location of your choice. Don't forget to put the location of the bin/exe into your PATH environment variable.
As a windows user you can just click on the exe and enjoy the wombat glory.

## Using
On Windows you can just click the exe, on Linux if the bin is in your PATH you can just type wombatsay in your terminal.
Wombatsay either accepts cmdline arguments or you can type the sentence after starting the program.

```
wombatsay
What does the wombat say?
I am a wombat
  _______________
 < I am a wombat >
  ---------------
     \
      \  /\___/\
        /       \--------\
        ()  ()            \
      / __                 \
     |  ||        >         |
     <  --    __ >          |oo
      < -----/|      ____   |oo
        /_____|-----/______ |

```
