#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generateur.h"

/* ---------------------------------------------------------- */
/* Fonction qui permet l'initialisation dans le main */

LabyrintheInit()
{
    LabyrinteRemplitCase();
    LabyrinteRandomChiffre();
    LabyrintheCasseMur();
    CasseMurRandom();
    Solution();
}

/* ---------------------------------------------------------- */
/* Remplie le tableau de 1 et de -1 pour faire une grille */

LabyrinteRemplitCase()
{
    for(lignes = 0; lignes < 71; lignes++)
    {
        if(((lignes + 2) % 2) == 0)
        {
            for(colonnes = 0; colonnes < 71; colonnes++)
            {
                labyrinthe[lignes][colonnes] = -1;
            }
        }
        else
        {
            for(colonnes = 0; colonnes < 71; colonnes++)
            {
                if(((colonnes + 2) % 2) == 0)
                {
                    labyrinthe[lignes][colonnes] = -1;
                }
                else
                {
                    labyrinthe[lignes][colonnes] = 1;
                }
            }
        }
    }
}

/* ---------------------------------------------------------- */
/* Remplie le case du tableau qui ne sont pas égale à -1 d'un nombre unique */

LabyrinteRandomChiffre()
{
    int nb = 0;

    for(lignes = 0; lignes < 71; lignes++)
    {
        for(colonnes = 0; colonnes < 71; colonnes++)
        {
            if(labyrinthe[lignes][colonnes] == 1)
            {
                nb = nb + 1;
                labyrinthe[lignes][colonnes] = nb;
            }
        }
    }

    // Casse deux murs au bord pour avoir un début et une fin
    labyrinthe[1][0] = -2;
    labyrinthe[1][1] = -2;
    labyrinthe[69][70] = -3;
    labyrinthe[69][69] = -3;
}

/* ---------------------------------------------------------- */
/* Permet de casser les murs dans le tableau (-1) de maniere random */

LabyrintheCasseMur()
{
    // Permet de créer des chiffre random qui change bien à chaque lancement
    srand(time(NULL));

    // Répète la tache jusqu'à ce que toute les case est le même chiffre un qu'un chemin arriver fin est possible
    while(Terminer() == 0)
    {
        // Permet de choisir une case random dans le labi
        int x = (rand() % 69) + 1;
        int y = (rand() % 69) + 1;

        troue1 = -1;
        troue2 = -1;

        // Permet de vérifier que c'est bien un mur
        if(labyrinthe[x][y] == -1)
        {
            // Permet de savour si je dois prendre les case blanche haut et bas ou droite et gauche
            if(labyrinthe[x + 1][y] == -1)
            {
                troue1 = labyrinthe[x][y - 1];
                troue2 = labyrinthe[x][y + 1];
            }
            else
            {
                troue1 = labyrinthe[x + 1][y];
                troue2 = labyrinthe[x - 1][y];
            }
        }

        // Vérifie si l'on peut casser le mur ou pas
        if(troue1 != troue2 && troue1 != -1 && troue2 != -1)
        {
            // Casse le mur
            labyrinthe[x][y] = troue1;

            // Remplace toute les cases lié après le mur cassé pour qu'elles ait le même nombre
            for(int i = 0; i < 71; i++)
            {
                for(int j = 0; j < 71; j++)
                {
                    if(labyrinthe[i][j] == troue2)
                    {
                        labyrinthe[i][j] = troue1;
                    }
                }
            }
        }
    }

    // Toute les casses qui ne sont pas des murs on le chiffre 0
    for(int i = 0; i < 71; i++)
    {
        for(int j = 0; j < 71; j++)
        {
            if(labyrinthe[i][j] != -1)
            {
                labyrinthe[i][j] = 0;
            }
        }
    }
}

/* ---------------------------------------------------------- */
/* Permet de savoir quand le labyrinthe a fini d'être crée,cette fonction vérifie que toutes les cases blanches
   on le même nombre*/

int Terminer()
{
    for(int i = 1; i < 71; i++)
    {
        for(int j = 1; j < 71; j++)
        {
            if(labyrinthe[i][j] != -1)
            {

                if(labyrinthe[i][j] != troue1)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* ---------------------------------------------------------- */
/* Casse des murs random pour avoir un labyrinthe complexe avec plusieurs sortie possible */

CasseMurRandom()
{
    // Permet de créer des chiffre random qui change bien à chaque lancement
    srand(time(NULL));

    // Savoir le nombre de mur cassé
    int nbMurCasse = 0;

    while(nbMurCasse != 10)
    {

        // Permet de choisir une case random dans le labi
        int x = (rand() % 69) + 1;
        int y = (rand() % 69) + 1;

        // Pour savoir si la case du labi est bien un mur
        if(labyrinthe[x][y] == -1)
        {
            labyrinthe[x][y] = 0;
            nbMurCasse++;
        }
    }
}

/* ---------------------------------------------------------- */
/* Remplie chaque case avec la distancce de l'arrivé */

Solution()
{
    distance = 1;

    // Remplie la case d'arrivé par le nombre 1
    labyrinthe[69][70] = 1;

    while(labyrinthe[1][0] == 0)
    {
        distance++;

        for(int i = 0; i < 71; i++)
        {
            for(int j = 0; j < 71; j++)
            {
                if(labyrinthe[i][j] == distance - 1)
                {
                    if(labyrinthe[i + 1][j] == 0)
                    {
                        labyrinthe[i + 1][j] = distance;
                    }
                    if(labyrinthe[i - 1][j] == 0)
                    {
                        labyrinthe[i - 1][j] = distance;
                    }
                    if(labyrinthe[i][j + 1] == 0)
                    {
                        labyrinthe[i][j + 1] = distance;
                    }
                    if(labyrinthe[i][j - 1] == 0)
                    {
                        labyrinthe[i][j - 1] = distance;
                    }
                }
            }
        }
    }

    // Coordonnées de déplacement
    int i = 1;
    int j = 0;

    // Initialise la case de départ à -2
    labyrinthe[1][0] = -2;

    // Permet de mettre le nombre -2 pour créer le chemin gagnant dans le tableau
    while(labyrinthe[69][70] == 1)
    {
        if(labyrinthe[i + 1][j] == distance - 1)
        {
            labyrinthe[i + 1][j] = -2;
            i++;
        }
        else if(labyrinthe[i - 1][j] == distance - 1)
        {
            labyrinthe[i - 1][j] = -2;
            i--;
        }
        else if(labyrinthe[i][j + 1] == distance - 1)
        {
            labyrinthe[i][j + 1] = -2;
            j++;
        }
        else if(labyrinthe[i][j - 1] == distance - 1)
        {
            labyrinthe[i][j - 1] = -2;
            j--;
        }
        distance--;
    }
}
