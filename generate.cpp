#include<iostream>
#include"sudoku.h"
int main() {
    // finish your generate code...
    Sudoku su;
    su.setData();
    su.generate();
    su.printMap(1);
    return 0;
}
