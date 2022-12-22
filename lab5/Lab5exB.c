/*
 *  File: lab5exB.c
 *  ENSF 337, lab 5, Exercise B
 */
#include <stdio.h>
#include <stdlib.h>

// This is a simple C program that is supposed to create an array of type double,
// (dyanamically on the heap), filling it with some arbitrary numbers and then
// using the array as needed. But the program doesn't do any thing useful becaues
// some flaws in the main function and improper design of the function
// create_array.

double* create_array(double * x, unsigned long n);
void populate_array(double *array, int n);

int main(void) {
    printf("\nProgram started...\n");
    double *array = NULL;
    int n = 20;
    int count = 0;
    array = create_array(array, n);
    
    if( array != NULL) {
        populate_array(array, n);
        
        // displays half of the values of the array
        for(int i = 0; i < n/2; i++){
            printf("%f\n", *array++);
            count++;
        }
        
        // According to C standard, the program's behaviour, after the following
        // call to the function free is considered "Undefined" and needs to be fixed.
        
        free((array - count));
    }
    
    printf("Program terminated...\n");
    return 0;
}

// THE FOLLOWING FUNCTION IS NOT PROPERLY DESINGED AND NEEDS TO BE FIXED
double* create_array(double *x, unsigned long n) {
    x = malloc(n *sizeof(double));
    if(x == NULL){
        printf("Sorry Memory Not Available. Program Terminated.\n");
        exit(1);
    }
    return (x);
}

void populate_array(double *array, int n) {
    int i;
    for(i = 0; i < n; i++)
        array[i] = (i + 1) * 100;
}
