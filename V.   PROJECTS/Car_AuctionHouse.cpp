#include <iostream>
#include <fstream>
#include <limits> //For the getline to work, and to not make an infinite loop
#include <cstdio> // Required for remove()
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
        cout << " [MODIFIED] ";
        Car::display();
        cout << "   MOD Installed: " << modification << endl;
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
        cout << "1. Add Classic Car\n2. Add Modified Car\n3. Add Bidder\n";
        cout << "4. Show Auction Lots\n5. Show Bidders\n6. Save to File\n";
        cout << "7. Read from File\n8. Delete File\n9. Exit\n";
        cout << "Enter choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            continue;
        }
        cin.ignore(); // Consume the trailing newline

        try {
            switch (choice) {
            case 1: {
                string make, model; int year; double price;
                cout << "Enter Make: "; getline(cin, make);
                cout << "Enter Model: "; getline(cin, model);
                cout << "Enter Year: "; cin >> year;
                cout << "Enter Price: "; cin >> price;
                cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                house.addCar(new ClassicCar(make, model, year, price));
                cout << "Classic Car Added!\n";
                break;
            }
            case 2: { 
                string make, model, mod; int year; double price;
                cout << "Enter Make: "; getline(cin, make);
                cout << "Enter Model: "; getline(cin, model);
                cout << "Enter Year: "; cin >> year;
                cout << "Enter Price: "; cin >> price;
                cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); 
                cout << "Enter Modification: "; getline(cin, mod);
                house.addCar(new ModifiedCar(make, model, year, price, mod));
                cout << "Modified Car Added!\n";
                break;
            }
            case 3: { // Add Bidder
                string name; double budget;
                cout << "Enter Bidder Name: "; getline(cin, name);
                cout << "Enter Budget: "; cin >> budget;
                cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
                house.addBidder(Bidder(name, budget));
                cout << "Bidder Added!\n";
                break;
            }
            case 4: house.showLots(); break;
            case 5: house.showBidders(); break;
            case 6: house.saveToFile("Auction.txt"); break;
            case 7: house.readFromFile("Auction.txt"); break;
            case 8: { // Delete the File
                if (remove("Auction.txt") == 0) cout << "File 'Auction.txt' deleted successfully.\n";
                else cout << "Error: Could not delete file (it may not exist).\n";
                break;
            }
            case 9: cout << "Exiting Program...\n"; break;
            default: cout << "Invalid choice!\n";
            }
        } catch (const char* message) {
            cout << "Exception: " << message << endl;
        }
    } while (choice != 9);

    return 0;
}