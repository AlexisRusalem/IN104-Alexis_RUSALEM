#include <stdio.h>
#include <stdlib.h>
	
	
int main(){
	int area[9][9];
	int i, j;

// On génère la matrice aléatoirement 
	for(j=0;j<9;++j){
		for(i=0;i<9;++i){
			area[j][i]=(i+j*3+j/3)%9 +1;
			}
			}

	
	// on demande à l'utilisateur la difficulté souhaitée 
	
	int niveau=0;
	printf("Niveau de difficulté (easy 1, medium 2, hard 3):\n");
	scanf("%d\n", &niveau);
	
	// on supprime aléatoirement des cases
	for(i=0;i<9;++i)
		{
		for(j=0;j<niveau;++j)
		{
		area[i][j+rand()%3]=0;
		}}
	

	// Afficher la matrice
	for(i=0;i<9;++i)
		{
		for(j=0;j<9;++j){
			printf("%d  ", area[i][j]);
			}
		printf("\n");
	}}
