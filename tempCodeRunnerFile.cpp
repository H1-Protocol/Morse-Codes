#include <iostream>
#include <print>
using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person(string n, int a): name(n),age(a){}    
};
class Teacher : public Person{
    public:
    string subject;
    Teacher(string n, int a, string s):Person(n, a), subject(s){}
    void show(){
        cout << "Name    : "<<name <<endl;
        cout << "Age     : "<<age <<endl;
        cout << "Subject : "<<subject <<endl;
    }
};

class Student : public Teacher{
    public:
    string std_Name;
    bool Pass;
Student(string n, int a, string s, string st, bool pf):Teacher(n,a,s), std_Name(st), Pass(pf){}
void show(){
    cout << "Name         : "<< name << endl;
    cout << "Age          : "<< age << endl;
    cout << "Subject      : "<< subject << endl;
    cout << "Student Name : "<< std_Name << endl;
    cout << "Final Result : "<< (Pass ? "Pass" : "Fail") << endl;
}
};

int main() {

  Student G("Ghani Shah", 46, "Physics", "Zakki Shah", true);

G.show();


    return 0;
}

