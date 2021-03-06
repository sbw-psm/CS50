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
    // implementation of binary search algorithm
    if (!(value >=  0)) // return false if value not even
        return false;

    int low = 0, high = n-1, middle = (n-1)/2;
 
    while (high >= low)
    {
        if (values[middle] == value)
        {
            return true;
        }
        else 
        {
            if (values[middle] > value)
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }

            middle = (low + high)/2;
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
