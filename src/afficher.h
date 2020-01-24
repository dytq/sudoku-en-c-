#include "gestion_sudoku.h"

#ifndef __AFFICHER_H
#define __AFFICHER_H
// Fonction a appeler au début poour créer la fenêtre grapĥique
void initialiser_fenetre_graphique();

// Fonction a appeler à la fin pour terminer proprement la fenêtre grapĥique
void terminer_fenetre_graphique();

// Fonction qui affiche l'état courant du sudoku
void sudoku_afficher(SUDOKU S,char *titre);

// Fonction qui affiche "vous avez gagner" sur fond noir
void affiche_gagner();

// Fonction qui affiche le quadriallage
void dessine_quadrillage();
#endif
