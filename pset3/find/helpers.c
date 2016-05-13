/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implementation of linear search algorithm
    if (!(value >=  0)) // return false if value not even
        return false;
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implementation of bubble sort algorithm
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n-1)-i; j++)
        {
           if (values[j] > values[j+1])
           {
                int tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
           }
        }
    }
    return;
}
