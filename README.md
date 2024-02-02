![Static Badge](https://img.shields.io/badge/NumberShift-Game-blue)

# CONSOLE NUMBER SHIFT GAME

## DESCRIPTION 

This is a console number shift game implemented in C++. The game displays a square matrix with randomly placed numbers. The goal of the game is to arrange these randomly placed numbers in ascending order by shifting using **arrows** keys.

## How to play the game 

1. The game starts by displaying *rule of game* how to move numbers and others. 
2. Then it displays a square matrix with randomly placed numbers.
3. The player's task is to arrange these numbers in ascending order.


## Installation is very simple 
1. ### Microsoft Visual Studio IDE 
      Open the solution in the microsoft visual studio IDE and start making your own version of the game. 

2. ### Vsiual studio code 
      1. Prepend **../Header/** path in the relative include path in every *.cpp* file already mentioned
      For example 
      *#include "matrix.hpp"* change this to #include "../Header/matrix.cpp"  
      Do the same with every cpp file
      2. Navigate to **source** directory of the project in the integrated terminal  
      and Execute the following command to compile and run .exe file  
       1. To compile and generate exe file  
           ``` 
             g++ --std=c++14 -o  ..\..\Executable\MatrixNumberShift  .\GameUtility.cpp .\main.cpp matrix.cpp .\matrix1.cpp
            ``` 
            The above command will create an exe file in the Executable directory and by double clicking it you can run your game. 

## Usage 
To start playing the game, Go to the *Executable* folder and open *exe* file by double clicking on it. 


## Contribution 
Sure, here’s a template for a contribution section you can add to your README:

## Contributing

I welcome contributions to the Number Shift Game! Here's how you can help:

1. **Fork the Repository**: Start by forking the Number Shift Game repository.

2. **Clone the Repository**: After forking, clone the repository to your local machine. You can do this with the command: `git clone https://github.com/Prashant-Kumar-321/ConsoleNumberShiftGame`.

3. **Create a New Branch**: Create a new branch for the changes you want to make. You can create a new branch with: `git checkout -b New-branch-name`.

4. **Make Your Changes**: Make the changes you want to contribute. This could be adding a new feature, fixing bugs, or improving documentation.

5. **Commit Your Changes**: After making your changes, commit them with a meaningful commit message.

6. **Push to GitHub**: Push your changes to the forked repository on GitHub.

7. **Submit a Pull Request**: Finally, submit a pull request from your forked repository to our repository. I'll review your contribution and, if everything looks good, merge it!


## LICENCE
This project is licensed under the [MIT License](https://opensource.org/license/mit/).

Feel free to adjust the content and structure based on your preferences and project specifics.
