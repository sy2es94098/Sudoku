#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    Sudoku();
    Sudoku(const int map[]);
    void printMap(int num);
    int getBlank(int tmp);
    int getNotBlank(int tmp);
    int repeatTest();
    int tryAnswer();
    int answerCheck(int now, int start, int next[]);
    bool solveTest();
    int recordNow(int now);
    int getLast();
    void setData();
    void externTest();
    static const int sudokuSize = 81;

    // generate
    void generate();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve();
  private:
    int map[sudokuSize];
    int map2[sudokuSize];
    int startRow[sudokuSize] ;
    int startColumn[sudokuSize] ;
    int startCell[sudokuSize] ;
    int nextRow[9] ;
    int nextColumn[9] ;
    int nextCell[9] ;
    int answerRecord[sudokuSize];

};

extern int lastNum[Sudoku::sudokuSize] ;
extern int lastLocation ;
#endif // SUDOKU_H
