# CPPND: Capstone project: Seasnake game (modified snake game)

This project is based on a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for that repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

Food in the starter code has been replaced with moving frogs that are inherited from a common based class with the snake. Objective of the game is to guide the snake using arrow keys and eat all the frogs while avoiding collision with the tail of the snake.

This project is not a complete game and definitely not optimized in many ways, but instead the goal has been to utilize and demonstrate some of the topics learned throughout the program.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo
2. Compile: `cmake . && make`
3. Run it: `./SeaSnakeGame`

## Code structure

The Seasnake game consists of six main classes: 1. Game, 2. Chordate, 3. Frog, 4. Snake, 5. Controller and 6. Renderer. 

Main function creates:
* Controller for snake movement control
* Renderer for drawing the snake and frogs on the screen
* Game for running the main game loop

Game object stores a Snake object and vector of Frog objects as part of the state.

Chordate is a common base class for Snake and Frog classes.

## File structure

**main.cpp**

This is the entrypoint for the program. Sets variables such as window size, and creates Renderer, Controller and Game objects, and calls the Game::Run method to start the game loop.

**chordate.h and chordate.cpp**

These files define the Chordate base class which contains common members for both Frog and Snake classes. 

**controller.h and controller.cpp**

These files define the Controller class which handles keyboard input using SLD library and sets the snake's direction based on the input.

**frog.h and frog.cpp**

These files define the Frog class that inherits the Chordate class and defines Frog-specific members.

**game.h and game.cpp**

These files define the Game class and the game loop.

**random_generator.h and random_generator.cpp**

Global random number generator developed by Bjarne Stroustrup.

**renderer.h and renderer.cpp**

These files define the Renderer class which uses the SDL library to render the game to the screen. The Renderer::Render method draws the frogs and the snake in the window using the SDL renderer.

**snake.h and snake.cpp**

These files define the Snake class that inherits the Chordate class and defines Snake-specific members.


## Rubric points implemented in this project

1.  The project accepts user input and processes the input
    * Number of frogs, in effect difficulty level, is queried from the user (main.cpp line 17 )
1.  The project uses Object Oriented Programming techniques
    * Both main elements of the game, snake (snake.h/snake.cpp) and frogs (frogs.h/frogs.cpp), are objects
1.  Classes use appropriate access specifiers for class members
    * Chordate (chordate.h), Frog (frog.h) and Snake (snake.h) classes define members private whenever possible. Members are made public only when necessary.
1.  Classes encapsulate behavior
    * Frog-specific movement is defined as a method of Frog class (frog.cpp line 16 )

1.  Classes follow and appropriate inheritance hierarchy
    * Snake (snake.h) and Frog (frog.h) classes both inherit from common Chordate (chordate.h) class and define only creature-specific members
1.  The project uses scope / Resource Aquisition is initialization (RAII) where appropriate
    * Frogs are created using make_unique (game.cpp line 59), stored in a vector and dead frogs are removed with erase-method (game.cpp line 97)
1.  The project uses smart pointers instead of raw pointers
    * Frogs are accessed using unique_ptr (game.h line 23)
