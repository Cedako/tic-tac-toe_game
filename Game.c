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
    if(a[0]==a[1] && a[1]==a[2])
        return 1;
    else if(a[3]==a[4] && a[4]==a[5])
        return 1;
    else if(a[6]==a[7] && a[7]==a[8])
        return 1;
    else if(a[0]==a[3] && a[3]==a[6])
        return 1;
    else if(a[1]==a[4] && a[4]==a[7])
        return 1;
    else if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else if(a[0]==a[4] && a[4]==a[8])
        return 1;
    else if(a[2]==a[4] && a[4]==a[6])
        return 1;
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    else
        return -1;
}

//Main function
int main(){
    int sel,choice,score=-1,player=1;
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


        //players play the game until score changes to either 0 or 1 (0 = draw, 1 = win)
        if(player==1){
            printf("Player 1 type any digit from 1 to 9 to insert a %c\n=> ",x);
        } else {
            printf("Player 2 type any digit from 1 to 9 to insert a %c\n=> ",o);
        }
        scanf(" %d",&choice);
        symbol=((player==1)?x:o);

        if(choice==1 && a[0]=='1')
            a[0]=symbol;
        else if(choice==2 && a[1]=='2')
            a[1]=symbol;
        else if(choice==3 && a[2]=='3')
            a[2]=symbol;
        else if(choice==4 && a[3]=='4')
            a[3]=symbol;
        else if(choice==5 && a[4]=='5')
            a[4]=symbol;
        else if(choice==6 && a[5]=='6')
            a[5]=symbol;
        else if(choice==7 && a[6]=='7')
            a[6]=symbol;
        else if(choice==8 && a[7]=='8')
            a[7]=symbol;
        else if(choice==9 && a[8]=='9')
            a[8]=symbol;
        else {printf("Wrong Selection\n");player--;}

        score=checkWin();
        player++;
        board();
    } while (score == -1);

    if (score==1){
        switch (player)
        {
        case 2:
            printf("\n\nPlayer 1 wins\n\n");
            break;
        default:
            printf("\n\nPlayer 2 wins\n\n");
            break;
        }
    } else {
        printf("Its a draw!\n\n");
    }
    
    end:
    system("pause");
    return 0;
}