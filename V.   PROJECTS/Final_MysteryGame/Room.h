#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <map>
#include "Item.h"

class Room {
private:
    std::string name;
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item*> items; // Composition: Room has items

public:
    Room(std::string n, std::string d) : name(n), description(d) {}

    void addExit(std::string direction, Room* neighbor) {
        exits[direction] = neighbor;
    }

    void addItem(Item* item) {
        items.push_back(item);
    }

    Item* removeItem(std::string itemName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == itemName) {
                Item* found = *it;
                items.erase(it);
                return found;
            }
        }
        return nullptr;
    }

    void displayInfo() const {
        std::cout << "\n--- " << name << " ---\n";
        std::cout << description << "\n";
        
        if (!items.empty()) {
            std::cout << "Items here: ";
            for (const auto& item : items) {
                std::cout << "[" << item->getName() << "] ";
            }
            std::cout << "\n";
        }

        std::cout << "Exits: ";
        for (const auto& exit : exits) {
            std::cout << exit.first << " ";
        }
        std::cout << "\n";
    }

    Room* getExit(std::string direction) {
        if (exits.find(direction) != exits.end()) {
            return exits[direction];
        }
        return nullptr;
    }

    std::string getName() const { return name; }
};

#endif
