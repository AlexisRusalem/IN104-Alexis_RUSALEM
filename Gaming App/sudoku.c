#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sudoku.h"


// Fonction d' affichage_grille
void  affichage_grille (int grille[9][9])
{
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            printf( ((j+1)%3) ? "%d " : "%d|", grille[i][j]);
        }
        putchar('\n');
        if (!((i+1)%3))
            puts("------------------");
    }
    puts("\n\n");
}

bool absentSurLigne (int k, int grille[9][9], int i) // on test si k est sur la ligne i
{
    for (int j=0; j < 9; j++)
        if (grille[i][j] == k)
            return false;
    return true;
}

bool absentSurColonne (int k, int grille[9][9], int j) //on test si k est sur la colonne j
{
    for (int i=0; i < 9; i++)
        if (grille[i][j] == k)
            return false;
    return true;
}

bool absentSurBloc (int k, int grille[9][9], int i, int j) // on regarde si k est dans le bloc de  i, j 
{
    int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3); 
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (grille[i][j] == k)
                return false;
    return true;
}

bool estValide (int grille[9][9], int position) // on regarde si la grille est valide, posiion est une variable de 1 à 81
{
    if (position == 9*9)
        return true;

    int i = position/9, j = position%9;

    if (grille[i][j] != 0)
        return estValide(grille, position+1);

    for (int k=1; k <= 9; k++) // on balaye tous les entiers possibles et si il est ok on le met 
    {
        if (absentSurLigne(k,grille,i) && absentSurColonne(k,grille,j) && absentSurBloc(k,grille,i,j))
        {
            grille[i][j] = k;

            if ( estValide (grille, position+1) )
                return true;
        }
    }
    grille[i][j] = 0;

    return false;
}

bool coup(int grille[9][9])
{
    		int ligne;
    		int colonne;
    		int valeur;
	    	printf("_______________________________________________________________________________________\n");
	    	printf("                             Selectionez la ligne (de 1 à 9)                           \n");
	    	printf("_______________________________________________________________________________________\n");
	    	scanf("%u", &ligne);
	    	if ((ligne<=0) || (ligne>9)){
	    		printf("_______________________________________________________________________________________\n");
	    		printf("                                  Hors de la grille                                    \n");
	    		printf("_______________________________________________________________________________________\n");
	    		return false;}
	    

	    	printf("_______________________________________________________________________________________\n");
	    	printf("                             Selectionez la colonne (de 1 à 9)                           \n");
	    	printf("_______________________________________________________________________________________\n");
  		scanf("%u", &colonne);
  		if ((colonne<=0) || (colonne>9)){
	    		printf("_______________________________________________________________________________________\n");
	    		printf("                                  Hors de la grille                                    \n");
	    		printf("_______________________________________________________________________________________\n");
	    		return false;}
	    	if (grille[ligne-1][colonne-1]!=0){
	    		printf("_______________________________________________________________________________________\n");
	    		printf("                                  Case déjà remplie                                    \n");
	    		printf("_______________________________________________________________________________________\n");
			return false;}
			
		printf("Selectionnez la valeur (de 1 à 9):");
	    	scanf("%u", &valeur);
	    	if (valeur<0 || valeur>9){
	    		printf("_______________________________________________________________________________________\n");
	    		printf("                                  Valeur incorrecte                                    \n");
	    		printf("_______________________________________________________________________________________\n");
			return false;}
		else { // On remplit la grille si aucune des condirions précédentes n'est validées 
			grille[ligne-1][colonne-1]=valeur;
			 affichage_grille(grille);
			return true;}
			
	    	
} 


void remplir_diagonales_3x3(int grille[9][9]){
	for (int i=0; i<9; i++){
		grille[i][i]=1+i;
		}
	}


void play_sudoku(){
	int niveau;
	int grille_finale[9][9]=
    {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
  
    };
	int grille[9][9] =
    {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
  
    };

    remplir_diagonales_3x3(grille);
    estValide(grille,0); // remplit la grille complètement !!!
    
    
    // Sauvegarde de la grille complétée
    
    memcpy(grille_finale, grille, sizeof grille);
    printf("_______________________________________________________________________________________\n");
    printf("               Niveau de difficulté (easy 1, medium 2, hard 3):                        \n");
    printf("_______________________________________________________________________________________\n");
    scanf("%d", &niveau);
    
	// on supprime aléatoirement des cases
	for(int i=0;i<9;++i)
		{
		for(int j=0;j<niveau;++j)
		{
		grille[i][rand()%9]=0;
		grille[rand()%9][i]=0;
		}}
	printf("_______________________________________________________________________________________\n");
    	printf("                                 Grille à résoudre                                     \n");
    	printf("_______________________________________________________________________________________\n");
     affichage_grille(grille);
    


    while(memcmp(grille_finale, grille, sizeof grille)!=0){   
	    	while(coup(grille)==false){
	    		 affichage_grille(grille_finale);}
	    
	 }
	printf("_______________________________________________________________________________________\n");
	printf("                          Bravo vous avez gagné!!!!!!!!!                               \n");
	printf("_______________________________________________________________________________________\n");
    }

