/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// location of empty space in matrix (indexed 0)
int spaceR, spaceC;

// location of tile in matrix (indexed 0)
int tileR, tileC;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
bool search(int tile, int board[DIM_MAX][DIM_MAX], int n);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // initializing the board   
    for (int i = 0, n = (d*d)-1; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = n;
            n--;
        }
    }
    board[d-1][d-1] = 0;
    spaceR = d-1;
    spaceC = d-1;
    // if number of tiles are odd then swap tiles 1 and 2
    if ((d^2-1)%2 != 0)
    {
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j=0; j < d; j++)
        {
            if (board[i][j] == 0)
                printf(" _");
            else
                printf("%2i", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    if (search(tile, board, d))
    {
        if ( (((spaceR+1) == tileR) && (spaceC == tileC)) ||\
             ((spaceR == tileR) && ((spaceC-1) == tileC)) ||\
             (((spaceR-1) == tileR) && (spaceC == tileC)) ||\
             ((spaceR == tileR) && ((spaceC+1) == tileC)) \
            )
        {
            
                // swap the space and tile values
                board[spaceR][spaceC] = board[tileR][tileC];
                board[tileR][tileC] = 0; // assigning empty space
                
                // set new space location
                spaceR = tileR;
                spaceC = tileC;
                return true;
            
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // check if the empty space is at the bottom-right corner
    if (board[d-1][d-1] == 0)
    {
        // check if the board’s tiles are arranged from smallest to largest,
        // left to right, top to bottom
        for (int i = 0, n = 1; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] != n)
                {
                    return false;
                }
                n++;
            }
        }
        return true;
    }
    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int tile, int board[DIM_MAX][DIM_MAX], int n)
{
    // implementation of linear search algorithm
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == tile)
            {
                   tileR = i;
                   tileC = j;
                   return true;
            }
        }
    }
    return false;
}