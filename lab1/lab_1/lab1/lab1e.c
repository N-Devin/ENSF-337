#include <stdio.h>
int main()
{
    double num1 = -34.5;
    double num2 = 98.7;
    
    double sum;         // sum of num1 and num2
    double sumSquared;  // the square of num2 plus num2
    
    // 1) Add the two numbers and store the result in the variable 'sum'

     sum = num1 + num2;

    // 2) Compute the square of the sum and store the result in the variable  'sum Squared'
    //    Use the variable 'sum' (computed above) for this computation

sumSquared = sum*sum;
printf( "The sum squared is: %f \n", sumSquared );
    
    // 3) Now double the sum squared value and store the result in 'sumSquared'

printf( "The sum squared is now: %f \n", sumSquared);

       sumSquared = sumSquared*2;
    
    
    
     return 0;
}
