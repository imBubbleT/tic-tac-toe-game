#include <iostream>
#include <string>
using namespace std;


//Its char instead of int because mark will be a char 'X' or 'O'
//0 will not be used but make coding the grid easier and less confusing
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int checkwin();
void board();
string player1, player2; //player1 and 2 is here so I can use it in the board funcion

int main()
{
    int player = 1, i, choice;
    char mark;
    string currentPlayer;

    board();
    cout << "Player 1 (X), enter your name: ";
    getline(cin, player1);

    board();
    cout << "Player 2 (O), enter your name: ";
    getline(cin, player2);

    do{
        board();
        player = (player%2)? 1 : 2;//short for if else statment (condition)? true: false
        currentPlayer = (player == 1)? player1: player2;

        //Players move
        cout << currentPlayer <<", enter a number: ";
        cin >> choice;

        mark = (player == 1)? 'X' : 'O';

        //Checks if the selected grid position is not marked yet and lets the selected player mark it if unoccupied
        if (choice == 1 && square[1] == '1'){
            square[1] = mark;
        }
        else if(choice == 2 && square[2] == '2'){
            square[2] = mark;
        }
        else if(choice == 3 && square [3] == '3'){
            square [3] = mark;
        }
        else if(choice == 4 && square [4] == '4'){
            square [4] = mark;
        }
        else if(choice == 5 && square [5] == '5'){
            square [5] = mark;
        }
        else if(choice == 6 && square [6] == '6'){
            square [6] = mark;
        }
        else if(choice == 7 && square [7] == '7'){
            square [7] = mark;
        }
        else if(choice == 8 && square [8] == '8'){
            square [8] = mark;
        }
        else if(choice == 9 && square [9] == '9'){
            square [9] = mark;
        }
        else{
            cout << "Invalid move ";

            player-- ;
            cin.ignore(); // I dont understand cin.ignore() and cin.get()
            cin.get();
        }
        i = checkwin();

        player++;
    }
    while(i==-1);
    board();

    if(i == 1){
        player --;
        cout << "-->\a"<< currentPlayer << " wins! ";
    }else{
        cout << "-->\aGame draw!";

        cin.ignore();
        cin.get();
    }
    return 0;
}


/******************
function to return game status
1 = game over with result
-1 = game in progress
0 = game over as a draw
******************/
int checkwin()
{
    if(square[1] == square[2] && square[2] == square[3]){
        return 1;
    }
    else if(square[4] == square[5] && square[5] == square[6]){
        return 1;
    }
    else if(square[7] == square[8] && square[8] == square[9]){
        return 1;
    }
    else if(square[1] == square[4] && square[4] == square[7]){
        return 1;
    }
    else if(square[2] == square[5] && square[5] == square[8]){
        return 1;
    }
    else if(square[3] == square[6] && square[6] == square[9]){
        return 1;
    }
    else if(square[1] == square[5] && square[5] == square[9]){
        return 1;
    }
    else if(square[3] == square[5] && square[5] == square[7]){
        return 1;
    }
    // Game draw
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3'
            && square[4] != '4' && square[5] != '5' && square[6] != '6'
            && square[7] != '7' && square[8] != '8' && square[9] != '9'){
        return 0;
    // Game in progress
    }else{
        return -1;
    }
}


/**************
funtion to draw tic tac toe board with marks
**************/

void board()
{
    system("cls"); //this clears the screen
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << player1 << "(X) - " << player2 << "(0)\n\n\n";

    cout << "     |     |     \n";
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";

    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "     |     |     \n\n";
}
