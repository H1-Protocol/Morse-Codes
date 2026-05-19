#include <vector4.h>
#include <matrix4x4.h>
#include <iostream>
int main()
{
Matrix4x4 A
{
    Vector4 {2, 3, 4, 5},
    Vector4 {0, 0, 0, 0},
    Vector4 {0, 0, 0, 0},
    Vector4 {0, 0, 0, 0},
};

Matrix4x4 B
{
        Vector4 {1, 0, 0, 0},
        Vector4 {6, 0, 0, 0},
    Vector4 {0, 0, 0, 0},
    Vector4 {0, 0, 0, 0},
};

std::cout <<"A   =" << A << std::endl;
std::cout <<"B   =" << B << std::endl;
std::cout <<"A*B =" << A*B << std::endl;


return 0;