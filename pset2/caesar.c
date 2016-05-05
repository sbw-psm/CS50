#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc > 2)
    {   
        printf("Too many command-line arguments\n");
        return 1;
    }
    else if (argc < 2)
    {
        printf("Too few command-line arguments\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string s = GetString();
        for (int i = 0, n = strlen(s); i< n; i++)
        {
            if (isalpha(s[i]))
            {
                // encipher lowercase letters
                if (islower(s[i]))
                {
                    int letter = s[i];
                    letter -= 97;
                    letter = (letter + key) % 26;
                    letter += 97;
                    printf("%c", letter);
                }
                // encipher uppercase letters
                else
                {
                    int letter = s[i];
                    letter -= 65;
                    letter = (letter + key) % 26;
                    letter += 65;
                    printf("%c", letter);
                }
            }
            else 
                printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
