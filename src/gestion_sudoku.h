
#ifndef __SUDOKU_H
#define __SUDOKU_H

#include "pile.h"

struct element
{
	int val;					//Valeur de la case 
	unsigned int indice;		//chaque case aura un ensemble de valeurs d'indices possible. 
	int est_verifie;			//0 (FAUX) si verifié 1 (VRAI) sinon
	int est_travail;			//0 (FAUX) si ce n'est pas une valeur de travail et 1 (VRAI) sinon 
};
struct sudoku
{
	struct element T[9][9];		//Chaque case
	PILE p;   					//Déclaration du type "PILE" pour sauvegarder les valeurs et les restituer après.
};

typedef struct sudoku SUDOKU;

//Fonction d'initialisation des valeurs dans la structure SUDOKU
SUDOKU initialisation_valeurs(SUDOKU S);

//Fonction qui modifie une case dans le SUDOKU
SUDOKU sudoku_modifier_case(SUDOKU S,int ligne,int colonne);

//Fonction qui permet mettre pour chaque case de élement de remplir le tableau d'indices selon les valeurs possible
SUDOKU valeurs_possible(SUDOKU S);
SUDOKU remplir_ligne(SUDOKU S,int y,int x);
SUDOKU remplir_colonne(SUDOKU S,int y,int x);
SUDOKU remplir_case(SUDOKU S,int i,int j);

//Fonction qui permet le retour en arrière lorqu'il est appelée
SUDOKU undo(SUDOKU S);

//Fonction qui trouve la solution
int trouve(SUDOKU S);

//Fonction qui termine le programme
int terminer(SUDOKU S);
#endif


