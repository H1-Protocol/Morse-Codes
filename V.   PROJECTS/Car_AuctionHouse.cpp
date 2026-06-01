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
    Car(string make, string model, int year, double price):make(make), model(model), year(year), price(price) {
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
    ClassicCar(string make, string model, int year, double price) : Car(make, model, year, price) {}

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
    ModifiedCar(string make, string model, int year, double price, string mod) : Car(make, model, year, price) {
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

    Bidder(string name, double budget) : name(name), budget(budget){}

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
    Auction(string Aucname):houseName(Aucname), carCount(0), bidderCount(0){}

    void addCar(Car* c) {   
        if (carCount >= 6) {
            throw "Auction is full! Max 6 lots.";
        }

        lots[carCount] = c;
        carCount++;
    }

    void addBidder(Bidder b) {
           if (bidderCount >= 10) {
            throw "Auction is full of People! Max 10 bidders.";
        }
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

    file << "===== " << houseName << " =====" << endl;

    // Save Cars
    file << "\n--- Auction Lots ---" << endl;
    for (int i = 0; i < carCount; i++) {
        file << lots[i]->getType() << " | "
             << lots[i]->getName() << " | $"
             << lots[i]->getPrice() << endl;
    }

    // Save Bidders
    file << "\n--- Registered Bidders ---" << endl;
    for (int i = 0; i < bidderCount; i++) {
        file << bidders[i].getName()
             << " | Budget: $"
             << bidders[i].getBudget() << endl;
    }

    file.close();

    cout << "\nNOTE: Saved Auction Data and Bidders to file '"
         << filename << "'" << endl;
}
    void readFromFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw "Could not open file!";
    }

    string line;

    cout << "\nReading file contents:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

    ~Auction() {
        for (int i = 0; i < carCount; i++) {
            delete lots[i];
        }
    }
};


int main() {
    Auction house("Auto Auction");

    int choice;

    do {
        cout << "\n====== AUTO AUCTION MENU ======\n";
        cout << "1. Add Classic Car\n";
        cout << "2. Add Modified Car\n";
        cout << "3. Add Bidder\n";
        cout << "4. Show Auction Lots\n";
        cout << "5. Show Bidders\n";
        cout << "6. Save to File\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                string make, model;
                int year;
                double price;

                cout << "Enter Make: ";
                cin >> make;
                cout << "Enter Model: ";
                cin >> model;
                cout << "Enter Year: ";
                cin >> year;
                cout << "Enter Price: ";
                cin >> price;

                house.addCar(new ClassicCar(make, model, year, price));
                cout << "Classic Car Added!\n";
            }

            else if (choice == 2) {
                string make, model, mod;
                int year;
                double price;

                cout << "Enter Make: ";
                cin >> make;
                cout << "Enter Model: ";
                cin >> model;
                cout << "Enter Year: ";
                cin >> year;
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Modification: ";
                cin >> mod;

                house.addCar(new ModifiedCar(make, model, year, price, mod));
                cout << "Modified Car Added!\n";
            }

            else if (choice == 3) {
                string name;
                double budget;

                cout << "Enter Bidder Name: ";
                cin >> name;
                cout << "Enter Budget: ";
                cin >> budget;

                house.addBidder(Bidder(name, budget));
                cout << "Bidder Added!\n";
            }

            else if (choice == 4) {
                house.showLots();
            }

            else if (choice == 5) {
                house.showBidders();
            }

            else if (choice == 6) {
                house.saveToFile("Auction.txt");
            }

            else if (choice == 7) {
                cout << "Exiting Program...\n";
            }

            else {
                cout << "Invalid choice!\n";
            }

        } catch (const char* message) {
            cout << "Exception: " << message << endl;
        }

    } while (choice != 7);

    return 0;
}