#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "joueur.h"
#include "pioche.h"
#include "mecanique.h"

int main() {
    srand(time(NULL));
    int nbJoueurs = 0;
    int partieEnCours = 1;

    Joueur *tabJoueurs = connexion(&nbJoueurs);
    Pioche deck;
    initialiser_pioche(&deck);
    melanger_pioche(&deck); 

    while (partieEnCours) {
        printf("\n========== NOUVELLE MANCHE ==========\n");

        for (int i = 0; i < nbJoueurs; i++) {
            reset_joueur_manche(&tabJoueurs[i]);
            
            jouer_tour(&tabJoueurs[i], &deck);

            tabJoueurs[i].scoreTotal += tabJoueurs[i].scoreManche;
            printf("Fin du tour. Score total de %s : %d\n", tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);

            if (tabJoueurs[i].scoreTotal >= 200) {
                printf("\n!!! %s A ATTEINT 200 POINTS ET REMPORTE LA VICTOIRE !!!\n", tabJoueurs[i].nom);
                partieEnCours = 0;
                break; //
            }

            if (deck.indexProchaine >= TAILLE_PIOCHE) {
                printf("\n--- LA PIOCHE EST EPUISEE. FIN DE LA PARTIE. ---\n");
                partieEnCours = 0;
                break;
            }
        }
    }

    printf("\n--- CLASSEMENT FINAL ---\n");
    for (int i = 0; i < nbJoueurs; i++) {
        printf("%d. %s : %d points\n", i + 1, tabJoueurs[i].nom, tabJoueurs[i].scoreTotal);
    }

    free(tabJoueurs);
    printf("\nMerci d'avoir joue a FlipTek !\n");

    return 0;
}
