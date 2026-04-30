#ifndef PIOCHE_H
#define PIOCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAILLE_PIOCHE 85

typedef struct {
    int cartes[TAILLE_PIOCHE]; // tab des 85 carte
    int indexProchaine;        // indice de la prochaine carte à tirer
} Pioche;

/* --- Prototypes --- */

/**
 * Remplit le tableau avec les 79 numéros et les 6 bonus
 */
void initialiser_pioche(Pioche *p);

/**
 * Mélange aléatoirement les cartes (Fisher-Yates)
 */
void melanger_pioche(Pioche *p);

/**
 * Tire la carte suivante et incrémente l'index[cite: 1]
 * @return La valeur de la carte tirée
 */
int tirer_carte(Pioche *p);


#endif