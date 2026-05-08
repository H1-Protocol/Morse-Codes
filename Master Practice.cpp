#include <iostream>
#include <string>

using namespace std;

// 1. Template Example
template <typename T>
void displayInfo(T data) {
    cout << "Log: " << data << endl;
}

// 2. Base Class (Abstract)
class Entity {
protected:
    int id;
    static int count; // Static Variable
public:
    Entity(int _id) : id(_id) { count++; } // Initialization List
    virtual void performAction() = 0;      // Pure Virtual Function
    virtual ~Entity() {}                   // Virtual Destructor
    static int getCount() { return count; } // Static Method
};

int Entity::count = 0;

// 3. Composition Class
class Skill {
public:
    string name;
    Skill(string n) : name(n) {}
};

// 4. Derived Class with Deep Copy
class Developer : public Entity {
private:
    string* role;        // Pointer for Deep Copy practice
    Skill devSkill;      // Composition (Has-a Skill)
public:
    Developer(int i, string r, string s) : Entity(i), devSkill(s) {
        role = new string(r);
    }

    // Copy Constructor (Deep Copy)
    Developer(const Developer& other) : Entity(other.id), devSkill(other.devSkill) {
        role = new string(*other.role);
    }

    // Overriding Virtual Function
    void performAction() override {
        cout << "Dev ID " << id << " coding in " << *role 
             << " with skill: " << devSkill.name << endl;
    }

    ~Developer() { delete role; } // Destructor
    
    // Friend Function
    friend void hack(Developer& d);
};

void hack(Developer& d) {
    cout << "Hacking Dev ID: " << d.id << endl;
}

int main() {
    displayInfo("Starting System...");

    // Polymorphism with Base Pointer
    Entity* emp = new Developer(101, "C++", "Logic");
    emp->performAction();

    cout << "Total Entities: " << Entity::getCount() << endl;

    delete emp;
    return 0;
}