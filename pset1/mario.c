/*
 * Code Author: Shivam B. Waghela
 * The Output of this code exactly matches cs50's staff solution: ~cs50/pset1/mario
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        n = GetInt();
    }while (n>23 || n<0);
    
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n-1; j++) 
            printf(" ");
            
        for (int k=0; k<2+i; k++)
            printf("#");
        
        printf("\n");
    }
}
