#include <stdlib.h>
#include <uvsqgraphics.h>

//~ local:
#include "constantes.h"
#include "afficher.h"
#include "gestion_sudoku.h"
#include "lire_ecrire.h"

SUDOKU jouer(SUDOKU S,char* nom)
{
	POINT P;
	char touche[2];
	int fleche[2];
	int a;
	a=wait_key_arrow_clic(touche,fleche,&P);
	if(a==EST_CLIC)
	{
		int ligne = P.x/TAILLE_CASE; 
		int colonne = P.y/TAILLE_CASE; 
		S = sudoku_modifier_case(S,ligne,colonne);
	}
	if(touche[0]=='U') S=undo(S); //retour en arrière
	if(touche[0]=='Q')
	{
		 printf("\n**ATTENTION:SAUVEGARDER VOTRE PARTIE AVANT DE QUITTER :/**\n");
		 terminer_fenetre_graphique();
	}	
	if(touche[0]=='S') ecrire_fichier(S,nom);
	if(touche[0]=='V')
	{
		if(trouve(S)) //ne modifie rien si échoue.Renvoie 1 si la fonction a réussi à résoudre le sudoku
		{
			attendre(1000);
			terminer_fenetre_graphique();		
		}
		attendre(1000);
	}
	return S;
}

int main (int argc, char *argv[]) 
{
	SUDOKU S;
	if(argc != 2)
	{
		fprintf(stderr, "AUCUN FICHIER CHARGÉ:OUVERTURE DU MODE PAR DEFAUT\n");
		argv[1]="mode_creatif.sudoku";
	}
	initialiser_fenetre_graphique();    	//Initialisation de la fenetre graphique
	S   = lire_fichier(argv[1]); 				//lecture du fichier principale 
	S   = initialisation_valeurs(S);			//Initialisation valeurs indice pour l'affichage;
	S.p = creer_pile();						//Création de la pile pour le retour en arrière
	sudoku_afficher(S,argv[1]);				//Affiche le sudoku et le titre
	while(terminer(S)) 						//Faire tant que le joueur n'a pas gagner 
	{
		S = jouer(S,argv[1]);				//Jouer - argv[1] pour pouvoir sauvegarder
		sudoku_afficher(S,argv[1]);			//Afficher
	}
	affiche_gagner();
	terminer_fenetre_graphique();			//Fin de la fenetre graphique
}
