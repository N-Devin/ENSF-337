// part1.cpp
// ENSF 337 Fall 2022 exercise D
//


#include <iostream>
using namespace std;

#include "DynString.h"

int main()
{
    DynString a("Apple");
    DynString *b;
    
    // NOTE: The fact that the following code is within an extra pair of
    // braces means that the object b will disappear before the object c
    // is created.
    {
        b = new DynString("film");
        char ch = b -> at(2);
        cout << "ch is: " << ch << endl;
        cout << "a before call to truncate function is: " << a.c_str() << endl;
        a.truncate(3);
        cout << "a after truncate is: " << a.c_str() << endl;
        DynString c("Debug");
    }
    // point two
    delete b;
    return 0;
}
