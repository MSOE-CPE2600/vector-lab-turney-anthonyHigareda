/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 6: Git and GitHub
* Created: 30 September 2025
*
* main.c
* Initializes the vector program then hands off control
* to userinterface.c
*
* Compile with:
* gcc -o vector main.c mathcontroller.c storagecontroller.c userinterface.c - Wall
**********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "mathcontroller.h"
#include "storagecontroller.h"
#include "userinterface.h"

int main(int argc, char const *argv[])
{
    if (argc > 1 && !strcmp(argv[1], "-h"))
    {
        drawHelp();
    }
    init();
    while (1)
    {
        runInterface();
    }
}