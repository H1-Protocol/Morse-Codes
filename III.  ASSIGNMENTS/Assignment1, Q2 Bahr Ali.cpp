#include <iostream>
#include <print>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person(string n, int a):name(n), age(a){}
};
class Teacher : public Person{
    string subject;
    public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s){}
    void displayTeacherinfo(){
        cout << "Name: " <<name<<", "<< "Age: " <<age<<endl<<"Subject: "<<subject;
    }
};

class Student : public Person{
    public:
   int studentID;
   Student(string n, int a, int sD): Person(n, a), studentID(sD){}
   void displayStudentinfo(){
        cout << "Name: " <<name<<", "<< "Age: " <<age<<endl<<"ID: "<<studentID;
    }
};

class Department{
    public:
    string dep;
    Teacher* teach;
    Student* stud;
    Department( string d) :  dep(d), teach(nullptr), stud(nullptr){}

    void addTeacher(Teacher* t){
        teach = t;
    }
    void addStudent(Student* s){
        stud = s;
    }
    void displayInfo(){
        cout << "Department: "<< dep<<endl;
        cout << "Teachers: "<<endl;
    teach->displayTeacherinfo();
    stud->displayStudentinfo();
        
        
    }
};

int main() {

    Department objCS("Computer Science");
    Department objMath("Mathematics");

    Teacher prof1("John Doe", 40, "Computer Networks");
    Teacher prof2("Jane Smith", 35, "Calculus");

    Student student1("Alice Johnson", 20, 12345);
    Student student2("Bob Williams", 22, 67890);

    objCS.addTeacher(&prof1);
    objMath.addTeacher(&prof2);

    objCS.addStudent(&student1);
    objMath.addStudent(&student2);

    objCS.displayInfo();
    cout << endl;
    objMath.displayInfo();

    return 0;
}

