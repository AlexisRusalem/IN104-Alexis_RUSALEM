#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

#define height 60
#define width 30
#define nb_ghosts 40
#define nb_lives 5
#define nb_obstacles 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


struct coor{
    int x;
    int y;
};

struct PacMan{
    struct coor coord;
    int nx; // 1, 0 ou -1, permet de gérer le déplacment (par exemple -1 haut ...)
    int ny;
    int lives; // nombre de vie
    int food; // nombre de nouriture 
};

struct ghost{
    struct coor coord;
    int nx;
    int ny;
};

void afficher_grille(char area[width][height]);
bool vie_restante(struct PacMan pacman, char area[width][height]);
void init_ghosts(struct ghost allghosts[nb_ghosts], char area[width][height]);
void deplacer_ghost();
 void deplacer_pacman();
 int play_pacman();



#endif
