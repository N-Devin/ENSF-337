//  ENSF 337 - Lab 6 Exercise A
//  M. Moussavi
//  lab6exe_A.h

#ifndef lab6ExA_h
#define lab6ExA_h

#define MAX_BITS 5
#define MAX_ARRAY_SIZE 4

typedef struct Bits_Pattern
{
    char bits[MAX_BITS];
    int value;
    
} Bits_Pattern;


int read_bit_patterns(Bits_Pattern * arr, const char* filename);

void display_bit_patterns(Bits_Pattern arr[], int size);

void calculate_value(Bits_Pattern * byte);

#endif /* lab6ExA_h */
