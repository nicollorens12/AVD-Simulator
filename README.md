# AVD-Simulator
This is a simulator of how a drone with an ADV system could locate potential victims of and avalanche. The program consists of a fixed value matrix simulating
an area of a mountain. The execution works this way: a Sector of a mountain is generated (Matrix with all '+' characters) then a random avalanche is created; 
avalanche affected points are simulated as '|' characters. Then it's decided randomly if an avalanche has victims or not. If it does, a maximum of 4 victims will 
be placed randomly on different points of a matrix.

Future implementation will simulate the drone process of searching possible victims.

## How to compile

Before compiling the project for the first time it is necessary must execute
`make init`, so that all the appropiate folders are created. After that, to compile the
project just run the command `make` on the root directory of the project.
This will generate an executable file on the *bin* folder.

This program doesn't need any parameters.
