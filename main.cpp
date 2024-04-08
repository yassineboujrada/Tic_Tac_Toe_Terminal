#include <iostream>
#include <string>
#include "matrice.cpp"
#include <random>

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

string checkWinner(const matrice& m) {
    string winnerPlayer = " ";
    for (int i = 0; i < 3; ++i) {
        if (m.getValue(i,0) == m.getValue(i,1) && m.getValue(i,1) == m.getValue(i,2) && m.getValue(i,0) != " ") {
            winnerPlayer = m.getValue(i,0);
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (m.getValue(0,i) == m.getValue(1,i) && m.getValue(1,i) == m.getValue(2,i) && m.getValue(0,i) != " ") {
            winnerPlayer = m.getValue(0,i);
        }
    }

    if (m.getValue(0,0) == m.getValue(1,1) && m.getValue(1,1) == m.getValue(2,2) && m.getValue(0,0) != " ") {
        winnerPlayer = m.getValue(0,0);
    }

    if (m.getValue(0,2) == m.getValue(1,1) && m.getValue(1,1) == m.getValue(2,0) && m.getValue(0,2) != " ") {
        winnerPlayer = m.getValue(0,2);
    }

    if (winnerPlayer != " ") {
        return  winnerPlayer;
    }
    return " ";
}

int main() {
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1);

    const string Xplay = "X";
    const string Oplay = "O";
    string winnerPlayer = " ";

    int row = -1;
    int col = -1;

    string Currentplayer =  (distribution(gen) == 0) ? Xplay : Oplay;
    
    matrice game_board(3,3," ");

    for(int i=0;i<9;i++){
        
        cout<<"##########   Player "<<Currentplayer<<" turn \U0001F642   ##########"<<endl;

        printTabla(game_board);

        if (winnerPlayer != " ") {
            break;
        }

        while(true){
            cout<<"#### Enter row and col from 0 to 2 : ";
            cin>>row>>col;

            if(row < 0 || row > 2 || col < 0 || col > 2){
                cout<<"Invalid input"<<endl;
            }
            else if (game_board.getValue(row,col) != " "){
                cout<<"Invalid position"<<endl;
            }
            else{
                break;
            }
            row--;
            col--;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        game_board.setValue(row,col,Currentplayer);
        Currentplayer = (Currentplayer == Xplay) ? Oplay : Xplay;

        winnerPlayer = checkWinner(game_board);
        
    }
    if (winnerPlayer != " ") {
        cout << "Player " << winnerPlayer << " wins ! \U0001F4AA" << endl;
    } else {
        cout << "It's a draw ! \U0001F612" << endl;
    }

    return 0;
}
