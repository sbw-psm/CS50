#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
        // check for alphanumeric characters
        for (int i = 0, n = strlen(argv[1]); i<n; i++)
        {   
            if (isdigit(argv[1][i]))
            {
                printf("Command-line argument can contain only alphabetical characters\n");
                return 1;
            }
        }
        
        string s = GetString();
        string key = argv[1];
        int keyLength = strlen(key);
        for (int i = 0, j = 0, n = strlen(s); i < n; i++)
        {
            if (isalpha(s[i]))
            {
                // determine the appropriate shift
                int k = key[j];
                if (islower(k))
                {
                    k -= 97;
                }
                else 
                {
                    k -= 65;
                }
                // encipher for lowercase letters
                if (islower(s[i]))
                {
                    int letter = s[i];
                    letter -= 97;
                    letter = (letter + k) % 26;
                    letter += 97;
                    printf("%c", letter);
                    j++;
                    j %= keyLength;
                }
                // encipher for uppercase letters
                else
                {
                    int letter = s[i];
                    letter -= 65;
                    letter = (letter + k) % 26;
                    letter += 65;
                    printf("%c", letter);
                    j++;
                    j %= keyLength;
                }
            }
            else
                printf("%c", s[i]);
        }
        printf("\n");
    }
}