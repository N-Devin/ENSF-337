/*
* File Name: lab_one.c
* Assignment: Lab 1 Exercise B
* Lab section: B02
* Completed by: Nimna Wijedasa * Submission Date: Sept 18, 2022 */
#include <stdio.h> #include <math.h>
int main() {
double angle, sine, taylor;
printf("input angle \n");
scanf("%lf",&angle);
sine = sin(angle);
taylor = (angle) - ((pow(angle,3)) / 6 ) + (pow(angle,5) / 7))/ 5040 );
(120) ) - ((pow(angle, printf("The angle is %.5lf \nThe Taylor approximation is %.5lf\n", sine,taylor);
return 0; }
