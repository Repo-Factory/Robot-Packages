# Package Repository For SDSU Mechatronics Auxilary Code

A consolidated place for packages related to SDSU Mechatronics Robots

## Description

Here I am gathering a collection of packages that perform robotic functions.
I decided to do this as a feel the idea of a behemoth codebase is very hard to digest.
One of the keys to good software is solving problems without having to think of how that will fit into 
the other 1000 things that have to be done. In other words, decoupling your code.
That's why I think it's a good idea to think of things as standalone packages.
These packages will work whether they are on their own or inside a "codebase".
Of course they will have various dependencies but those will be clearly laid out in the READMEs. This also means
you're only dependent on a few libraries instead of being tied to every single other piece of code in the codebase.  

To make this work we need a library based system. All packages will have source code as well as a main function. The source code will be compiled into shared libraries (.so files) which can be linked to from anywhere. The main function will be compiled as a seperate executable that links to the library. It's okay if this doesn't make sense to you right now. But in C/C++ we generally use CMake to facilitate creating these libraries.

Once you have a library, as long as it's in a PATH the system recognizes (ie. bashrc), you can use it from anywhere and include the appropriate headers. These headers will be available at robot_libraries/  as I have set this as the default include location in all the CMakeLists.txt.  

These packages can also be used independent of other packages or languages. Python code can be ran alongside these packages because the package itself is self-contained (however, if you want to take advantage of convenient functions used constantly on the robot all the APIs/libraries I've written personally are in C++. You could make a wrapper if you want.)

## Directories ##

- `convenience/`- Houses scripts and some help with things like CMake and overall making development easier 
- `dependency/` - General code that will be used in various nodes (think math functions, not specific to a node)
- `robot/`      - These will have packages for different nodes on the robot   

## Getting Started

* Read around a bit to get a feel for the packages here. I'm working hard on keeping documentation up (I hate doing it). There may be mistakes in various places so please point them out. Download this repo and try to build some of the packages and execute them. Some important paths you need to setup to be visible on your computer are 

    /usr/local/lib
    /usr/local/bin/robot
    /usr/local/bin/robot_tests
    /usr/local/include/robot_libraries
    /usr/local/config

All these directories will be where your machine looks for libraries/headers/dependencies so you need to make sure your ~/.bashrc can see them  

### Dependencies

* Most packages will have some kind of dependency. All this means is you'll have to download another package it is dependent on and build it. This will place the library and a bunch of files in the directories listed above, giving you access to the dependency.

### Executing programs

To use any of these packages you obviously have to build them. This always kind of sucks for people. I would recommend taking advantage of the bash scripts in the convenience_packages. It will have some build shortcuts so you don't have to type all the CMake commands every time.

## Authors

[@Strix Elixel](https://github.com/Repo-Factory/) Github
