#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"

class Player {
private:
    std::string name;
    std::vector<Item*> inventory;
    Room* currentRoom;

public:
    Player(std::string n, Room* startRoom) : name(n), currentRoom(startRoom) {}

    void move(std::string direction) {
        Room* nextRoom = currentRoom->getExit(direction);
        if (nextRoom) {
            currentRoom = nextRoom;
            std::cout << "You move to the " << direction << ".\n";
        } else {
            std::cout << "You can't go that way.\n";
        }
    }

    void takeItem(std::string itemName) {
        Item* item = currentRoom->removeItem(itemName);
        if (item) {
            *this + item; // Using overloaded + operator
            std::cout << "You picked up the " << itemName << ".\n";
        } else {
            std::cout << "There is no " << itemName << " here.\n";
        }
    }

    // Operator Overloading: Use + to add an item to inventory (demonstrative)
    void operator+(Item* item) {
        if (item) {
            inventory.push_back(item);
        }
    }

    void showInventory() const {
        std::cout << "\nInventory: ";
        if (inventory.empty()) {
            std::cout << "Empty\n";
        } else {
            for (const auto& item : inventory) {
                std::cout << "[" << item->getName() << "] ";
            }
            std::cout << "\n";
        }
    }

    Room* getCurrentRoom() const { return currentRoom; }
    std::string getName() const { return name; }
    const std::vector<Item*>& getInventory() const { return inventory; }
};

#endif
