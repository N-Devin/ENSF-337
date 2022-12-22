// DynString.cpp
// ENSF 337 Fall 2022 lab 7 exercise D
//
// completed by:
// lab section:
#include <assert.h>
#include <string.h>
#include "DynString.h"

DynString::DynString()
: lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s)
: lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
}

DynString::~DynString()
{
    delete [] storageM;
}

int DynString::length() const
{
    return lengthM;
}

const char DynString::at(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

const char * DynString::c_str() const
{
    return storageM;
}


void DynString::append(const DynString& tail)
{
    // Students will complete the definition of this function.
    int tot_len = lengthM + tail.length() +1;

    char* new_arr = new char[tot_len];
    for (int i = 0; i < lengthM ; i++){
        new_arr[i] = storageM[i];
    }
    for (int i = lengthM, j = 0; i < tot_len ; i++, j++){
        new_arr[i] = tail.storageM[j];
    }
    new_arr[tot_len] = '\0';
    delete [] storageM;
    storageM = new_arr;
    lengthM = tot_len - 1;

}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    // Point one
}
