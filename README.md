## C++ MazeGenerator

####Disclaimer:
**This is my first time trying writing C++ program it could contain badly written c++ code** 

This work under linux it's uses ncurses library to show the generated maze.
It's uses a recursive backtracker technique to generate the corridors and other algorithms to create rooms and room entrances.

### How to use
Simple call the executable it will generate a 50x50 random maze, if you want to specify the size of the maze you can call the executable with 2 parameters the first one is the **width** a second is the **height** of the maze.

After generation, you will get a seed, if you use that seed as a third parameter you get the same maze again, or you can write your own seed.