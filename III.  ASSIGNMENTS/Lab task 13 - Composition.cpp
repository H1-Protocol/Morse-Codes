#include <iostream>
#include <string>
using namespace std;

class Address {
    private:
    string city, country;
    public:
    Address(string city, string country):city(city), country(country){}
    void display(){
        cout << "City: " << city << endl;
        cout << "Country: " << country << endl;
    }
};
class Marks{
    private:
    float sub1, sub2, sub3;
    public:
    Marks(float sub1, float sub2, float sub3):sub1(sub1), sub2(sub2), sub3(sub3){}
    float total(){
        return sub1+sub2+sub3;
    }  
    float average(){
        return total()/3.0;
    }
    void display(){
        cout << "Sub1: " << sub1 << endl;
        cout << "Sub2: " << sub2 << endl;
        cout << "Sub3: " << sub3 << endl;
    }
};
class Student{
    private:
    int rollNo;
    string name;
    Address address;
    Marks marks;

    public:
Student(int rollNo, string name, Address address, Marks marks/*, string city, string country, float sub1, float sub2, float sub3*/) : rollNo(rollNo), name(name), address(address), marks(marks)/*, city(city), country(country), sub1(sub1), sub2(sub2), sub3(sub3)*/{}
    
    void displayFull_package(){
        cout << "<========Student Record========>" << endl;
        cout << "Roll No    :" << rollNo << endl;
        cout << "Name       :" << name << endl;
        address.display();
        marks.display();
        cout << "Total Marks: " << marks.total() << endl;
        cout << "Average    : " << marks.average() << endl;
        cout << "<==============================>" << endl<< endl<< endl;

        
    }
};

int main(){
    
    Address add1("Peshawar", "Pakistan");
    Marks mk1(43.0, 54.0, 76.0);
    Student stu1(101, "Zakki", add1, mk1);
    stu1.displayFull_package();
 
    Address add2("Agarthe", "Agarthese Empire");
    Marks mk2(99.9, 99.9, 99.8);
    Student stu2(1, "Vegimite", add2, mk2);
    stu2.displayFull_package();

    Address add3("Peshawar", "Pakistan");
    Marks mk3(26.0, 76.0, 84.0);
    Student stu3(102, "Zeeshan", add3, mk3);
    stu3.displayFull_package();

    return 0;
}