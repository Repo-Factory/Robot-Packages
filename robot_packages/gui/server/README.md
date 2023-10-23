# Robot GUI

User Interface to interact with Club Robot

## Description

GUI will have various pages for controlling the robot. It will also need an interface to talk to the robot and for the robot
to talk to it. The GUI will do this primarily by passing JSON strings between the robot process and GUI process. 

## Directories ##

- `gui_node/`                -      Actual Graphical Interface
- `talker/`                  -      Will Send JSON Strings to Robot when GUI buttons are clicked over ROS2
- `listener`                 -      Will Listen for JSON Strings constantly and perform appropriate callbacks

## Getting Started

The GUI Package has many dependencies which will be the hardest part about using it.
If you don't have QT on your machine, use these commands to get started 

    sudo apt-get install qt5-default
    sudo apt-get install qtcreator

### Dependencies

* Must link to core_dependencies library for types
* Must have Qt headers installed and linked correctly in the CMakeLists.txt

### Executing program

* Building will cause a gui_exec binary to be outputed to /usr/local/bin/robot

## Authors

[@Strix Elixel](https://github.com/Repo-Factory/) Github
