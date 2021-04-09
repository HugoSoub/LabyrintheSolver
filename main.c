#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "ecran.h"
#include "generateur.h"

int main(int argc, char** argv)
{
    LabyrintheInit();

    //Initialise l'ecran
    initFenetre();

    //Cr�er la grille sur l'ecran
    afficheGrille(labyrinthe);



    //Permet de faire de ne pas fermer la fen�tre tant que l'utilisateur ne clique pas sur exit
    while(1)
    {
        SDL_Event event;
        SDL_WaitEvent(&event);

        if(event.type == SDL_QUIT)
        {
            break;
        }
    }

    //Quitte le programme et ferme la fen�tre
    SDL_Quit();
    return 0;
}
