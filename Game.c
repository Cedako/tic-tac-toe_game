#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Array that contains the board
char a[9] = {'1','2','3','4','5','6','7','8','9'};

//Function that displays the board
void board(){
    system("cls");
    printf(" %c| %c| %c\n",a[0],a[1],a[2]);
    printf("--+--+--\n");
    printf(" %c| %c| %c\n",a[3],a[4],a[5]);
    printf("--+--+--\n");
    printf(" %c| %c| %c\n",a[6],a[7],a[8]);
    printf("--+--+--\n");
}

//Function that displays the rules of the game
void rules(){
    printf("\t\tTic Tac Toe\n\n");
    printf("Rules:\n");
    printf("\n 1°- Each player enters a number in which the symbol will be placed.");
    printf("\n 2°- When a player connects 3 symbols in a row, column or diagonal, it wins and the game ends.");
    printf("\n 3°- Have fun.");
}

//Main function
int main(){
    int sel;
    printf("\t\t ¡Welcome to tic tac toe! \n\n");
    printf("press 1 to play the game\n==> "); scanf(" %d",&sel);
    board();
    return 0;
}