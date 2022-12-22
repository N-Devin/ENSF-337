// ENSF 337 - Fall 2022 - Exercise B
// lab7String.h
// M. Moussavi

#ifndef lab7String_h
#define lab7String_h
#include <iostream>
using std::cout;
using std::endl;

// WARNING
//   The Lab7String class has a major defect.  If you try to
//   copy a Lab7String object, bad things will happen.

class Lab7String {
public:
    Lab7String();
    // PROMISES: Empty string object is created.
    
    Lab7String(const char *s);
    // PROMISES: s points to first char of a built-in string.
    // REQUIRES: String object is created by copying chars from s.
    
    ~Lab7String();
    
    int length() const;
    // PROMISES: Return value is number of chars in string.
    
    const char * c_str() const;
    // PROMISES:
    //   Return value points to first char in built-in string
    //   containing the chars of the string object.
    
    void set_char(int pos, char c);
    // REQUIRES: pos >= 0 && pos < length(), c != '\0'
    // PROMISES: Character at position pos is set equal to c.
private:
    int lengthM;
    char *storageM;
};


#endif /* lab7String_h */
