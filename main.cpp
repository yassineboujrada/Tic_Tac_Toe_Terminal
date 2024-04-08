#include <iostream>
#include <string>
#include "matrice.cpp"

using namespace std;

void printTabla(const matrice& m) {
    cout << "   |   |   " << endl;
    cout << " " << m.getValue(0,0) << " | " << m.getValue(0,1) << " | " << m.getValue(0,2) << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << m.getValue(1,0) << " | " << m.getValue(1,1) << " | " << m.getValue(1,2) << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << m.getValue(2,0) << " | " << m.getValue(2,1) << " | " << m.getValue(2,2) << endl;
    cout << "   |   |   " << endl;
}

int main() {
    
    matrice game_board(3,3," ");

    printTabla(game_board);

    return 0;
}