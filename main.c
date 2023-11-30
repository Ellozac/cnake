#include <stdio.h>
#include <time.h>
#include <termios.h>
#include <stdlib.h>

int main() { 
    // characters used to display the snake and apple and border
    char snakeHead = '0';
    char snakeBody = 'o';
    char apple = 'a';
    char arenaBorder = '*';
    // defining width/height of the arena with index 0 as the width and index 1 as the height
    int arena[2];
    arena[0] = 16;
    arena[1] = 16;
    
    int snakePosX, snakePosY
    snakePosX = arena[0] / 2;
    snakePosY = arena[1] / 2;

    int gameState = 1;
    while (gameState) {
        // Clear Terminal
        system("clear");
        for (int i = 0; i < arena[0]; i++) {
            // prints 1 asterix
            printf("%c", arenaBorder);
        }
        for (int i = 0; i < arena[1]; i++) {
            prtinf("\n")
            if (snakePosY == i) {
                
            }
        }
        gameState = 0;
    }

    return 0;
}
