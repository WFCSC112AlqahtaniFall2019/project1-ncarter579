#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

int main() {
    vector<int> board(3,0);
    vector<vector<int>> matrix(3, board);  //setting up a vector board that will store which tiles the ships are randomly placed on

    vector<string> coutBoard(3,"0");
    vector<vector<string>> printMatrix(3, coutBoard); //setting up an additional vector board to print out to the user after every turn

    int shipX; //x coordinate used in placing the random ships
    int shipY;  //y coordinate used in placing the random ships
    int guessX; //x coordinate used when the player guesses a random location
    int guessY;  //y coordinate used when the player guesses a random location
    int i;  //variable used for iterating through for loops
    int j;   //variable used for iterating through for loops
    int guesses;  //variable to keep track of how many guesses the player makes before guessing correctly

    srand(time(0));  //makes it so the random number generator give a new number each time they run

    for(i = 0; i < 2; i++ ) {  //for loop that iterates twice and places the two random ships on the board
        shipX = rand() % 3 + 0;  //random x coordinate of the ship
        shipY = rand() % 3 + 0;  //random y coordinate of the ship
        matrix.at(shipX).at(shipY) = 1;  //sets the location of the ship equal to 1 so that we can check and see if the player hit the ship later
    }

    for(guesses = 0; guesses < 100; guesses++){   //this is a big for loop that will continue to iterate until the player guesses correctly
        cout << "Guess your x value between 1 and 3!" << endl;
        cin >> guessX;      //getting a value for the players x coordinate guess
        cout << "Guess your y value between 1 and 3!" << endl;
        cin >> guessY;      //getting a value for the players y coordinate guess

        cout << "Location X-Y = " << guessX << "-" << guessY<< endl;  //printing out the players guess for them

        if( matrix.at(guessX - 1 ).at(guessY - 1) == 1){ //checking to see if the players guess is a hit (equal to 1 in the matrix vector)
            cout << "You sunk my battleship! (" << guesses + 1 << " guesses!)" << endl;  //printing out the players guesses
            printMatrix.at(guessX - 1 ).at(guessY - 1) = "X"; //changing the value in the printMatrix vector to display that the player hit the battleship

            for(i = 0; i < 3; i++){  //a for loop that prints out the updated board
                cout << "!";
                for(j = 0; j < 3; j++){
                    cout <<  printMatrix.at(i).at(j) << "!" ;
                }
                cout << endl;
                cout << "-------" << endl;
            }
            break;  //breaks out of the for loop and ends the program because the player won
        }
        else{  //if the players guess was incorrect this will happen
            cout << "Miss!" << endl;
            printMatrix.at(guessX - 1 ).at(guessY - 1) = "O"; //changing the value in the printMatrix vector to display that the player missed the battleship

            for(i = 0; i < 3; i++){ //a for loop that prints out the updated board
                cout << "!";
                for(j = 0; j < 3; j++){
                    cout <<  printMatrix.at(i).at(j) << "!" ;
                }
                cout << endl;
                cout << "-------" << endl;
            }
        }
    }  //if the player guesses incorrectly, this loop will iterate forever until they manage to hit a battleship

    return 0;
}