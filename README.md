# About

I did this simple project to familiarise myself with Unreal's API for AI and the use of C++ in Unreal.

NPCs move around the map to get spheres, and when they have one they go looking for the player. 
Once they have seen him they go towards him to leave the ball and come back for another one. 
When there are no more spheres they wait for them to be respawned


## State Machine

A bit tricky part was to create the state machine for the NPCs.

I created a structure representing a state, which has 3 functions that are called at the beginning, at the end and during the execution of the state.

The Actor Update will call the state Update method 





## AI components

It was quite difficult to figure out how to make unreal AI components work                     

































