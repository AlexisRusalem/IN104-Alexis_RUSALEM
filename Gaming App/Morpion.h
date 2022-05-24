#ifndef MORPION_H
#define MORPION_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// fonction de declaration
	int* creer_grille();
	void afficher(int* grille);
	void affichage_symbol(int* grille);
	void placer(int* grille, int chiffre, int joueur);
	void placer_alea(int* grille, int joueur);
	int a_gagne(int* grille, int joueur);
	void play_morpion();
	
#endif
