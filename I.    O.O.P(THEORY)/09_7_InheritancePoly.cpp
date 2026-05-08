#include <iostream>
using namespace std;

class Shape
{
public:
    //virtual void draw() = 0; //pure virtual to make it abstract class, also run time binding 
    virtual void draw() // Remove virtual to make it early/static/compile time binding
    {
        cout<<"Draw a Shape"<<endl;
    }
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout<<"Draw a Circle"<<endl;
    }
};

class Square : public Shape
{
public:
    void draw()
    {
        cout<<"Draw a Square"<<endl;
    }
};

int main()
{
    Shape *shapes[3];
    shapes[0] = new Shape(); // Give error when we make Shape abstract (Pure Virtual)
    shapes[1] = new Circle();
    shapes[2] = new Square();
    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw();
    }

    Shape s;
    cout<<sizeof(s); // Size of object increased by 4 Bytes
                     // As when virtual is used, object add
                     // VPTR (Virutal Pointer), which points to vtable.
                                      
                     // Without virtual give 1 byte, necessary 
                     // for each object has a unique address & 
                     // compiler distinguish between two objects.
    return 0;
}
