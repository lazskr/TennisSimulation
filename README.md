# TENNIS SIMULATION 

# What is the project's purpose? 
Firstly, the Tennis Simulation enables for users to simulate singles Tennis Matches for any tournament (ATP or Grand Slam) for any professional players and allows them to perform experimental repetition to to acquire an overall average winner (**autonomous simulation**). The Tennis Simulation program also allows the users to simulate a match where it is a text-based statistics-driven game where the user "controls" 1 player and they must make choices throughout the game which will either hinder or increase their player's probability of wininng the match (**interactive simultation**). This project was written in C++. 

# How to execute and run the Tennis Simulation? 
Step 1: run "g++ -std=c++11 -O2 -Wall -o execute Main.cpp Menu.cpp Player.cpp Simulation.cpp autonomousSimulation.cpp interactiveSimulation.cpp" in the terminal 

Step 2: run "./execute" in the terminal to begin the program  

**NOTE:** For the autonomous simulation, please refer to https://www.atptour.com/en/players to get the statistic called total points won (which is represented as a percentage %) for each player as the autonomous simulation relies on this piece of information. 

# Motivation behind this project: 
This project was created to exemplify Objected Oriented Programming in C++. Specifically, the four pillars of Object-Oriented Programming can be identified within this project which are: Abstraction, Inheritance, Polymorphism and Encapsulation.

# What are the features of the Tennis Simulation? 
* Enables the user to run a real-life simulated Tennis Match in either an ATP or Grand slam match format for both men and women 
* Enables the user to run text-based Tennis video game simulation where they control a player and make key decisions for them (which will have an impact on the outcome of the match)

