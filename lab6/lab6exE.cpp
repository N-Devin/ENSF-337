// lab6exE.cpp
// ENSF 337, Lab 6 Exercise E


#include <iostream>

using std::cin;
using std::cout;

int func1(int&, int*&);
void func2(int&, int*);

int main()
{
    int c[] = { 50, 10, 45};

    int* p = &c[2];
    
    c[1] = func1(c[1], p);

    return 0;
}


int func1(int& arg1, int*& arg2)
{
    int z = arg1 + *arg2;
    
    func2(arg1, arg2 - 2);
    
    return z;
}


void func2(int& x, int* y)
{
    *y += x;
    x += 100;
    
    // point one
}
