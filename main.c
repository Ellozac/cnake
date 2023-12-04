#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
int main() { 
    // Check OS running the program
    // os 1 is linux, 2 is windows
    int os;
    #ifdef __linux__
        printf("LinuxOS\n");
        #include <termios.h>
        os = 1;
    #elif _WIN64 || _WIN32
        printf("windowsOS\n");
        os = 2;
    #endif

    bool bodyCheck = false;
    // characters/assets used to display the snake and apple and border
    char snakeHead = '0';
    char snakeBody = 'o';
    char apple = 'a';
    char arenaBorder = '*';
    // defining width/height of the arena with index 0 as the width and index 1 as the height
    int arena[2];
    arena[0] = 56;
    arena[1] = 16;
    // initial length of snake
    int length = 7;
    // dynamic memory allocation for snake position x and y in Heap
    int* snakePosX = (int *)malloc(sizeof(int) * length);
    int* snakePosY = (int *)malloc(sizeof(int) * length);
    

    // set snake position to center of screen for start of game
    snakePosX[0] = arena[0] / 2;
    snakePosY[0] = arena[1] / 2;

    // starting the game, Whilst gameState is 1 the game is running if 0 game stops 
    int gameState = 1;
    while (gameState) {
        // Clear Terminal based on OS 
        if (os == 1)
        {
            system("clear");
        } 
        else if (os == 2) 
        {
            system("cls");
        } 
        else 
        {
            printf("error detecting OS");
            return 0;
        }
        
        
        // prints out to the user the game
        for (int i = 0; i < arena[0]; i++) {
            // prints 1 asterix
            printf("%c", arenaBorder);
        }
        for (int i = 0; i < arena[1]; i++) {
            printf("\n");
            bodyCheck = false; 
            for (int k = 0; k < arena[0]; k++) {
                // logic for what character to output to console
                if (snakePosX[0] == k && snakePosY[0] == i) {
                    printf("%c", snakeHead);
                    continue;
                };
                for (int j = 1; j <= length; j++) if (snakePosX[j] == i && snakePosY[j] == k) {
                    printf("%c", snakeBody);
                    bodyCheck = true;
                    break;
                }
                if (bodyCheck) continue;
                else if (k == 0 || k == arena[0] - 1) printf("%c", arenaBorder);
                else printf(" ");
            }
            
        }
        printf("\n");
        for (int i = 0; i < arena[0]; i++) {
            // prints 1 asterix
            printf("%c", arenaBorder);
        }
        gameState = 0;
    }

    free(snakePosX);
    free(snakePosY);
    return 0;
}
