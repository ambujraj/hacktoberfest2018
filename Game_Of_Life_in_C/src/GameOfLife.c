#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "GameOfLife.h"

#define DISPLAY 1

/* 
 * rules of the game of life
 *  > less than two neighbours dies
 *  > two or three neighbours lives
 *  > three neighbours resuract a cell
 *  > more than 3 neighbours dies
 */

int main(int argc, char * argv[]) {
    FILE *initFile; 
    char *buffer = NULL;
    char *token;
    const char delim[2] = ",";
    char **strret;
    int x = 0, y = 0;
    size_t bufferLength;
    size_t read;
    size_t init = 0;
    long int iteration = 0;
    Cell current_generation[MATRIXSIZE][MATRIXSIZE];
    Cell future_generation[MATRIXSIZE][MATRIXSIZE];

    if (argc != 3){
        printf("Usage: Game File Num\n");
        printf("\n");
        printf("\tFile: file containing the initial state.\n");
        printf("\tNum: number of generation.\n");
        exit(1);
    }

    int len = strlen(argv[2]);
    char * argument;
    argument = malloc(sizeof(char)*len + 1);

    strcpy(argument, argv[2]);

    for (int i = 0;argument[i] != '\0'; i++)
    {
        if (!(isdigit(argument[i])))
        {
            printf("Wrong iteration number\n");
            exit(1);
        }
    }

    iteration = strtol(argument,strret,10);
    
    free(argument);

    if ((initFile=fopen(argv[1],"r")) == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    //get the initial state from a file
    while(getline(&buffer,&bufferLength,initFile) != -1){
        token = strtok(buffer,delim); 
        while (token != NULL){
            if (strcmp(token,"\n") != 0){
                if(strcmp(token,"0") == 0){
                    current_generation[x][y] = dead;
                    y++;
                }
                else if (strcmp(token,"1") == 0){
                    current_generation[x][y] = alive;
                    y++;
                }
                else
                {
                    printf("unknown string\n");
                    exit(1);
                }
            }
            token = strtok(NULL,delim); 
        }
        y = 0;
        x++;
    }

    if(DISPLAY) printLife(current_generation);
// game of life
    while (iteration > 0) {
        Live(current_generation,future_generation);

        for (int i = 0; i < MATRIXSIZE; i++)
        {
            for (int j = 0; j < MATRIXSIZE; j++)
            {
                current_generation[i][j] = future_generation[i][j];
            }
        }
    if(DISPLAY) printLife(future_generation);
    iteration--;
    }

    fclose(initFile);
}

void printLife(Cell cellp[MATRIXSIZE][MATRIXSIZE] ){
    for (int i = 0; i < MATRIXSIZE; i++)
    {
       for (int j = 0; j < MATRIXSIZE; j++)
       {
           if (cellp[i][j] == dead)
               printf(". ");
           else 
               printf("* ");
       }
     printf("\n" );
    }
     printf("\n" );
}

void Live(Cell current_generation[MATRIXSIZE][MATRIXSIZE], Cell future_generation[MATRIXSIZE][MATRIXSIZE])
{
    int neighbours = 0;

    for (int i = 0; i < MATRIXSIZE; i++)
    {
        for (int j = 0; j < MATRIXSIZE; j++)
        {
            if( i != 0 )
            {
                if (current_generation[i-1][j] == alive) neighbours++;
                if (j != MATRIXSIZE-1)
                {
                    if (current_generation[i-1][j+1] == alive) neighbours++;
                }
                if ( j != 0 )
                {
                    if (current_generation[i-1][j-1] == alive) neighbours++;

                }

            }

            if (j != 0)
            {
                if (current_generation[i][j-1] == alive) neighbours++;

                if (i != MATRIXSIZE-1)
                {
                    if (current_generation[i+1][j-1] == alive) neighbours++;
                }

            }

            if (i != MATRIXSIZE-1)
            {
                if (j != MATRIXSIZE-1)
                {
                    if (current_generation[i+1][j+1] == alive) neighbours++;
                }
                if (current_generation[i+1][j] == alive) neighbours++;
            }

            if (j != MATRIXSIZE-1)
            {
                if (current_generation[i][j+1] == alive) neighbours++;
            }
            
            //game rules
            if (neighbours < 2)
                future_generation[i][j] = dead;
            else if (neighbours == 2)
            {
                if (current_generation[i][j] == alive)
                    future_generation[i][j] = alive;
                else 
                    future_generation[i][j] = dead;
            } 
            else if (neighbours == 3)
                future_generation[i][j] = alive;
            else if (neighbours > 3)
                future_generation[i][j] = dead;

            neighbours = 0;
        }
    }
}
