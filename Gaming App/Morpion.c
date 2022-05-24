#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Morpion.h"



int* creer_grille(){
	int* grille = malloc(sizeof(int)*9);
	for (int i=0; i<9; i+=1){
		grille[i]=0;}
	return(grille);
	}

void afficher(int* grille){
	for (int i=0; i<9; i+=3){
		printf("%d",grille[i]);
		printf("%d",grille[i+1]);
		printf("%d\n",grille[i+2]);
		}
	}
	
void affichage_symbol(int* grille){
		printf("\n===============\n");
 		for (int i=0; i<3; i+=1){
 			printf("| ");
 				if (grille[i]==1){
 					printf("X |");
 			}
 				if (grille[i]==2){
 					printf("O |");
 			}
 				if (grille[i]==0){
 					printf(". |");
 			}
 			
 			}
 			printf("\n===============\n");
 		for (int i=3; i<6; i+=1){
 			printf("| ");
 				if (grille[i]==1){
 					printf("X |");
 			}
 				if (grille[i]==2){
 					printf("O |");
 			}
 				if (grille[i]==0){
 					printf(". |");
 			}
 			}
 			printf("\n===============\n");
 		for (int i=6; i<9; i+=1){
 			printf("| ");
 				if (grille[i]==1){
 					printf("X |");
 			}
 				if (grille[i]==2){
 					printf("O |");
 			}
 				if (grille[i]==0){
 					printf(". |");
 			}

 			}
 			printf("\n===============\n");
 			}



void placer(int* grille, int chiffre, int joueur) {
	if(grille[chiffre-1]==0){
 		grille[chiffre-1]=joueur;}
	}

 
 void placer_alea(int* grille, int joueur){
 	srand(time(0));
 	int alea=rand()%9 +1;
 	while (grille[alea-1]!=0){
 		alea=rand()%9 +1;}
 	placer(grille,alea,joueur);
 	}
 			

 int a_gagne(int* grille, int joueur){
 	if (grille[0]==joueur && grille[1]==joueur && grille[2]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[3]==joueur && grille[4]==joueur && grille[5]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[6]==joueur && grille[7]==joueur && grille[8]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[0]==joueur && grille[4]==joueur && grille[8]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[2]==joueur && grille[4]==joueur && grille[6]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[6]==joueur && grille[7]==joueur && grille[8]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
  	if (grille[0]==joueur && grille[3]==joueur && grille[6]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[1]==joueur && grille[4]==joueur && grille[7]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	if (grille[2]==joueur && grille[5]==joueur && grille[8]==joueur){
 		if (joueur ==1)(printf("Bravo vous avez gagné\n"));
 		if (joueur ==2)(printf("Dommage vous avez perdu\n"));
 		return(1);
 		}
 	else{
 		return(0);	
 	}
 	}



void play_morpion(){
 	int compteur=0;
 	//int j=0;
 	
 	int* grille= creer_grille();
 	while(a_gagne(grille,1)!=1 && a_gagne(grille,2)!=1){
 		int x=10;
 		affichage_symbol(grille);
		while (x>9 || x<1){ 
			printf("\nEn quelle case veux-tu jouer? ( de 1 à 9)");
 			scanf("%d", &x);
 			}

 		placer(grille,x,1);
 		placer_alea(grille,2);
 		compteur+=1;
 		/*for (int i=0; i<9; i+=1){
 			if (grille[i]!=0){
 				j+=1;}
 			}
 		
 		if (j>=9 && a_gagne(grille,1)==0 && a_gagne(grille,2)==0 ){
 			printf("il y a match nul en %d", compteur);
 			printf(" tours\n");	
 		
 		} 
 		j=0;
 		*/
 		printf("\n");
 			}
 		
		free(grille);
	}



