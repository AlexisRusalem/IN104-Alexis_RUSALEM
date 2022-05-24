all:  file.o endmain.o Morpion.o sudoku.o pacman.o
	./file

file.o : endmain.o Morpion.o sudoku.o pacman.o
	gcc -o file endmain.o Morpion.o sudoku.o pacman.o

sudoku.o : sudoku.c sudoku.h
	gcc -o sudoku.o -c sudoku.c 
	
Morpion.o : Morpion.c Morpion.h
	gcc -o Morpion.o -c Morpion.c 

pacman.o : pacman.c pacman.h
	gcc -o pacman.o -c pacman.c 
	
	
endmain.o: endmain.c Morpion.h sudoku.h pacman.h
	gcc -o endmain.o -c endmain.c 
	
