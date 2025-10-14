/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 5: Vector Calculator
* Created: 30 September 2025
*
* userinterface.h
* Header file for userinterface.c
**********************************************************/

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

void runInterface();
void display(Vector v);
void operationError();
void numConversionError(char *invalidString);
void drawHelp();

#endif // USERINTERFACE_H