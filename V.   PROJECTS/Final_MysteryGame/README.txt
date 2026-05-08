The Whispering Manor - C++ Mystery Game
========================================

University Finals Project - Semester 2
Student: zakki

Required Concepts Implemented:
------------------------------
1. Class: Implemented in every header file (Item, Room, Player, GameEngine).
2. Static: Used GameEngine::sessionGameCount to track games started in a session.
3. Inheritance: Clue and Key classes inherit from the abstract Item class.
4. Composition: 
   - Room contains a vector of Item* pointers.
   - Player contains a vector of Item* pointers (inventory).
   - GameEngine contains pointers to Room and Player objects.
5. Polymorphism: Used virtual void use() in Item class, overridden in Clue and Key.
6. Operator Overloading: Overloaded operator+ in the Player class to add items to inventory.
7. File Handling: saveGame() writes the player's name and current room to 'save.txt'.

How to Compile and Run:
-----------------------
Compile: g++ -o mystery_game.exe main.cpp
Run: ./mystery_game.exe

Game Controls:
--------------
- move <direction> (e.g., move north)
- take <item> (e.g., take Letter)
- use <item> (e.g., use Letter)
- inventory (show items)
- save (save progress)
- quit (exit game)
