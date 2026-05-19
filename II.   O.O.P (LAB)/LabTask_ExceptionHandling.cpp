#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputData() {
        cout << "Enter Name: ";
        cin >> name;
        
        cout << endl << "Enter Roll Number: ";
        cin >> rollNumber;
        
        cout << endl << "Enter Marks: ";
        cin >> marks;
        
    }

    void validateData() {
        if (name == " ") {
            throw runtime_error("Invalid Name Exception");
        }
        
        if (rollNumber <= 0) {
            throw runtime_error("Invalid Roll Number Exception");
        }
        
        if (marks < 0 || marks > 100) {
            throw runtime_error("Invalid Marks Exception");
        }
    }

    void displayData() {
        cout << endl <<"========Student Record========" << endl;
        cout << "Name       : " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks      : " << marks << endl;
    }
};

int main() {
    Student lil_boi;

    char Again = 'Y';
    while (Again == 'Y' || Again == 'y') {
    try {
        lil_boi.inputData();
        lil_boi.validateData();
        
        // If the validation passes, displays the data
        lil_boi.displayData();
    }
    catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Exception: An Unknown Hacker has Breached and Destabilized the Main System with errors./n Mayday...Mayday..." << endl;
    }
    cout << "Do you want to enter another student record? (Y/N): ";
    cin >> Again;
    }
    return 0;
}