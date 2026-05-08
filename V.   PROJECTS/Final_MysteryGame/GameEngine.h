#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Room.h"
#include "Player.h"

class GameEngine {
private:
    Player* player;
    std::vector<Room*> rooms;
    bool isRunning;

    // Static member: tracks how many games have been started in this session
    static int sessionGameCount;

public:
    GameEngine() : player(nullptr), isRunning(true) {
        sessionGameCount++;
        setupRooms();
    }

    ~GameEngine() {
        delete player;
        for (auto room : rooms) delete room;
    }

    static int getSessionGameCount() { return sessionGameCount; }

    void setupRooms() {
        Room* hall = new Room("Hallway", "A long, dimly lit hallway with dusty portraits.");
        Room* study = new Room("Study", "A room filled with books and a mahogany desk.");
        Room* kitchen = new Room("Kitchen", "Smells of old herbs. A rusty knife lies on the counter.");
        Room* cellar = new Room("Cellar", "It's cold and damp down here.");

        hall->addExit("north", study);
        hall->addExit("east", kitchen);
        study->addExit("south", hall);
        kitchen->addExit("west", hall);
        kitchen->addExit("down", cellar);
        cellar->addExit("up", kitchen);

        study->addItem(new Clue("Letter", "A letter mentioning a hidden treasure in the cellar."));
        kitchen->addItem(new Key("IronKey", "A heavy iron key."));
        cellar->addItem(new Clue("Note", "The note says: 'The butler did it.'"));

        rooms.push_back(hall);
        rooms.push_back(study);
        rooms.push_back(kitchen);
        rooms.push_back(cellar);

        player = new Player("Detective", hall);
    }

    // File Handling: Save game state
    void saveGame() {
        std::ofstream outFile("save.txt");
        if (outFile.is_open()) {
            outFile << player->getName() << "\n";
            outFile << player->getCurrentRoom()->getName() << "\n";
            outFile.close();
            std::cout << "Game saved successfully!\n";
        } else {
            std::cerr << "Unable to open file for saving.\n";
        }
    }

    void run() {
        std::cout << "Welcome to 'The Whispering Manor'!\n";
        std::cout << "Goal: Find all 3 pieces of evidence to solve the mystery!\n";
        std::cout << "Session Games Started: " << sessionGameCount << "\n";

        while (isRunning) {
            player->getCurrentRoom()->displayInfo();
            std::cout << "\nWhat do you want to do? (move <dir>, take <item>, use <item>, inventory, save, quit): ";
            
            std::string command;
            std::cin >> command;

            if (command == "quit") {
                isRunning = false;
            } else if (command == "move") {
                std::string dir;
                std::cin >> dir;
                player->move(dir);
            } else if (command == "take") {
                std::string item;
                std::cin >> item;
                player->takeItem(item);
                checkWinCondition();
            } else if (command == "use") {
                std::string itemName;
                std::cin >> itemName;
                useItem(itemName);
            } else if (command == "inventory") {
                player->showInventory();
            } else if (command == "save") {
                saveGame();
            } else {
                std::cout << "Invalid command.\n";
            }
        }
    }

    void useItem(std::string itemName) {
        for (auto item : player->getInventory()) {
            if (item->getName() == itemName) {
                item->use();
                return;
            }
        }
        std::cout << "You don't have that item.\n";
    }

    void checkWinCondition() {
        if (player->getInventory().size() == 3) {
            std::cout << "\n****************************************\n";
            std::cout << "CONGRATULATIONS! You found all evidence!\n";
            std::cout << "The mystery of the Whispering Manor is solved.\n";
            std::cout << "****************************************\n";
            isRunning = false;
        }
    }
};

// Initialize static member
int GameEngine::sessionGameCount = 0;

#endif
