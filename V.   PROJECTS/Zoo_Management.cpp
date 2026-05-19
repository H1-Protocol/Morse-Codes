#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

// Base class
class Animal {
protected:
    string name;
    string type;
    int age;

    static int count;

public:
    Animal(string n, string t, int a) {  // Parameterized constructor
        name = n;
        type = t;
        age = a;
        count++;
    }

    virtual void speak() {
        cout << name << " makes a sound." << endl; // Virtual function for polymorphism
    }

    void display() {
        cout << "Name: " << name
             << " || Type: " << type
             << " || Age: " << age << endl<< endl;
    }

    string getName() { // Getter function
        return name;
    }

    static int getCount() {
        return count;
    }

    virtual ~Animal() { // Destructor
        count--;
    }
};

int Animal::count = 0;


// Child class 1
class Lion : public Animal {
public:
    Lion(string n, int a) : Animal(n, "Lion", a) {}

    void speak() override {
        cout << name << " says: ROAR!" << endl<<"======================================" << endl;
    }
};


// Child class 2
class Parrot : public Animal {
public:
    Parrot(string n, int a) : Animal(n, "Parrot", a) {}

    void speak() override {
        cout << name << " says: SQUAWK!" << endl<<"======================================" << endl;
    }
};


// Child class 3
class Elephant : public Animal {
public:
    Elephant(string n, int a) : Animal(n, "Elephant", a) {}

    void speak() override {
        cout << name << " says: TRUMPET!" << endl <<"======================================" << endl;
    }
};


// Zoo class
class Zoo {
private:
    string zooName;
    vector<Animal*> animals;

public:
    Zoo(string name) {
        zooName = name;
    }

    void addAnimal(Animal* animal) {
        if (animals.size() >= 8) {
            throw runtime_error("The cages are full! Monkeys are going krazy.");
        }

        animals.push_back(animal);
    }

    void showAnimals() {
        cout << "\n========================================" << endl;
        cout << "          " << zooName << " Database" << endl;
        cout << "========================================" << endl;

        int number = 1;

        for (Animal* animal : animals) {
            cout << "\nAnimal #" << number << endl;
            cout << "----------------------------------------" << endl;
            animal->display();
            animal->speak();
            number++;
        }

        cout << "\n========================================" << endl;
        cout << "Total Animals in Zoo: " << animals.size() << endl;
        cout << "Total Animal Objects Created: " << Animal::getCount() << endl;
        cout << "========================================" << endl;
    }

    void saveToFile() { // File Handling
        ofstream file("Zoo.txt");

        if (!file) {
            throw runtime_error("File could not be opened.");
        }

        file << zooName << endl;

        for (Animal* animal : animals) {
            file << animal->getName() << endl;
        }

        file.close();

        cout << "\n[Saved] Zoo database has been transferred to Zoo.txt" << endl;
    }

    ~Zoo() {
        for (Animal* animal : animals) {
            delete animal;
        }
    }
};


int main() {
    try {
        Zoo zoo("Peshawar Zoo");

        zoo.addAnimal(new Lion("Simba boi", 27));
        zoo.addAnimal(new Parrot("Bluey", 2));
        zoo.addAnimal(new Parrot("Captain Flint", 75));
        zoo.addAnimal(new Elephant("Sherman Jumbo", 43));


        zoo.showAnimals();

        zoo.saveToFile();

        // This line shows exception handling because the zoo already has 8 animals.
        zoo.addAnimal(new Lion("Extra Boi", 4));
    }
    catch (runtime_error& error) {
        cout << "\n========================================" << endl;
        cout << "              SYSTEM ERROR" << endl;
        cout << "========================================" << endl;
        cout << "Message: Chimps have overridden the database!" << endl;
        cout << "Reason: " << error.what() << endl;
        cout << "========================================" << endl;
    }

    return 0;
}