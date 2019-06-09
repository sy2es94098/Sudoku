all::solve generate transform

generate:sudoku.o generate.o
	g++ -o generate generate.o sudoku.o

generate.o:sudoku.h generate.cpp
	g++ -c generate.cpp

solve:sudoku.o solve.o
	g++ -o solve solve.o sudoku.o

solve.o:solve.cpp sudoku.h
	g++ -c solve.cpp

transform:sudoku.o transform.o
	g++ -o transform transform.o sudoku.o

transform.o:transform.cpp sudoku.h
	g++ -c transform.cpp

sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

