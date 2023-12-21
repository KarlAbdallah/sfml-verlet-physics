# sfml-verlet-physics
sfml-verlet-physics is a C++ library that implements game engine physics using Verlet Integration and draws the resulting output using SFML.

This is <ins>not</ins> a fully featured engine, but rather a personnal challenge to create a physics engine with working collisions from scratch.

# Example #
Click to watch
[![Video](https://img.youtube.com/vi/vh5EXcA9_PU/maxresdefault.jpg)](https://youtu.be/vh5EXcA9_PU)

# Pre-requisites 
This code requires the use of g++ v13.1.0 and SFML v2.6.0. More recent versions of those libraries should be compatible, but were not tested. This code also makes uses the C++ Standard CPP23 (previous versions should be compatible but again, weren't tested).

Both g++ and SFML will need to be added to PATH.

# Compiling #
## Using VS Code ##
To compile and run using VS Code, open the entire project in VS Code and press the 'Run C\C++ File' button inside the 'src\main.cpp' file (make sure to have the C\C++ extension installed on VS Code).

## Using cmd ##
* Navigate to the project directory,
* Enter to compile: 
```
g++ -I<SFML-PATH>\include -L<SFML-PATH>\lib -g src\main.cpp src\event.cpp src\object.cpp src\render.cpp src\solver.cpp -o build\sfml-verlet-physics.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main
```
with \<SFML-PATH> being the path to your SFML library (e.g.: C:\SFML-2.6.0).
* Enter to run:
```
.\build\sfml-verlet-physics.exe
```

# Usage #
* Use the arrows on your keyboard (Up, Down, Right, Left) to provide initial velocity to the objects.
* Use PageUp and PageDown to alter the mass of an object.
* Left click creates an object with the displayed parameters on screen.
* Escape exits the app.
