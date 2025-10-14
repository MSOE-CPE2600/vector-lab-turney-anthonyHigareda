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


void init();
Vector getVector(char *name);
int findVector(char *name);
int addVector(Vector vnew);
void list();

Vector vectors[10];

void init()
{
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

int addVector(Vector vnew)
{
    int i = findVector(vnew.name);
    if (i == -1)
    {
        i = findVector("NULL");
        if (i == -1)
        {
            printf("Storage is full! Please clear storage with \"clear\"%s",
            " before adding new vectors\n");
            return 0;
        }
        else
        {
            vectors[i] = vnew;
        }
    }
    else
    {
        vectors[i] = vnew;
    }
    return 1;
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

