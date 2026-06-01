#include <iostream>
#include <fstream>
using namespace std;

class Car {
protected:
    string make, model;
    int year;
    double price;

    static int totalCars;

public:
    Car(string b, string m, int y, double p):make(b), model(m), year(y), price(p) {
        totalCars++;
    }

    static int getTotalCars() {
        return totalCars;
    }

    string getName() const {
        return make + " " + model;
    }

    double getPrice() const {
        return price;
    }

    virtual void display() const {
        cout << year << " " << make << " " << model << " | $" << price << endl;
    }

    virtual string getType() const = 0;

    virtual ~Car() {
        totalCars--;
    }
};

int Car::totalCars = 0;
class ClassicCar : public Car {
public:
    ClassicCar(string b, string m, int y, double p) : Car(b, m, y, p) {}

    string getType() const {
        return "Classic";
    }

    void display() const {
        cout << " [CLASSIC] ";
        Car::display();
    }
};


class ModifiedCar : public Car {
    string modification;

public:
    ModifiedCar(string b, string m, int y, double p, string mod) : Car(b, m, y, p) {
        modification = mod;
    }

    string getType() const {
        return "Modified";
    }

    void display() const {
        cout << "[MODIFIED] ";
        Car::display();
        cout << "   Mod done: " << modification << endl;
    }
};
class Bidder {
    string name;
    double budget;

public:
    Bidder() {
        name = "";
        budget = 0;
    }

    Bidder(string n, double b) : name(n), budget(b){}

    string getName() const {
        return name;
    }

    double getBudget() const {
        return budget;
    }
};
class Auction {
    string houseName;

    Car* lots[6];
    int carCount;

    Bidder bidders[10];
    int bidderCount;

public:
    Auction(string name):houseName(name), carCount(0), bidderCount(0){}

    void addCar(Car* c) {
        if (carCount >= 6) {
            throw "Auction is full! Max 6 lots.";
        }

        lots[carCount] = c;
        carCount++;
    }

    void addBidder(Bidder b) {
        bidders[bidderCount] = b;
        bidderCount++;
    }

    void showLots() const {
        cout << "\n========= " << houseName << " - Auction Lots =========" << endl;

        for (int i = 0; i < carCount; i++) {
            lots[i]->display();
        }

        cout << "Total cars listed: " << Car::getTotalCars() << endl;
    }

    void showBidders() const {
        cout << "\n======== Registered Bidders ========" << endl;

        for (int i = 0; i < bidderCount; i++) {
            cout << bidders[i].getName()
                 << " | Budget: $" << bidders[i].getBudget() << endl;
        }
    }

    void saveToFile(string filename) const {
        ofstream file(filename);

        if (!file.is_open()) {
            throw "Could not open file!";
        }

        file << houseName << endl;

        for (int i = 0; i < carCount; i++) {
            file << lots[i]->getType() << " | "
                 << lots[i]->getName() << " | $"
                 << lots[i]->getPrice() << endl;
        }

        file.close();

        cout << "\nNOTE: Saved Auction Data to file '" << filename <<"'"<< endl;
    }

    ~Auction() {
        for (int i = 0; i < carCount; i++) {
            delete lots[i];
        }
    }
};


int main() {
    Auction house(" Auto Auction");

    house.addCar(new ClassicCar("BMW", "E46 Coupe", 1997, 18000));
    house.addCar(new ClassicCar("Porsche", "911 Turbo", 1996, 62000));
    house.addCar(new ModifiedCar("Toyota", "Mark II", 1994, 95000, "Twin Turbo"));
    house.addCar(new ModifiedCar("Nissan", "Skyline R34", 1999, 120000, "V12-Century Swaped"));

    house.addBidder(Bidder("Zakki", 125000));
    house.addBidder(Bidder("Afaq ", 10000));
    house.addBidder(Bidder("Bisma ", 70000));

    house.showLots();
    house.showBidders();

    house.saveToFile("Auction.txt");

    try {
        house.addCar(new ClassicCar("Mazda", "RX-7 FD", 1995, 45000));
        house.addCar(new ClassicCar("Ferrari", "458 Pista", 1993, 95000));
    }
    catch (const char* message) {
        cout << "\nException: " << message << endl;
    }

    return 0;
}