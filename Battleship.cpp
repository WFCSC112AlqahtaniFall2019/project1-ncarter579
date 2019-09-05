#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

int main() {
    vector<int> board(2,2);
    int shipX;
    int shipY;
    int guessX;
    int guessY;

    srand(time(0));
    shipX = rand()% 3 + 0;
    shipY = rand()% 3 + 0;

    cout << shipX;
    cout << shipY;
    return 0;
}