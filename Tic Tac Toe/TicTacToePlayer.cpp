//#include <iostream>
//#include <vector>
//#include <sstream>
//
//#include "TicTacToe.h"
//
//using namespace std;
//
//
//int minimax(TicTacToe s, int depth, bool isMax, TicTacToe &best) {
//    int k = s.evaluate();
//
//    if (depth == 0 || k != -100) {
//        best = s;
////        cout<<"returning "<<k<<endl;
//        return k;
//    }
//
//    int max, temp;
//    TicTacToe maxState, tempState;
//
//    vector<TicTacToe> children = s.expand(isMax ? 'X' : 'O');
//
//    max = minimax(children[0], depth - 1, !isMax, maxState);
//    maxState = children[0];
//
//
//    for (int i = 1; i < children.size(); i++) {
//        temp = minimax(children[i], depth - 1, !isMax, tempState);
//        if ((temp > max) == isMax) {
//            max = temp;
//            maxState = children[i];
//        }
//    }
//    best = maxState;
//    return max;
//}
//
//
//int main() {
//    TicTacToe s, b;
//
//    int x, y, v, exp;
//
//    bool result;
//
//    do {
//        exp = minimax(s, 10, true, b);
//        s = b;
//        cout << s.toString() << endl;
//        v = s.evaluate();
//        if (v == -100) {
//            do {
//                cout << "Give x and y of your move:";
//                if (exp == 1)
//                    cout << " (looser)";
//                cin >> x >> y;
//                result = s.setCell(x, y, 'O');
//            } while (!result);
//
//            v = s.evaluate();
//        }
//    } while (v == -100);
//
//    switch (v) {
//        case 0:
//            cout << "Tie" << endl;
//            break;
//
//        case 1:
//            cout << "You lose" << endl;
//            break;
//        case -1:
//            cout << "You win" << endl;
//            break;
//    }
//
//
//    return 0;
//}
//
