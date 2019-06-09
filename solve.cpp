#include<iostream>
#include<fstream>
#include"sudoku.h"
#include<cstdlib>
using namespace std;
int main() {
    // finish your solve code...
    int initMap[Sudoku::sudokuSize];
    for( int i = 0; i < Sudoku::sudokuSize ; i++) {
        cin >> initMap[i];
    }
    Sudoku su(initMap);
    su.solve();
    return 0;
}
