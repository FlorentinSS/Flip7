#include "pioche.h"

void initialiser_pioche(Pioche *p) {
    int i = 0;

    p->cartes[i++] = 0;

    for (int num = 1; num <= 12; num++) {
        for (int qte = 0; qte < num; qte++) {
            p->cartes[i++] = num;
        }
    }


    for (int bonus = 13; bonus <= 18; bonus++) {
        p->cartes[i++] = bonus;
    }

    p->indexProchaine = 0;
}

void melanger_pioche(Pioche *p) {
    // Fisher Yate
    for (int i = TAILLE_PIOCHE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = p->cartes[i];
        p->cartes[i] = p->cartes[j];
        p->cartes[j] = temp;
    }
}

int tirer_carte(Pioche *p) {
    if (p->indexProchaine >= TAILLE_PIOCHE) {
        return -1; 
    }
    
    int carte = p->cartes[p->indexProchaine];
    p->indexProchaine++;
    return carte;
}

