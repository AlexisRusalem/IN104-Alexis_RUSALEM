#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pacman.h"
#define height 60
#define width 30
#define nb_ghosts 40
#define nb_lives 5
#define nb_obstacles 50

//Cette fonction affiche la grille de jeu
void  afficher_grille(char area[width][height]){
    for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                printf("%c",area[i][j]);
            }
            printf("\n");
        };


}




//Cette fonction place aleatoirement les fantomes sur l'aire de jeu

void init_ghosts(struct ghost allghosts[nb_ghosts], char area[width][height]) {

    //Creation et placement aleatoire des ghosts
    struct ghost g;
    for (int i=0; i<nb_ghosts; i++){
    int a=rand()%width;
    int b=rand()%height;
    while (area[a][b]=='#'  /* ||  area[a][b]=='G.' */ || area[a][b]=='G'  ){
    a=rand()%width;
    b=rand()%height;       
    }
    g.coord.x=a;
    g.coord.y=b;
    allghosts[i]=g;
    area[a][b]='G';
    }

    //Remplissage aleatoire de la grille avec des food
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){        
        if(area[i][j]==' '  ){
            area[i][j]='.';
            }         
        }
    };  

}

//initialisation de la liste des ghosts
struct ghost allghosts[nb_ghosts];


//initiamisation du pacman
struct PacMan pacman = {
        {
             .x = 1,
            .y = 1,
        },
         .nx = 0,
        .ny = 0,
        .lives = nb_lives,
        .food=0,
};


//initialisation de la grille de jeu
char area [width][height]=
    {
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        # # # # #          #             # # # # # #      #" },
   { "#        #       #         # #            #                #" },
   { "#        #       #        #   #           #                #" },
   { "#        # # # # #       #     #          #                #" },
   { "#        #              # # # # #         #                #" },
   { "#        #             #         #        #                #" },
   { "#        #            #           #       #                #" },
   { "#        #           #             #      #                #" },
   { "#        #          #               #     # # # # # #      #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        ##        ##           #          ##        #     #" },
   { "#        # #      # #          # #         # #       #     #" },
   { "#        #  #    #  #         #   #        #  #      #     #" },
   { "#        #    # #   #        #     #       #   #     #     #" },
   { "#        #     #    #       # # # # #      #    #    #     #" },
   { "#        #          #      #         #     #     #   #     #" },
   { "#        #          #     #           #    #      #  #     #" },
   { "#        #          #    #             #   #       # #     #" },
   { "#        #          #   #               #  #        ##     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
};


//Fonction qui demande la direction du pacman et qui déplace simultanement les fantomes


void deplacer_ghost(){
        //Demande a l'utilisateur la direction souhaitée
        int reponse;
        printf("_______________________________________________________________________________________\n");
        printf("Entrez 8 pour aller en haut, 5 pour le bas, 4 pour la gauche et 6 pour la droite :     \n");
        printf("_______________________________________________________________________________________\n");
        scanf("%d",&reponse); 
        if(reponse==8){
        pacman.nx=-1;
        pacman.ny=0;
        }
        else if(reponse==5){
        pacman.nx=1;
        pacman.ny=0;
        }
        else if(reponse==4){
        pacman.nx=0;
        pacman.ny=-1;
        }
        else if(reponse==6){
        pacman.nx=0;
        pacman.ny=1;
        }
        else{
        pacman.nx=0;
        pacman.ny=0;
    }


// Déplace aléatoirement les fantômes :
 
    for (int i=0; i<nb_ghosts; i++){
        int a=allghosts[i].coord.x;   // on récupère les coordonnées du ghost
        int b=allghosts[i].coord.y;
         int newa=a;
        int newb=b;
        int k=rand()%3-1;
        int j=rand()%2;
        
       
       if (area[(a+k*j)%width][(b+k*abs(j-1)%2)%height]=='.' || area[(a+k*j)%width][(b+k*abs(j-1)%2)%height]==' ') {
        	
        
        newa=(a+k*j)%width;
        newb=(b+k*abs(j-1)%2)%height;}
        
	else {
	k=rand()%3-1;
	j=rand()%2;
	if (area[(a+k*j)%width][(b+k*abs(j-1)%2)%height]=='.' || area[(a+k*j)%width][(b+k*abs(j-1)%2)%height]==' ') {
        	
        
        newa=(a+k*j)%width;
        newb=(b+k*abs(j-1)%2)%height;}}	
        
        area[a][b]='.';
        area[newa][newb]='G';
        
  
         
        allghosts[i].coord.x=newa;
        allghosts[i].coord.y=newb;
        

    };
    
    
}

//Permet le deplacement du pacman

 void deplacer_pacman(){
    
    area[pacman.coord.x][pacman.coord.y]=' ';
    
    
    //verifie si le pacman croise un obstacle ou non
    
        if(area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='#' || area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='G' /*|| area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='G.' */ ){
            pacman.coord.x=1;
            pacman.coord.y=1;
            pacman.lives=pacman.lives-1;

        }
        else{
            pacman.coord.x=pacman.coord.x+pacman.nx;
            pacman.coord.y=pacman.coord.y+pacman.ny;
            if(area[pacman.coord.x][pacman.coord.y]=='.'){
                pacman.food=pacman.food+1;
            }
            
        }
    area[pacman.coord.x][pacman.coord.y]='P';

};



//Cette fonction que le pacman a un encore un nombre de vie positif, elle renvoit faux sinon

bool vie_restante(struct PacMan pacman, char area[width][height]){
    if(pacman.lives<0){
	printf("_______________________________________________________________________________________\n");
	printf("                           Vous avez perdu avec un score de  %d                        \n",pacman.food);
	printf("_______________________________________________________________________________________\n");
        return false;
    }
    else{
         afficher_grille(area); // on affiche le grille pour rejouer 
    }
    return true;
}



int play_pacman(){
   

init_ghosts(allghosts,area);
area[1][1]='P';


 afficher_grille(area); 
bool A=true;

while(A){
    deplacer_ghost();
     //int l =3;
    //printf("%d", l);
    //afficher_grille(area); 
    deplacer_pacman();
    
    A=vie_restante(pacman,area);


}/*
for (int i=0; i<3; i++){
    deplacer_ghost();
     //int l =3;
    //printf("%d", l);
    deplacer_pacman();
    //A=vie_restante(pacman,area);
    }*/

return 0;

}
