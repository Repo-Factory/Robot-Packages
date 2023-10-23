# GUI Desktop Icon

Place GUI on Desktop for easy Access

## Description

This is a Linux Based .desktop file which points to GUI Program. This is more of a pain than you think it would be.... you're welcome.

## Getting Started

Copy this file to your /home/{usr}/Desktop directory. A new icon will be placed on your desktop that can run the GUI.

### Dependencies

* This relies on a few things being put into place before working. One, you need the actual gui executable to be built and available     from /usr/local/bin/robot/gui_exec. This means you have to build the gui_package on your machine with the CMake INSTALL Target pointing here (this CMake should already be done but be aware)

* You must also have a shell script called /usr/local/bin/scripts/launch_gui.sh on your machine. This is because the gui_exec has to link to librclcpp.so dynamic library which you have to source. Since you can't source before hand you can't run the executable directly. This means you need to have this icon point to a shell script which sources and runs /usr/local/bin/robot/gui_exec

## Authors

[@Strix Elixel](https://github.com/Repo-Factory/) Github
