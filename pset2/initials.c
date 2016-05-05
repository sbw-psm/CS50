#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    if (s[0] >= 97)
        s[0] -= 32;
    printf("%c", s[0]);
    for (int i=1, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (s[i+1] >= 97)
                s[i+1] -= 32;
            printf("%c", s[i+1]);
        }
    }
    printf("\n");
}