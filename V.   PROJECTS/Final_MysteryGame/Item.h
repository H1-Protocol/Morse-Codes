#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

// Base Class: Item
class Item {
protected:
    std::string name;
    std::string description;

public:
    Item(std::string n, std::string d) : name(n), description(d) {}
    virtual ~Item() {}

    // Polymorphism: Virtual function
    virtual void use() = 0;

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
};

// Inheritance: Clue class
class Clue : public Item {
public:
    Clue(std::string n, std::string d) : Item(n, d) {}

    void use() override {
        std::cout << "Clue: " << name << " - " << description << std::endl;
        std::cout << "This seems important for the investigation..." << std::endl;
    }
};

// Inheritance: Key class
class Key : public Item {
public:
    Key(std::string n, std::string d) : Item(n, d) {}

    void use() override {
        std::cout << "Key: " << name << " - " << description << std::endl;
        std::cout << "You can use this to unlock a specific door." << std::endl;
    }
};

#endif
