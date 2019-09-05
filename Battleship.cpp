#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

int main() {
    vector<int> board(3,0);
    vector<vector<int>> matrix(3, board);
    int shipX;
    int shipY;
    int guessX;
    int guessY;
    int i;
    int j;
    int guesses;

    srand(time(0));
    for(i = 0; i < 2; i++ ) {
        shipX = rand() % 3 + 0;
        shipY = rand() % 3 + 0;
        matrix.at(shipX).at(shipY) = 1;
    }


    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout<<  " " << "!" ;
        }
        cout << endl;
        cout << "-------" << endl;
    }



    /*
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout<< "Matrix[" << i << "][" << j << "]=" << matrix.at(i).at(j) << endl;
        }
    }
    */

    for(guesses = 0; guesses < 8; guesses++){
        cout << "Guess your x value between 1 and 3!" << endl;
        cin >> guessX;
        cout << "Guess your y value between 1 and 3!" << endl;
        cin >> guessY;

        cout << "Location X-Y = " << guessX << "-" << guessY<< endl;



        if( matrix.at(guessX - 1 ).at(guessY - 1) == 1){
            cout << "You sunk my battleship! (" << guesses + 1 << " guesses!)" << endl;
            break;
        }
        else{
            cout << "Miss!" << endl;
        }
    }

    return 0;
}