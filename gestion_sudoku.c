#include <stdlib.h>
#include <stdio.h> //Pour le debug

//~ local
#include "gestion_sudoku.h"
#include "constantes.h"
#include "afficher.h"

SUDOKU initialisation_valeurs(SUDOKU S)
{
	int i,j;
	for(i=0;i<9;i++) for(j=0;j<9;j++) S.T[i][j].est_verifie=FAUX;
	return S=valeurs_possible(S);		//Pour pouvoir afficher les indices et initialiser
}
SUDOKU remplir_colonne(SUDOKU S,int i,int j)
{
	int x=j;
	int y=0;
	while(y<9)
	{
		unsigned int tmp=0x00000001;
		tmp=tmp<<S.T[y][x].val;
		S.T[i][j].indice|=tmp;
		y++;
	}
	return S;
}
SUDOKU remplir_ligne(SUDOKU S,int i,int j)
{
	int x=0;
	int y=i;
	while(x<9)
	{
		unsigned int tmp=0x00000001;
		tmp=tmp<<S.T[y][x].val;
		S.T[i][j].indice|=tmp;
		x++;
	}
	return S;
}
SUDOKU remplir_case(SUDOKU S,int i,int j)
{
	int x_2;
	int y_2;
	int x_1;
	int y_1;
	x_2=j*3;
	y_2=i*3;
	x_1=j*3;
	y_1=i*3;
	while(y_1<i*3+3)
	{
		while(x_1<j*3+3)
		{
			unsigned int tmp=0x00000001;
			tmp=tmp<<S.T[y_1][x_1].val;
			while(y_2<i*3+3)
			{
				while(x_2<j*3+3)
				{
					S.T[y_2][x_2].indice|=tmp;
					x_2++;
				}
				x_2=j*3;
				y_2++;
			}
			y_2=i*3;
			x_1++;
		}
		x_1=j*3;
		y_1++;
	}
	return S;
}
SUDOKU valeurs_possible(SUDOKU S)
{
	int i=0,j=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			S.T[i][j].indice=0x00000001;
			S = remplir_colonne(S,i,j);
			S = remplir_ligne(S,i,j);
			S = remplir_case(S,i/3,j/3);
		}
	}
	//DEBUG
	//~ for(i=0;i<9;i++)
	//~ {
		//~ for(j=0;j<9;j++)
		//~ {
			//~ printf("|%X|",S.T[i][j].indice);
		//~ }
		//~ printf("\n");
	//~ }
	//~ printf("\n");
	return S;
}
SUDOKU sudoku_modifier_case(SUDOKU S,int ligne,int colonne)
{
	if(S.T[colonne][ligne].est_travail==VRAI)
	{
		S.p=empile(S.p,S.T[colonne][ligne].val,ligne,colonne); // on empile les valeurs ajouté (on fera de même pour la vérification)
		debug(S.p);
		while( (S.T[colonne][ligne].indice >> S.T[colonne][ligne].val) & 1)	S.T[colonne][ligne].val++;
		if(S.T[colonne][ligne].val > 9) S.T[colonne][ligne].val=0;
	}
	S=valeurs_possible(S);
	return S;
}

SUDOKU undo(SUDOKU S)
{
	if(est_vide(S.p)==FAUX)
	{
		S.p->T=prendre(S.p);
		S.T[S.p->T.y][S.p->T.x].val=S.p->T.v;
		S.p=depile(S.p);		    //fonction de dépilement  de la première valeurs
		S=valeurs_possible(S); 		//raffraichissement des valeurs
		debug(S.p); 				//affiche la pile
	}
	return S;
}

int terminer(SUDOKU S)
{
	int i,j;
	for(i=0;i<9;i++) for(j=0;j<9;j++) if(S.T[i][j].indice!=0x000003FF) return VRAI;
	return FAUX;
}

int trouve(SUDOKU S) //cette fonction cherche si il y a un seul indice possible pour chaque case
{
	int cmp=0;
	int add_val=0;
	int valeurs=0;
	int i,j,k;
	while(terminer(S))
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(S.T[i][j].est_travail==VRAI&&S.T[i][j].val==VIDE)
				{
					for(k=1;k<=9;k++)
					{
						if(((S.T[i][j].indice>>k)&1)==0)
						{
							cmp++;
							valeurs=k;
						}
					}
				}
				if(!(cmp) && S.T[i][j].est_travail==VRAI && !(S.T[i][j].val)) 
				{
					sudoku_afficher(S,"ECHEC:(");
					return 0; //si le programme genere des valeurs impossible
				}
				if(cmp==1)
				{
					add_val++;
					S.T[i][j].val=valeurs;
					S.T[i][j].est_verifie=VRAI;
					sudoku_afficher(S,"VERIFICATION");
					S=valeurs_possible(S);
				}
				cmp=0;
				valeurs=0;
			}
		}
		if(add_val==0)  //si aucune valeur possible
		{
			sudoku_afficher(S,"ECHEC:(");
			return 0;
		}
		add_val=0;
	}
	sudoku_afficher(S,"SOLUTION");
	return 1;
}
