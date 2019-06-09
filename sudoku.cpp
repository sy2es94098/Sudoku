#include"sudoku.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int lastNum[Sudoku::sudokuSize] = {0} ;
int lastLocation = 0;

Sudoku::Sudoku() {
    for(int i = 0; i < sudokuSize; ++i)
        map[i] = 0;
}

Sudoku::Sudoku(const int init_map[]) {
    for(int i = 0; i < sudokuSize; ++i)
        map[i] = init_map[i];
}

int Sudoku::solve() {
    int sol = 0;
    setData();
    sol = repeatTest();
    if(sol == 0 )
        cout << '0' << endl;
    else {
        sol = tryAnswer();
        if(sol == 0)
            cout << '0' << endl;
        else {
            if(sol >= 2)
                cout << '2' << endl;
            else {
                cout << 1 << endl;
                printMap(2);
            }
        }
    }
}

void Sudoku::swapNum(int x, int y) {
    for(int i = 0 ; i < sudokuSize ; ++i) {
        if(map[i] == x)
            map[i] = y;
        else {
            if(map[i] == y)
                map[i] = x;
        }
    }
}

void Sudoku::swapRow(int x, int y) {
    x = x*27;
    y = y*27;
    int tmp, X, Y;
    for(int i = 0; i < 3 ; ++i) {
        for(int j = 0 ; j < 9 ; ++j) {
            X = x + i * 9 + nextRow[j];
            Y = y + i * 9 + nextRow[j];
            tmp = map[X];
            map[X] = map[Y];
            map[Y] = tmp;
        }
    }
}

void Sudoku::swapCol(int x, int y) {
    x = x*3;
    y = y*3;
    int tmp, X, Y;
    for(int i = 0; i < 3 ; ++i) {
        for(int j = 0 ; j < 9 ; ++j) {
            X = x + i + nextColumn[j];
            Y = y + i + nextColumn[j];
            tmp = map[X];
            map[X] = map[Y];
            map[Y] = tmp;
        }
    }
}

void Sudoku::rotate(int x) {
    int tmp;
    for(int c = 0 ; c < x ; ++c) {
        for(int i = 0 ; i < 9 ; ++i) {
            for(int j = 0 ; j < 9 ; ++j) {
                map2[8-i+nextColumn[j]] = map[i*9 + j];
            }
        }
        for(int k = 0 ; k < sudokuSize ; ++k)
            map[k] = map2[k];
    }
}

void Sudoku::flip(int x) {
    int tmp;
    if(x == 1) {
        int left, right;
        for(int i = 0 ; i < 4 ; ++i) {
            for(int j = 0 ; j < 9 ; ++j) {
                left = i+nextColumn[j];
                right = (8 - i ) + nextColumn[j];
                tmp = map[left];
                map[left] = map[right];
                map[right] = tmp;
            }
        }
    }
    if(x == 0) {
        int up, down;
        for(int i = 0 ; i < 4 ; ++i) {
            for(int j = 0 ; j < 9 ; ++j) {
                up = i*9 + nextRow[j];
                down = (8-i)*9 + nextRow[j];
                tmp = map[up];
                map[up] = map[down];
                map[down] = tmp;
            }
        }
    }
}

void Sudoku::generate() {
    srand(time(NULL));
    int rnd, rndx, rndy;
    int init_map[sudokuSize] = {3, 1, 5, 9, 8, 6, 7, 2, 4, 6, 2, 9, 4, 5, 7, 1, 8, 3, 7, 4, 8, 3, 2, 1, 9, 6, 5, 5, 9, 4, 8, 3, 2, 6, 1, 7, 8, 7, 2, 6, 1, 4, 3, 5, 9, 1, 6, 3, 5, 7, 9, 8, 4, 2, 2, 3, 7, 1, 6, 5, 4, 9, 8, 9, 8, 1, 2, 4, 3, 5, 7, 6, 4, 5, 6, 7, 9, 8, 2, 3, 1};

    for(int i = 0 ; i < sudokuSize ; ++i) {
        map[i] = init_map[i];
    }
    for(int i = 0 ; i < 1000 ; ++i) {
        rnd = (rand()%5) + 1;
        if(rnd == 1 ) {
            rndx = (rand()%9) + 1;
            rndy = (rand()%9) + 1;
            swapNum(rndx, rndy);
        }
        if(rnd == 2 ) {
            rndx = (rand()%3);
            rndy = (rand()%3);
            swapRow(rndx, rndy);
        }
        if(rnd == 3 ) {
            rndx = (rand()%3);
            rndy = (rand()%3);
            swapCol(rndx, rndy);
        }
        if(rnd == 4 ) {
            rndx = (rand()%4)+1;
            rotate(rndx);
        }
        if(rnd == 5 ) {
            rndx = rand()%2;
            flip(rndx);
        }
    }
    for(int i = 0 ; i < 64 ; ++i) {
        rnd = rand()%81;
        map[rnd] = 0 ;
    }
}

void Sudoku::setData() {
    for(int i = 0; i < sudokuSize; ++i) {
        startRow[i] = i / 9 * 9;
        startColumn[i] = i % 9 ;
        startCell[i] = ((i/9)/3)*27 + ((i%9)/3)*3;
    }
    for(int i = 0; i < 9; ++i) {
        nextRow[i] = i;
        nextColumn[i] = i * 9;
        nextCell[i] = (i/3)*9 + (i%3);
    }
}

void Sudoku::printMap( int num) {
    if( num == 1) {
        for( int i = 0 ; i < sudokuSize ; ++i) {
            cout << map[i];
            if(i % 9 == 8 )
                cout << endl;
            else
                cout << ' ';
        }
    }
    if( num == 2) {
        for( int i = 0 ; i < sudokuSize ; ++i) {
            cout << map2[i];
            if(i % 9 == 8 )
                cout << endl;
            else
                cout << ' ';
        }
    }

}

int Sudoku::getBlank(int tmp) {
    do
        ++tmp;
    while(tmp < sudokuSize && map[tmp] > 0);
    return tmp;
}

int Sudoku::getNotBlank(int tmp) {
    do
        ++tmp;
    while(tmp < sudokuSize && map[tmp] == 0);
    return tmp;
}

int Sudoku::repeatTest() {
    int now = getNotBlank(-1);
    do {
        if( (answerCheck(now, startRow[now], nextRow) == 0) &&(answerCheck(now, startColumn[now], nextColumn) == 0) &&(answerCheck(now, startCell[now], nextCell) == 0)) {
            now = getNotBlank(now);
        } else
            return 0;
    } while(now < sudokuSize);
}

int Sudoku::tryAnswer() {
    int now = getBlank(-1);
    int sol = 0 ;
    do {
        ++map[now];
        if(map[now] > 9) {
            map[now] = 0;
            now = getLast();
        } else {
            if( (answerCheck(now, startRow[now], nextRow) == 0) &&(answerCheck(now, startColumn[now], nextColumn) == 0) &&(answerCheck(now, startCell[now], nextCell) == 0)) {
                recordNow(now);
                now = getBlank(now);
            }
        }

        if(now >= sudokuSize) {
            if(solveTest() == 1)
                return sol;
            ++sol;
            for(int i = 0; i < sudokuSize ; ++i)
                map2[i] = map[i];
            --lastLocation;
            now = lastNum[lastLocation];
        }

    } while( now >= 0 && sol < 2 );
    return sol;
}

bool Sudoku::solveTest() {
    int repeat = 0 ;
    for( int i = 0 ; i < sudokuSize; ++i) {
        if(map[i] == map2[i]) {
            ++repeat;
        }
    }
    if(repeat == 81)
        return 1;
    else
        return 0;
}

int Sudoku::getLast() {
    if(lastLocation <= 0)
        return(-1);
    else {
        return(lastNum[--lastLocation]);
    }
}

int Sudoku::recordNow(int now) {
    lastNum[lastLocation++] = now;
}

int Sudoku::answerCheck( int now, int start, int next[] ) {
    int here, repeat = 0;
    for(int i = 0 ; i < 9 ; ++i) {
        here = start + next[i];
        if((here != now) && (map[here] == map[now])) {
            ++repeat;
        }
    }
    return (repeat);
}



