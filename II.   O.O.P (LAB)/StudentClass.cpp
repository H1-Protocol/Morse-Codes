#include <iostream>
#include <string>

using namespace std;

// Student Class
class Student {
    
protected:
    int rollNo;
    string name;
    int obtainedMarks;
    int birthYear;

public:

    // Default Constructor
    Student() {
        rollNo = 0;
        name = "Not Defined";
        obtainedMarks = 0;
        birthYear = 0;
    }

    // Parameterized Constructor
    Student(int rollNo, string name, int obtainedMarks, int birthYear) {
        this->rollNo = rollNo;
        this->name = name;
        this->obtainedMarks = obtainedMarks;
        this->birthYear = birthYear;
    }

    // Function to set complete student data
    void setStudentData(int rollNo, string name, int obtainedMarks, int birthYear) {
        this->rollNo = rollNo;
        this->name = name;
        this->obtainedMarks = obtainedMarks;
        this->birthYear = birthYear;
    }

    

    // Function to set integer attributes
    void setData(string attribute, int value) {

        if (attribute == "rollNo") {
            rollNo = value;
        }
        else if (attribute == "obtainedMarks") {
            obtainedMarks = value;
        }
        else if (attribute == "birthYear") {
            birthYear = value;
        }
        else {
            cout << "Invalid Attribute for Integer Value." << endl;
        }
    }
    

    // Function to display student data
    void displayStudentData() {

        cout << "\n========== Student Information ==========" << endl;

        cout << "Roll Number     : " << rollNo << endl;
        cout << "Name            : " << name << endl;
        cout << "Obtained Marks  : " << obtainedMarks << endl;
        cout << "Birth Year      : " << birthYear << endl;

        cout << "=========================================\n" << endl;
    }
};

int main() {

    

    return 0;
}
