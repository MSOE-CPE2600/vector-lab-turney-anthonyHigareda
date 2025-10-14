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

#define EXPANSION_SIZE 5


void init();
void clear();
void reallocate();
Vector getVector(char *name);
int findVector(char *name);
void addVector(Vector vnew);
void list();
int loadFromCSV(char *filename);
int saveToCSV(char *filename);

Vector *vectors;
int numVectors;
int currentSize;

void init()
{
    vectors = malloc(sizeof(Vector) * EXPANSION_SIZE);
    numVectors = 0;
    currentSize = EXPANSION_SIZE;
    Vector vnull;
    strcpy(vnull.name, "NULL");
    vnull.x = 0;
    vnull.y = 0;
    vnull.z = 0;
    for (int i = 0; i < currentSize; i++)
    {
        vectors[i] = vnull;
    }
}

void clear()
{
    free(vectors);
}

void reallocate()
{
    Vector *newVectors = malloc(sizeof(Vector) * (currentSize + EXPANSION_SIZE));
    int i;
    for (i = 0; i < numVectors; i++)
    {
        newVectors[i] = vectors[i];
    }
    currentSize += EXPANSION_SIZE;
    Vector vnull;
    strcpy(vnull.name, "NULL");
    vnull.x = 0;
    vnull.y = 0;
    vnull.z = 0;    
    for (i = numVectors; i < currentSize; i++)
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
    for (int i = 0; i < currentSize; i++)
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
            vectors[numVectors] = vnew;
        }
        else
        {
            vectors[i] = vnew;
        }
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
    for (int i = 0; i < currentSize; i++)
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

int loadFromCSV(char *filename)
{
    FILE *data = fopen(filename, "r");
    if (data == NULL)
    {
        return 1;
    }
    char *line = malloc(sizeof(char) * 50);

    while (fgets(line, sizeof(char) * 50, data) != NULL)
    {
        Vector vnew;
        strcpy(vnew.name, strtok(line, ","));
        vnew.x = atof(strtok(NULL, ","));
        vnew.y = atof(strtok(NULL, ","));
        vnew.z = atof(strtok(NULL, ","));
        addVector(vnew);
    }
    return 0;
}

int saveToCSV(char *filename)
{
    FILE *save = fopen(filename, "w");
    if (save == NULL)
    {
        return 1;
    }
    for (int i = 0; i < numVectors; i++)
    {
        char name[10];
        strcpy(name, vectors[i].name);
        double x = vectors[i].x;
        double y = vectors[i].y;
        double z = vectors[i].z;
        fprintf(save, "%s,%f,%f,%f\n", name, x, y, z);
    }
    fclose(save);
    return 0;
}