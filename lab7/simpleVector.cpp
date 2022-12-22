// ENSF 337- lab 7 - Exercise D
//  simpleVector.cpp

/*
 NOTES ON MEMORY ALLOCATION POLICIES FOR SimpleVector OBJECT:
 
 - If vector objects are supposed to be empty storageM will be NULL and the values
   of sizeM and capacityM must be set to zero.
 - If the objects of vector are supposed to be initialize with supplied values of
   an array, the size a and values in the dynamically memory space for storageM
   must be identical to the size and values in the supplied array. And, the
   values of sizeM and capacityM should be both set to the exact size of array.
 
- If any member function need to resize the vector, it should check the values of
  sizeM and capacityM:
  - If sizeM is equal to capacityM and vector is empty (i.e. capaictyM is equal to
    zero), capcityM should be changed to 2.
  - Otherwise, if sizeM is equal to capacityM, and capacityM is not zero (i.e.
    vector is NOT empty), the value of capacityM should be doubled up
  EXAMPLE: if capacityM is 5 and sizeM is also 5:
     1. the value of capacityM should be changed to 10.
     2. the dynamically allocated memory space for storageM should be reallocated
        to 10.
     3. The current values in the vector should be preserved and any unnecessary
        dynamically allocated memory must to deallocated.
*/

#include "simpleVector.h"
#include <cassert>
using namespace std;

SimpleVector::SimpleVector(const TYPE *arr, int n) {
    storageM = new TYPE[n];
    sizeM = n;
    capacityM = n;
    for(int i =0; i < sizeM; i++)
        storageM[i] = arr[i];
}

TYPE& SimpleVector::at(int i) {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}

const TYPE& SimpleVector::at(int i)const {
    assert(i >= 0 && i < sizeM);
    return storageM[i];
}


// The followng member function should follow the above-mentioned memory
// management policy to resize the vector, if necessary. More specifically:
//   - If sizeM < capacityM it doesn't need to make any changes to the size of
//     allocated memory for vector
//   - Otherwise it follows the above-mentioned memory policy to create additionl
//     memory space and adds the new value, val, to the end of the current vector
//     and increments the value of sizeM by 1
void SimpleVector::push_back(TYPE val) {
    
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS
if (sizeM == capacityM){
    int updated_cap = (capacityM ==0 ) ? 2 : 2 *capacityM;
    TYPE *new_location = new TYPE [updated_cap];
    for (int i = 0; i < size(); i++)
    {
        new_location[i] = storageM[i];
    }
    delete[ ] storageM;
    storageM = new_location;
}

storageM[sizeM] = val;
sizeM++;
}


SimpleVector::SimpleVector(const SimpleVector& source) {
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS
    sizeM = 0;
    capacityM = 0;
    storageM = 0;
    int size = source.size();
    TYPE * storage = new TYPE [size];
    for(int i = 0 ; i < size; i ++){
        storage[i] = source.storageM[i];
    }
    storageM = storage;
    sizeM = source.size();
    capacityM = source.size();


}

SimpleVector& SimpleVector::operator= (const SimpleVector& rhs ){
//  THIS FUNCTION MUST BE COMPLETED BY THE STUDENTS
    int size2 = rhs.size();
    if( this != &rhs){
        TYPE * storage2 = new TYPE [size2];
        for(int i = 0 ; i < size2; i ++){
            storage2[i] = rhs.storageM[i];
        }
        delete [] storageM;
        storageM = storage2;
        sizeM = rhs.size();
        capacityM = rhs.size();
    }
    return *this;
}
