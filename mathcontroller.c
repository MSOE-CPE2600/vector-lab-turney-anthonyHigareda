/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 6: Git and GitHub
* Created: 30 September 2025
*
* mathcontroller.c
* Controlls math function calling on various vectors
**********************************************************/

#include <stdio.h>
#include <string.h>
#include "vector.h"

Vector add(Vector v1, Vector v2);
Vector sub(Vector v1, Vector v2);
Vector scalarMult(Vector v, double scalar);
double dotProd(Vector v1, Vector v2);
Vector crossProd(Vector v1, Vector v2);


Vector add(Vector v1, Vector v2)
{
    Vector vret;
    vret.x = v1.x + v2.x;
    vret.y = v1.y + v2.y;
    vret.z = v1.z + v2.z;

    return vret;
}

Vector sub(Vector v1, Vector v2)
{
    Vector vret;
    vret.x = v1.x - v2.x;
    vret.y = v1.y - v2.y;
    vret.z = v1.z - v2.z;

    return vret;
}

Vector scalarMult(Vector v, double scalar)
{
    Vector vret;
    vret.x = v.x * scalar;
    vret.y = v.y * scalar;
    vret.z = v.z * scalar;

    return vret;
}

double dotProd(Vector v1, Vector v2)
{
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector crossProd(Vector v1, Vector v2)
{
    Vector vret;
    vret.x = (v1.y * v2.z) - (v1.z * v2.y);
    vret.y = (v1.z * v2.x) - (v1.x * v2.z);
    vret.z = (v1.x * v2.y) - (v1.y * v2.x);

    return vret;
}