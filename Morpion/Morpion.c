#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Q1)

int* creer_grille(){
	int* grille = malloc(sizeof(int)*9);
	for (int i=0; i<9; i+=1){
		grille[i]=0;}
	return(grille);
	}
/*
 int main(){
 	creer_grille();
 }
*/
// Q2) 

void afficher(int* grille){
	for (int i=0; i<9; i+=3){
		printf("%d",grille[i]);
		printf("%d",grille[i+1]);
		printf("%d\n",grille[i+2]);
		}
	}
/*
 int main(){
 	afficher(creer_grille());
 }
 
*/
 // Q3)
 
 int test_affichage(){
 	int* grille= creer_grille();
 	grille[4]=1;
 	grille[8]=2;
 	afficher(grille);
 	return(0);
 	}
/*
 int main(){
 	test_affichage();
 }
*/
// Q4)

void placer(int* grille, int chiffre, int joueur) {
	grille[chiffre-1]=joueur;
	}
/*	
// Cette fonction permet de placer un pion humain à la case d'indice 3
int main(){
 	int* grille= creer_grille();
 	placer(grille, 3, 1);
 	afficher(grille);
 	}
 */
 
 // Q5)
 
 void placer_alea(int* grille, int joueur){
 	srand(time(0));
 	int alea=rand()%9 +1;
 	while (grille[alea-1]!=0){
 		alea=rand()%9 +1;}
 	placer(grille,alea,joueur);
 	}
 			
 /*
 int main(){
 	int joueur=2;
 	int* grille= creer_grille();
 	placer_alea(grille, joueur);
 	afficher(grille);
 	}
 */
 // Q6
 
 int a_gagne(int* grille, int joueur){
 	if (grille[0]==joueur && grille[1]==joueur && grille[2]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[3]==joueur && grille[4]==joueur && grille[5]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[6]==joueur && grille[7]==joueur && grille[8]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[0]==joueur && grille[4]==joueur && grille[8]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[2]==joueur && grille[4]==joueur && grille[6]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[6]==joueur && grille[7]==joueur && grille[8]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
  	if (grille[0]==joueur && grille[3]==joueur && grille[6]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[1]==joueur && grille[4]==joueur && grille[7]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	if (grille[2]==joueur && grille[5]==joueur && grille[8]==joueur){
 		printf("C'est le joueur %d", joueur);
 		printf(" qui a gagné");
 		return(1);
 		}
 	else{
 		return(0);	
 	}
 	}


 // Q7)

/*
int main(){
 	int x;
 	int* grille= creer_grille();
 	while(a_gagne(grille,1)!=1 && a_gagne(grille,2)!=1){
 		afficher(grille);
 		printf("En quelle case veux-tu jouer?");
 		scanf("%d", &x);
 		placer(grille, x, 1);
 		placer_alea(grille,2);
	}
	free(grille);
	}
*/
// Q8)

int main(){
 	int compteur=0;
 	int j=0;
 	int x;
 	int* grille= creer_grille();
 	while(a_gagne(grille,1)!=1 && a_gagne(grille,2)!=1){
 		
 		//afficher(grille);
 		
 		printf("En quelle case veux-tu jouer?");
 		scanf("%d", &x);
 		placer(grille, x, 1);
 		placer_alea(grille,2);
 		compteur+=1;
 		for (int i=0; i<9; i+=1){
 			if (grille[i]!=0){
 				j+=1;}
 			}
 		
 		if (j>=9 && a_gagne(grille,1)==0 && a_gagne(grille,2)==0 ){
 			printf("il y a match nul en %d", compteur);
 			printf(" tours\n");	
 		
 		} 
 		j=0;
 		
 		for (int i=0; i<3; i+=1){
 				if (grille[i]==1){
 					printf("X");
 			}
 				if (grille[i]==2){
 					printf("O");
 			}
 				if (grille[i]==0){
 					printf(".");
 			}
 			
 			}
 			printf("\n");
 		for (int i=3; i<6; i+=1){
 				if (grille[i]==1){
 					printf("X");
 			}
 				if (grille[i]==2){
 					printf("O");
 			}
 				if (grille[i]==0){
 					printf(".");
 			}
 			}
 			printf("\n");
 		for (int i=6; i<9; i+=1){
 				if (grille[i]==1){
 					printf("X");
 			}
 				if (grille[i]==2){
 					printf("O");
 			}
 				if (grille[i]==0){
 					printf(".");
 			}

 			}
 			printf("\n");
 			}
 		
		free(grille);
	}



