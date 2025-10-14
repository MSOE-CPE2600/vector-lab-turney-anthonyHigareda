/*********************************************************
* CPE 2600-121
* Dr. Turney
* Fall 2025
* 
* Anthony Higareda
* Lab 6: Git and GitHub
* Created: 30 September 2025
*
* storagecontroller.c
* Manages all of the data being handled in this program
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "mathcontroller.h"

#define EXPANSION_SIZE 3


void init();
void reallocate();
Vector getVector(char *name);
int findVector(char *name);
void addVector(Vector vnew);
void list();

Vector *vectors;
int numVectors;

void init()
{
    vectors = malloc(sizeof(Vector) * EXPANSION_SIZE);
    numVectors = 0;
    Vector vnull;
    strcpy(vnull.name, "NULL");
    vnull.x = 0;
    vnull.y = 0;
    vnull.z = 0;
    for (int i = 0; i < 10; i++)
    {
        vectors[i] = vnull;
    }
}

void reallocate()
{
    Vector *newVectors = malloc(sizeof(Vector) * (numVectors + EXPANSION_SIZE));
    int i;
    for (i = 0; i < numVectors; i++)
    {
        newVectors[i] = vectors[i];
    }
    Vector vnull;
    strcpy(vnull.name, "NULL");
    vnull.x = 0;
    vnull.y = 0;
    vnull.z = 0;    
    for (i = numVectors; i < numVectors + EXPANSION_SIZE; i++)
    {
        newVectors[i] = vnull;
    }
    free(vectors);
    vectors = newVectors;
}

Vector getVector(char *name)
{
    int i = findVector(name);
    if (i != -1)
    {
        return vectors[i];
    }
    else
    {
        Vector vnew;
        strcpy(vnew.name, name);
        vnew.x = 0;
        vnew.y = 0;
        vnew.z = 0;
        addVector(vnew);
        return vnew;
    }
}

int findVector(char *name)
{
    for (int i = 0; i < 10; i++)
    {
        if (!strcmp(vectors[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void addVector(Vector vnew)
{
    int i = findVector(vnew.name);
    if (i == -1)
    {
        i = findVector("NULL");
        if (i == -1)
        {
            reallocate();
        }
        vectors[i] = vnew;
        numVectors += 1;
    }
    else
    {
        vectors[i] = vnew;
    }
}

void list()
{
    if (!strcmp(vectors[0].name, "NULL"))
    {
        printf("No vectors stored\n");
    }
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(vectors[i].name, "NULL"))
        {
            Vector v = vectors[i];
            printf("%s = %-4.3lf %-4.3lf %-4.3lf\n", v.name, v.x, v.y, v.z);
        }
        else
        {
            break;
        }
    }
}

