/*
 * =============================================
 *    CAR AUCTION HOUSE — C++ OOP Project
 * =============================================
 *  Concepts:
 *  1. Class
 *  2. Static
 *  3. Inheritance
 *  4. Composition
 *  5. Polymorphism
 *  6. File Handling
 *  7. Exception Handling
 * =============================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    int    year;
    double price;

    static int totalCars;   // counts every car listed

public:
    Car(string b, string m, int y, double p)
        : brand(b), model(m), year(y), price(p) {
        totalCars++;
    }

    static int getTotalCars() { return totalCars; }

    string getName()  const { return brand + " " + model; }
    double getPrice() const { return price; }

    // POLYMORPHISM
    virtual void display() const {
        cout << year << " " << brand << " " << model
             << " | $" << price << endl;
    }

    virtual string getType() const = 0;

    virtual ~Car() { totalCars--; }
};
int Car::totalCars = 0;



// INHERITANCE
class ClassicCar : public Car {
public:
    ClassicCar(string b, string m, int y, double p)
        : Car(b, m, y, p) {}

    string getType() const override { return "Classic"; }

    void display() const override {
        cout << "[CLASSIC] ";
        Car::display();
    }
};

class ModifiedCar : public Car {
    string modification; // e.g. "Turbo Kit", "Wide Body"
public:
    ModifiedCar(string b, string m, int y, double p, string mod)
        : Car(b, m, y, p), modification(mod) {}

    string getType() const override { return "Modified"; }

    void display() const override {
        cout << "[MODIFIED] ";
        Car::display();
        cout << "   Mod: " << modification << endl;
    }
};


// COMPOSITION — Auction HAS Cars + Bidders
class Bidder {
    string name;
    double budget;
public:
    Bidder(string n, double b) : name(n), budget(b) {}
    string getName()   const { return name; }
    double getBudget() const { return budget; }
};

class Auction {
    string        houseName;
    vector<Car*>  lots;      // Auction HAS cars
    vector<Bidder> bidders;  // Auction HAS bidders

public:
    Auction(string name) : houseName(name) {}

    void addCar(Car* c) {
        // EXCEPTION HANDLING
        if (lots.size() >= 6)
            throw runtime_error("Auction is full! Max 6 lots.");
        lots.push_back(c);
    }

    void addBidder(Bidder b) { bidders.push_back(b); }

    void showLots() const {
        cout << "\n=== " << houseName << " — Auction Lots ===" << endl;
        for (Car* c : lots)
            c->display();   // Polymorphism: calls correct display()
        cout << "Total cars listed: " << Car::getTotalCars() << endl;
    }

    void showBidders() const {
        cout << "\n=== Registered Bidders ===" << endl;
        for (const Bidder& b : bidders)
            cout << b.getName() << " | Budget: $" << b.getBudget() << endl;
    }

    // FILE HANDLING
    void saveToFile(string filename) const {
        ofstream file(filename);
        if (!file.is_open())
            throw runtime_error("Could not open file!");

        file << houseName << endl;
        for (Car* c : lots)
            file << c->getType() << " | " << c->getName()
                 << " | $" << c->getPrice() << endl;

        file.close();
        cout << "\nSaved auction listings to " << filename << endl;
    }

    ~Auction() {
        for (Car* c : lots) delete c;
    }
};


int main() {

    Auction house("Zakki's Auto Auction");

    // Add cars (mix of Classic and Modified)
    house.addCar(new ClassicCar("BMW",     "E36 Coupe", 1997, 18000));
    house.addCar(new ClassicCar("Porsche", "911 Turbo",   1996, 62000));
    house.addCar(new ModifiedCar("Toyota", "Supra MK4", 1994, 95000, "Single Turbo"));
    house.addCar(new ModifiedCar("Nissan", "Skyline R34",1999, 120000,"RB26 Swap"));

    // Add bidders (Composition: Auction HAS Bidders)
    house.addBidder(Bidder("Zakki",  25000));
    house.addBidder(Bidder("Afaq",  130000));
    house.addBidder(Bidder("Saad",   70000));

    // Show everything
    house.showLots();
    house.showBidders();


    // File Handling
    house.saveToFile("auction.txt");

    // Exception Handling demo
    try {
        house.addCar(new ClassicCar("Honda",   "NSX",      1991, 85000));
        house.addCar(new ClassicCar("Mazda",   "RX-7 FD",  1995, 45000));
        house.addCar(new ClassicCar("Ferrari", "348",      1993, 75000)); // triggers exception
    } catch (runtime_error& e) {
        cout << "\nException: " << e.what() << endl;
    }

    return 0;
}
