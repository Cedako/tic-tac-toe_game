#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Array that contains the board
char a[9] = {'1','2','3','4','5','6','7','8','9'};

//Stores symbol for each player
char x,o;

//Function that displays the board
void board(){
    system("cls");
    printf("Player 1 is %c\nPlayer 2 is %c\n\n",x,o);
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

//Function that stores symbols for each player
void selectSymbol(){
    system("cls");
    char dec;
    deci:
    printf("Player 1 select X or O => "); dec=getchar(); scanf(" %c",&dec);
    {
        if(dec=='X'||dec=='x'){
            x='X';
            o='O';
        } else if (dec=='O'||dec=='o'||dec=='0'){
            x='O';
            o='X';
        } else {
            printf("Please, enter either X or O only \n\n");
            goto deci;
        }
    }
}

//Function that checks win condition
int checkWin(){
    
}

//Main function
int main(){
    int sel,score=-1,player=1;
    char symbol;
    system("cls");
    printf("\t\t ¡Welcome to tic tac toe! \n\n");
    rules();
    printf("press 1 to play the game\n==> "); scanf(" %d",&sel);
    if (sel!=1){
        printf("Next time enter 1, see you soon.\n");
        goto end;
    }

    
    selectSymbol();
    system("color fc");
    board();


    do{
        player=((player%2)?1:2);
        symbol=((player==1)?x:o);

        score=checkWin();
        player++;
        board();
    } while (score == -1);
    
    end:
    system("pause");
    return 0;
}