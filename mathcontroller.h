/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 6: Git and GitHub
* Created: 30 September 2025
*
* mathcontroller.h
* Header file for mathcontroller.c
**********************************************************/

#ifndef MATH_CONTROLLER_H
#define MATH_CONTROLLER_H

#include "vector.h"

Vector add(Vector v1, Vector v2);
Vector sub(Vector v1, Vector v2);
Vector scalarMult(Vector v, double scalar);
double dotProd(Vector v1, Vector v2);
Vector crossProd(Vector v1, Vector v2);

#endif // MATH_CONTROLLER_H