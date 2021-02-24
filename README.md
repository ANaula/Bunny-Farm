# Bunny Farm Simulation

## Purpose

This c++ program was made to simulate a bunny farm over an 11 year timespan. It displays information for each bunny in the farm, notifies you when a bunny is born or has died, and shows the pen represented by a grid and where the bunnies are in that grid. The information is recorded in a text file and outputted.

## How it works

The program revolves around the bunny class and a linked list that holds all the bunny objects in the simulation. The bunny class holds information such as their gender, fur color, name, age, mortality status, grid mark icon, grid lcation, and if they are a mutant. A for loop is used to represent the progressing years and each year the linked list is traversed to either add, remove, or modify bunny information. These actions are done by four functions: **cull_check()**, **bunny_ai()**, **logic()**, and **draw()**.

**cull_check()** deletes half of the population randomly either when the total bunny population is greater than 50 or when prompted to by the user. Once a cull begins the user will be notified of which bunnies where deleted.

**bunny_ai()** has two purposes. Once the simulation begins, it places the first five bunnies in random locations on the grid. After that it move each bunny 1 time randomly each year depending on if there is space to move.

**logic()** has three purposes. It checks the ages of each bunny and deletes non-mutant bunnies older than 5 years and mutant bunnies older than 10. It ages the bunnies by one each year and creates new bunnies depending on if there are male and female non-mutant bunnies older than 2 years old. New bunnies are placed next to their mothers and carry over the same fur-color. However if there is no space around the mother the bunny is deleted. New bunnies have a 10% chance of being a mutant. It notifies the user if bunnies have been deleted or have been created as well as how many non-mutant males and females there are, the estimated number of new bunnies there are supposed to be, the number of bunnies actually created and the number of bunnies that had to be deleted due to no space..

**draw()** displays the year, information on each bunny, total bunny population, and the grid and where the bunnies are located in it. Bunnies under the age of two will be have lowercase letters with "f" meaning female, "m" meaning male, and "x" meaning mutant bunny. Once they are over the age of two these letters are in uppercase.

The user will have a choice to manually cull the population by pressing k. The program will not wait for this input so if the user does not want to cull, they just don't have to press k. Below is an example of the program in action.

![Alt Text](https://media.giphy.com/media/jKUcuGes2M9HDhjESq/giphy.gif)

As mentioned earlier, the program records all of this in a text file. In the repository, the text file "Bunny_Farm.txt" is an example of what this program outputs.

## To Build

A CMakeLists.txt file is provided in the repository for construction using CMake.
