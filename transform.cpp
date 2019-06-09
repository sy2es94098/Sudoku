#include"sudoku.h"
#include<iostream>
using namespace std;
int main() {
    // finish your transform code...
    int initMap[Sudoku::sudokuSize], type, x, y;
    for( int i = 0; i < Sudoku::sudokuSize ; i++) {
        cin >> initMap[i];
    }

    Sudoku su(initMap);
    su.setData();
    for(;;) {
        cin >> type;
        switch(type) {
        case 0 :
            su.printMap(1);
            break;
        case 1 :
            cin >> x >> y;
            su.swapNum(x,y);
            break;
        case 2 :
            cin >> x >> y;
            su.swapRow(x,y);
            break;
        case 3:
            cin >> x >> y;
            su.swapCol(x,y);
            break;
        case 4:
            cin >> x;
            su.rotate(x);
            break;
        case 5:
            cin >> x;
            su.flip(x);
            break;
        }
        if(type == 0)
            return 0;
    }
}
