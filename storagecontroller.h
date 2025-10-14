/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 6: Git and GitHub
* Created: 30 September 2025
*
* storagecontroller.h
* Header file for storagecontroller.c
**********************************************************/

#ifndef STORAGE_CONTROLLER_H
#define STORAGE_CONTROLLER_H

#include "vector.h"

void init();
void clear();
void reallocate();
Vector getVector(char *name);
int findVector(char *name);
int addVector(Vector vnew);
void list();
int loadFromCSV(char *filename);
int saveToCSV(char *filename);

#endif // STORAGE_CONTROLLER_H