#ifndef GENERATEUR_H_INCLUDED
#define GENERATEUR_H_INCLUDED

    int labyrinthe[71][71];
    int lignes;
    int colonnes;
    int troue1;
    int troue2;
    int distance;

    //Prototype
    LabyrintheInit();
    LabyrinteRemplitCase();
    LabyrinteRandomChiffre();
    LabyrintheCasseMur();
    CasseMurRandom();
    Terminer();
    Solution();
    PrintTab();

#endif // GENERATEUR_H_INCLUDED
