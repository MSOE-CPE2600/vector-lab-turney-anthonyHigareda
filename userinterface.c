/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 5: Vector Calculator
* Created: 30 September 2025
*
* userinterface.c
* Controlls console input and output and calls
* functions from both mathcontroller.c and 
* storagecontroller.c per user requests
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vector.h"
#include "storagecontroller.h"
#include "mathcontroller.h"

void runInterface();
void display(Vector v);
void operationError();
void numConversionError(char *invalidString);
void drawHelp();

void runInterface()
{

    char input[50];
    char *delimiters = {" ,"};
    char *token1;
    char *token2;
    char *token3;
    char *token4;
    char *token5;

    int numTokens = 0;

    printf("VectorMe> "); // Prompt user for input
    fgets(input, 50, stdin); // Get input from stdin
    token1 = strtok(input, delimiters); // Grab the tokens from the input
    token2 = strtok(NULL, delimiters);  // Break at a space or comma
    token3 = strtok(NULL, delimiters);  // Excess tokens will be NULL
    token4 = strtok(NULL, delimiters);
    token5 = strtok(NULL, delimiters);

    // Make an array of all the tokens for simplicity
    char *tokens[5] = {token1, token2, token3, token4, token5};

    // Check each non-null token for a trailing
    // newline and remove it if it exists
    for (int i = 0; i < 5; i++)
    {
        if (tokens[i] != NULL)
        {
            tokens[i][strcspn(tokens[i], "\n")] = 0;
            numTokens++;
        }
    }

    // Special commands: quit, clear, help, and list
    // Or display of one vector
    // Only executable if there is one token
    if (numTokens == 1)
    {
        if (!strcmp(tokens[0], "quit"))
        {
            printf("Goodbye\n");
            exit(0);
        }
        else if (!strcmp(tokens[0], "clear"))
        {
            init();
            printf("All vectors cleared\n");
        }
        else if (!strcmp(tokens[0], "list"))
        {
            list();
        }
        else if (!strcmp(tokens[0], "help"))
        {
            drawHelp();
        }
        else
        {
            if (findVector(tokens[0]) == -1)
            {
                printf("Vector \"%s\" not found\n", tokens[0]);
            }
            else
            {
                display(getVector(tokens[0]));
            }
        }
    }
    // there should be nothing to do with only 2 tokens
    // Example operations for 3 tokens:
    // a = b
    // a * 3
    // a + b
    else if (numTokens == 3)
    {
        // a = b
        // Create or assign vector a with the same x, y, and z
        // values as the second vector
        if (!strcmp(tokens[1], "="))
        {
            Vector v1 = getVector(tokens[0]);
            Vector v2 = getVector(tokens[2]);
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            if (addVector(v1))
            {
                display(v1);
            }
        }
        // a + b
        // Calculate the value of a + b without
        // adding a new vector to the list
        else if (!strcmp(tokens[1], "+"))
        {
            Vector v1 = getVector(tokens[0]);
            Vector v2 = getVector(tokens[2]);
            Vector vret = add(v1, v2);
            strcpy(vret.name, "ans");
            display(vret);
        }
        // a - b
        // Calculate the value of a - b without
        // adding a new vector to the list
        else if (!strcmp(tokens[1], "-"))
        {
            Vector v1 = getVector(tokens[0]);
            Vector v2 = getVector(tokens[2]);
            Vector vret = sub(v1, v2);
            strcpy(vret.name, "ans");
            display(vret);
        }
        // a * x
        // Calculate the value of a * x without
        // adding a new vector to the list
        else if (!strcmp(tokens[1], "*"))
        {
            Vector v1 = getVector(tokens[0]);
            if (isdigit(tokens[2][0]) || (tokens[2][0] == '-' && isdigit(tokens[2][1])))
            {
                double scalar = atof(tokens[2]);
                Vector vret = scalarMult(v1, scalar);
                strcpy(vret.name, "ans");
                display(vret);
            }
            else
            {
                numConversionError(tokens[2]);
            }
        }
        // a . b
        // Calculate the value of a . b
        else if (!strcmp(tokens[1], "."))
        {
            Vector v1 = getVector(tokens[0]);
            Vector v2 = getVector(tokens[2]);
            double dot = dotProd(v1, v2);
            printf("ans = %-4.3lf\n", dot);
        }
        // a X b
        // Calculate the value of a X b without
        // adding a new vector to the list
        else if (!strcmp(tokens[1], "X"))
        {
            Vector v1 = getVector(tokens[0]);
            Vector v2 = getVector(tokens[2]);
            Vector vret = crossProd(v1, v2);
            strcpy(vret.name, "ans");
            display(vret);
        }
        // Unknown operation, report to user
        else
        {
            operationError();
        }
    }
    // there should be nothing to do with only 4 tokens
    // or 5 tokens without an assignment
    // Example operations for 5 tokens:
    // a = 3 4 5
    // b = 1,2,3
    // c = a + b
    // c = a * 3
    else if (numTokens == 5)
    {
        // c = a + b
        // Calculate the value of a + b and
        // assign the result to vector c
        if (!strcmp(tokens[3], "+"))
        {
            Vector vret = getVector(tokens[0]);
            Vector v1 = getVector(tokens[2]);
            Vector v2 = getVector(tokens[4]);
            vret = add(v1, v2);
            if (addVector(vret))
            {
                display(vret);
            }
        }
        // c = a - b
        // Calculate the value of a - b and
        // assign the result to vector c
        else if (!strcmp(tokens[3], "-"))
        {
            Vector vret = getVector(tokens[0]);
            Vector v1 = getVector(tokens[2]);
            Vector v2 = getVector(tokens[4]);
            vret = sub(v1, v2);
            if (addVector(vret))
            {
                display(vret);
            }
        }
        // c = a * x
        // Calculate the value of a * x and
        // assign the result to vector c
        else if (!strcmp(tokens[3], "*"))
        {
            Vector vret = getVector(tokens[0]);
            Vector v1 = getVector(tokens[2]);
            if (isdigit(tokens[4][0]) || (tokens[4][0] == '-' && isdigit(tokens[4][1])))
            {
                double scalar = atof(tokens[4]);
                vret = scalarMult(v1, scalar);
                strcpy(vret.name, tokens[0]);
                if (addVector(vret))
                {
                    display(vret);
                }
            }
            else
            {
                numConversionError(tokens[4]);
            }
        }
        // c = a . b
        // Reports an error because a dot product
        // does not return a vector value
        else if (!strcmp(tokens[3], "."))
        {
            printf("Invalid Operand! Dot product cannot be assigned to a vector\n");
        }
        // c = a X b
        // Calculate the value of a X b and
        // assign the result to vector c
        else if (!strcmp(tokens[3], "X"))
        {
            Vector vret = getVector(tokens[0]);
            Vector v1 = getVector(tokens[2]);
            Vector v2 = getVector(tokens[4]);
            vret = crossProd(v1, v2);
            if (addVector(vret))
            {
                display(vret);
            }
        }
        // a = 1 2 3
        // Checks that the 4th token is a digit
        // then creates or assigns a vector with given values
        else 
        {
            Vector vnew;
            strcpy(vnew.name, tokens[0]);
            if (!isdigit(tokens[2][0]))
            {
                numConversionError(tokens[2]);
            }
            else if (!isdigit(tokens[3][0]))
            {
                numConversionError(tokens[3]);
            }
            else if (!isdigit(tokens[4][0]))
            {
                numConversionError(tokens[4]);
            }
            else 
            {
                vnew.x = atof(tokens[2]);
                vnew.y = atof(tokens[3]);
                vnew.z = atof(tokens[4]);
                if (addVector(vnew))
                {
                    display(vnew);
                }
            }
        }
    }
    // Comes here if there are 2 or 4 tokens in the input
    else
    {
        printf("Invalid input! Incorrect number of arguments!\n");
    }
}

    

void display(Vector v)
{
    printf("%s = %-4.3lf %-4.3lf %-4.3lf\n", v.name, v.x, v.y, v.z);
}

void operationError()
{
    printf("Invalid operand! Valid operations are:\n");
    printf("%s\n%s\n%s\n%s\n%s\n", "[+]    ADDITION", "[-]    SUBTRACTION",
        "[*]    SCALAR MULTIPLICATION", "[.]    DOT PRODUCT",
        "[X]    CROSS PRODUCT");
}

void numConversionError(char *invalidString)
{
    printf("Invalid input! \"%s\" is not a number!\n", invalidString);
}

void drawHelp()
{
    printf("Vector Calculator\n  Created By: Anthony Higareda\n\n");
    printf("Create 3-dimensional vectors and perform mathematical functions on them.\n\n");
    printf("* Program Functions Available \n");
    printf("* clear   - Erase all saved vectors\n");
    printf("* list    - List all saved vectors\n");
    printf("* help    - Display this help menu\n");
    printf("* quit    - Quit the program\n\n");
    printf("* Mathematical Functions Available \n");
    printf("* %-22s [+]\n* %-22s [-]\n* %-22s [*]\n* %-22s [.]\n* %-22s [X]\n\n",
        "ADDITION", "SUBTRACTION", "SCALAR MULTIPLICATION", "DOT PRODUCT", "CROSS PRODUCT");
    printf("* Example syntax:\n");
    printf("> a = 1 2 3\n> b = 3,4,5\n> c = a + b\n\n");
    printf("** IMPORTANT: \n** All terms or symbols must be separated %s",
        "by EXACTLY ONE space ' ' or comma ','\n\n");
}