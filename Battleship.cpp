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

    srand(time(0));
    for(i = 0; i < 2; i++ ) {
        shipX = rand() % 3 + 0;
        shipY = rand() % 3 + 0;
        matrix.at(shipX).at(shipY) = 1;
    }

    return 0;
}