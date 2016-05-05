#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float amountOwed;
    printf("O hai! How much change is owed?\n");
    amountOwed = GetFloat();
    while (amountOwed < 0.0)
    {
        printf("How much change is owed?\n");
        amountOwed = GetFloat();
    }
    amountOwed = round(amountOwed*100);
    
    int noCoins = 0;
    while (amountOwed >= 25)
    {
        amountOwed -= 25;
        noCoins++;
    }
    
    while (amountOwed >= 10)
    {
        amountOwed -= 10;
        noCoins++;
    }
    
    while (amountOwed >= 5)
    {
        amountOwed -= 5;
        noCoins++;
    }
    
    while (amountOwed > 0)
    {
        amountOwed -= 1;
        noCoins++;
    }
    
    printf("%d\n", noCoins);
}
