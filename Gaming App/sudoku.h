#ifndef SUDOKU
#define SUDOKU


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


// fonction de declaration
	void affichage_grille (int grille[9][9]);
	bool absentSurLigne (int k, int grille[9][9], int i);
	bool absentSurColonne (int k, int grille[9][9], int j);
	bool absentSurBloc (int k, int grille[9][9], int i, int j);
	bool estValide (int grille[9][9], int position);
	bool coup(int grille[9][9]);
	void remplir_diagonales_3x3(int grille[9][9]);
	void play_sudoku();
	
	
#endif
