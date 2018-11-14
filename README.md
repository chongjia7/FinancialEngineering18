# FinancialEngineering18
Master of Financial Engineering from Baruch College, City University of New York 

This repository contains final projects of Financial Engineering course with great emphasis place on options pricing ( European & American )with various methods such as Black-Scholes, Monte Carlo and Finite-Difference-Method. Additional libraries include Boost C++ & home-made UtilitiesDJD provided by the course. Most of these projects are created on CLion compiler (C++ 98), and should work fine on VS compiler too. 

Feedback from the course:

Groups A&B: Very good, this is essentially the code structure I am looking for here.
In regards to the matrix functionality, the point is to be able to have a generic matrix of option parameters and price a vector of options. The best way to achieve this (within what was learned in this course) would be to:
Create a Matrix class for parameters.
Create an interface (or multiple interfaces) to generate the parameter matrices. i.e., one interface can be from console, another hardcoded, another from a file, another random numbers, another a Mesh, etc.
The OptionMatrixPricer can have a generic pricing method that takes a reference to your Option base class as its parameter. It would then invoke the virtual .Price() method for each option in the matrix, and return a vector.

Groups C-D: Very good.

Groups E-F: Very good

I have also attached some useful design patterns, data structures and algorithms for future references. To note, one can always use multithreading to achieve such effect for more efficient Monte Carlo pricing if you're fed up of waiting too long for the simulations. 

Commentary: 
A good continuation for option trading strategies (not covered 
in this course) can be extended to Machine Learning and Reinforcement Learning 
in Finance, offered by NYU Tandon School of engineering. 

