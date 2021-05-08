#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class TicTacToe {
private:
    unsigned char board[3][3];

public:
    TicTacToe() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    TicTacToe(unsigned char a[][3]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = a[i][j];
    }

    bool setCell(int i, int j, char value) {
        if (board[i][j] == ' ') {
            board[i][j] = value;
            return true;
        }
        return false;
    }

    char getCell(int i, int j) { return board[i][j]; }

    vector<TicTacToe> expand(char k) {
        vector<TicTacToe> children;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ') {
                    TicTacToe child = *this;
                    child.board[i][j] = k;
                    children.push_back(child);
                }
        return children;
    }

    string toString() {
        stringstream ot;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                ot << board[i][j] << ' ';
            ot << endl;
        }
        return ot.str();
    }

    int evaluate() {
        for (int i = 0; i < 3; i++) //check for rows
        {
            bool same = true;
            for (int j = 1; j < 3; j++)
                if (board[i][j] == ' ' || board[i][j] != board[i][j - 1]) {
                    same = false;
                    break;
                }
            if (same) {
                return board[i][0] == 'X' ? 1 : -1;
            }
        }

        for (int j = 0; j < 3; j++) //check for columns
        {
            bool same = true;
            for (int i = 1; i < 3; i++)
                if (board[i][j] == ' ' || board[i][j] != board[i - 1][j]) {
                    same = false;
                    break;
                }
            if (same) {
                return board[0][j] == 'X' ? 1 : -1;
            }
        }
        bool same = true;
        for (int i = 1; i < 3; i++)
            if (board[i][i] == ' ' || board[i][i] != board[i - 1][i - 1]) {
                same = false;
                break;
            }
        if (same)
            return board[0][0] == 'X' ? 1 : -1;

        same = true;
        for (int i = 1; i < 3; i++)
            if (board[i][2 - i] == ' ' || board[i][2 - i] != board[i - 1][2 - (i - 1)]) {
                same = false;
                break;
            }
        if (same)
            return board[1][1] == 'X' ? 1 : -1;


        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return -100; //undefined

        return 0;
    }

    static int minimax(TicTacToe s, int depth, bool isMax, TicTacToe &best) {
        int k = s.evaluate();

        if (depth == 0 || k != -100) {
            best = s;
//        cout<<"returning "<<k<<endl;
            return k;
        }

        int max, temp;
        TicTacToe maxState, tempState;

        vector<TicTacToe> children = s.expand(isMax ? 'X' : 'O');

        max = minimax(children[0], depth - 1, !isMax, maxState);
        maxState = children[0];


        for (int i = 1; i < children.size(); i++) {
            temp = minimax(children[i], depth - 1, !isMax, tempState);
            if ((temp > max) == isMax) {
                max = temp;
                maxState = children[i];
            }
        }
        best = maxState;
        return max;
    }

    static void play() {
        TicTacToe s, b;

        int x, y, v, exp;

        bool result;

        do {
            exp = minimax(s, 10, true, b);
            s = b;
            cout << s.toString() << endl;
            v = s.evaluate();
            if (v == -100) {
                do {
                    cout << "Give x and y of your move:";
                    if (exp == 1)
                        cout << " (looser)";
                    cin >> x >> y;
                    result = s.setCell(x, y, 'O');
                } while (!result);

                v = s.evaluate();
            }
        } while (v == -100);

        switch (v) {
            case 0:
                cout << "Tie" << endl;
                break;

            case 1:
                cout << "You lose" << endl;
                break;
            case -1:
                cout << "You win" << endl;
                break;
        }
    }

};


#endif //TIC_TAC_TOE_H
