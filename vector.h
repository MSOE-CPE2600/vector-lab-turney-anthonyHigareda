/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 5: Vector Calculator
* Created: 30 September 2025
*
* vector.h
* Header file for vector.h
**********************************************************/

#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector
{
    char name[5];
    double x;
    double y;
    double z;
} Vector;

#endif // VECTOR_H