#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    //Default Constructor
    Person() : name("Unknown"), age(0) {}

    //Parameterized Constructor
    Person(string n, int a) : name(n), age(a) {}

    //Overridden Function 
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float marks;

public:
    Student() : Person(), rollNo(0), marks(0.0) {}

    Student(string n, int a, int r, float m) : Person(n, a), rollNo(r), marks(m) {}

    // Function Overloading
    void setData(int r) {
        rollNo = r;
    }
    void setData(int r, float m) {
        rollNo = r;
        marks = m;
    }

    void display() override {
        Person::display(); // Call base version
        cout << "Roll No: " << rollNo << ", Marks: " << marks << endl;
    }

    Student operator+(const Student& other) {
        Student temp;
        temp.name = "Combined Student";
        temp.marks = this->marks + other.marks;
        return temp;
    }

    void operator-(Student& other) {
        swap(this->name, other.name);
        swap(this->age, other.age);
        swap(this->rollNo, other.rollNo);
        swap(this->marks, other.marks);
    }
    
    float getMarks() { return marks; }
};

int main() {
    // Creating objects using different constructors
    Student s1("Alice", 20, 101, 85.5);
    Student s2("Bob", 21, 102, 75.0);

    cout << "--- Initial Data ---" << endl;
    s1.display();
    s2.display();

    // Demonstrate Function Overloading
    s1.setData(105, 92.0); 
    cout << "\n--- After setData Overloading ---" << endl;
    s1.display();

    // Demonstrate Operator Overloading (+)
    Student s3 = s1 + s2;
    cout << "\nTotal Marks of s1 + s2: " << s3.getMarks() << endl;

    // Demonstrate Operator Overloading (-) to swap
    cout << "\n--- Swapping s1 and s2 using '-' operator ---" << endl;
    s1 - s2; 
    s1.display();
    s2.display();

    return 0;
}