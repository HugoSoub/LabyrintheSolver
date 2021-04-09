#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED

    int lignes;
    int colonnes;

    //Prototype
    void initFenetre();
    void afficheGrille(int labyrinthe[71][71]);
    void LabyrintheEntreSortie(int labyrinthe[71][71]);
    void afficheChemin(int labyrinthe[71][71]);

#endif // ECRAN_H_INCLUDED

