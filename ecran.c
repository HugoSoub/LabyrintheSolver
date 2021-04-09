#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "ecran.h"

//Déclaration des variables
SDL_Window *ecran = NULL;
SDL_Surface *SurfaceBg = NULL;
SDL_Surface *windowSurface = NULL;
SDL_Surface *surfaceMur[71][71];

/* ---------------------------------------------------------- */
/* initisalisation de la fenêtre */

void initFenetre()
{
    //Vérifie que la fenêtre se lance bien
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stdout,"Erreur : L'initialisation de la SDL n'a pas marché. (%s)\n",SDL_GetError());
    }

    //Création de la fenêtre 710
    ecran = SDL_CreateWindow("Labyrinthe resolver",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               710,
                               710,
                               SDL_WINDOW_SHOWN);

    //Surface de l'arrière plan de la fenêtre
    SurfaceBg = SDL_GetWindowSurface(ecran);

    //Donne la couleur blanche à l'arrière plan
    SDL_FillRect(SurfaceBg, NULL, SDL_MapRGB(SurfaceBg->format, 255, 255, 255));

    //Mise à jour de la fenêtre
    SDL_UpdateWindowSurface(ecran);
}

/* ---------------------------------------------------------- */
/* Affiche la grille sur sur l'ecran */

    void afficheGrille(int labyrinthe[71][71])
    {
        windowSurface = SDL_GetWindowSurface(ecran);

        int x = 0;
        int y = 0;

        //Parcour le tableau à deux dimension labyrinthe
        for(lignes = 0; lignes < 71; lignes++)
        {
            for(colonnes = 0; colonnes < 71; colonnes++)
            {
                //Ajout d'un carré noir si le tableau retourne -1
                if(labyrinthe[lignes][colonnes] == -1)
                {
                    // Permet de créer des surfaces et stock dans le tableau
                    surfaceMur[lignes][colonnes] = SDL_CreateRGBSurface(0, 10, 10, 32, 0, 0, 0, 0);

                    // Donne la couleur noir au valeur tab égale à -1
                    SDL_FillRect(surfaceMur[lignes][colonnes], NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));

                    // Position du carré noir dans la fenêtre
                    SDL_Rect positionMur;
                    positionMur.x = x;
                    positionMur.y = y;

                    SDL_BlitSurface(surfaceMur[lignes][colonnes], NULL, windowSurface, &positionMur);
                }
                else if(labyrinthe[lignes][colonnes] == -2)
                {
                    // Permet de créer des surfaces et stock dans le tableau
                    surfaceMur[lignes][colonnes] = SDL_CreateRGBSurface(0, 10, 10, 32, 0, 0, 0, 0);

                    // Donne la couleur rouge au valeur tab égale à -2
                    SDL_FillRect(surfaceMur[lignes][colonnes], NULL, SDL_MapRGB(windowSurface->format, 255, 0, 0));

                    //Position du carré noir dans la fenêtre
                    SDL_Rect positionMur;
                    positionMur.x = x;
                    positionMur.y = y;

                    SDL_BlitSurface(surfaceMur[lignes][colonnes], NULL, windowSurface, &positionMur);
                }

                // Permet de connaitre la position du carré sur la fenêtre
                x += 10;
            }
            // Permet de connaitre la position du carré sur la fenêtre
            y += 10;
            x = 0;
        }

        // Update le rendu dans la fenêtre
        SDL_UpdateWindowSurface(ecran);
    }
