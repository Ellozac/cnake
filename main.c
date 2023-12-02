#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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


    // characters used to display the snake and apple and border
    char snakeHead = '0';
    char snakeBody = 'o';
    char apple = 'a';
    char arenaBorder = '*';
    // defining width/height of the arena with index 0 as the width and index 1 as the height
    int arena[2];
    arena[0] = 56;
    arena[1] = 16;

    int length = 1;
    int* snakePosX = (int *)malloc(sizeof(int) * length);
    int* snakePosY = (int *)malloc(sizeof(int) * length);
    
    snakePosX[0] = arena[0] / 2;
    snakePosY[0] = arena[1] / 2;



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
            for (int k = 0; k < arena[0]; k++) {

                if (k == 0 || k == arena[0] - 1) 
                {
                    printf("%c", arenaBorder);
                }
                else {
                    printf(" ");
                }
            }
            
        }
        printf("\n");
        for (int i = 0; i < arena[0]; i++) {
            // prints 1 asterix
            printf("%c", arenaBorder);
        }
        gameState = 0;
    }

    return 0;
}
