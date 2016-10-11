***
PLEASE TYPE gcc -o a.out -lpthread godrone.c  TO CREATE EXECUTABLE AND
./a.out 
TO COMPILE/RUN!!
***



I have one necessary file in order to create the drone simulation. 

This file is godrone.c . 


In this file, there is a createDrone method, and a main method.

The createdrone is a void pointer which runs a simple switch statement, to 
represent drones and their flight, and exit the pthread.

The main method uses threading to create instances of the createDrone method, 
and then creates a collision system for these drones.

The number of drones created is manipulated by the variable NUM_THREADS . 


