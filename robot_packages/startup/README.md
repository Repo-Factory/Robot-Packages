# Startup

Startup Procedures

## Description

Robot can be "turned on" in a couple different ways. One would be from hardware like a button. The second is from software,
either through terminal (lame) or GUI (much better)

## Getting Started

Robot startup is a grey concept because the robot is really kind of "on" at all times once the OS boots up. These packages are more entry points for the appropriate programs to be started, as these programs are what makes the robot appear to be on. Basically, orin has to be running at least one program (ie. has a main function) to be considered on... even then, that program could be hello world. The closest definition to on is "there's at least one program sending commands to the embedded system (CAN)". However, usually there are multiple processes, which is why we use ROS2 for IPC. The launch file in ROS2 is supposed to fork these processes for you, but I find you have very little control of your child processes this way. However, feel free to use the startup procedure you're comfortable with as it can be done in an infinite number of ways (tmux, launch, forking processes, button, ...). 

## Authors

[@Strix Elixel](https://github.com/Repo-Factory/) Github
