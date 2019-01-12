#include <stdio.h>
#include <uvsqgraphics.h>
#include "constantes.h"
#include "gestion_sudoku.h"

void initialiser_fenetre_graphique() {
	init_graphics(LARGEUR,HAUTEUR);
	affiche_auto_off();
}

void terminer_fenetre_graphique() {
	printf("\n**/!%cNETOYAGE DE LA PILE /!%c**\n",92,92);
	wait_escape();
	exit(EXIT_SUCCESS);
}
void dessine_quadrillage()
{
	POINT p1,p2;
	for(p1.x=0,p1.y=0,p2.y=HAUTEUR-TAILLE_CASE,p2.x=0;p1.x<LARGEUR; p1.x+=TAILLE_CASE,p2.x+=TAILLE_CASE)
	{
		draw_line(p1,p2,COUL_TRAIT);
		if(!(p1.x%(3*TAILLE_CASE)))
		{
			p1.x++,p2.x++;
			draw_line(p1,p2,COUL_TRAIT);
			p1.x--,p2.x--;
		}
	}
	for(p1.x=0,p1.y=0,p2.y=0,p2.x=LARGEUR;p1.y<HAUTEUR; p1.y+=TAILLE_CASE,p2.y+=TAILLE_CASE)
	{
		draw_line(p1,p2,COUL_TRAIT);
		if(!(p1.y%(3*TAILLE_CASE)))	
		{
			p1.y++,p2.y++;
			draw_line(p1,p2,COUL_TRAIT);
			p1.y--,p2.y--;
		}
	}
}
void affiche_nombre(SUDOKU S)
{
	POINT p1;
	int i,j;
	for(i=0,p1.y=TAILLE_CASE;i<9;i++,p1.y+=TAILLE_CASE)
	{
		for(j=0,p1.x=TAILLE_CASE/4;j<=9;j++,p1.x+=TAILLE_CASE)
		{
			if(S.T[i][j].est_travail==VRAI)
			{
				int tmp=p1.x;
				for(int k=0;k<=9;k++)
				{
					if(((S.T[i][j].indice>>k)&1)==0)
					{
						aff_int(k, TAILLE_POLICE_INDICES, p1, COUL_VAL_INDICES);
						p1.x=p1.x+TAILLE_POLICE_INDICES;
					}
				}
				p1.x=tmp;
			}
			if(S.T[i][j].est_travail==FAUX) aff_int(S.T[i][j].val, TAILLE_POLICE, p1, COUL_VAL_DEPART);
			if(S.T[i][j].est_travail==VRAI && S.T[i][j].val!=0) aff_int(S.T[i][j].val, TAILLE_POLICE, p1, COUL_VAL_TRAVAIL);
			if(S.T[i][j].est_verifie==VRAI && S.T[i][j].val!=0)	aff_int(S.T[i][j].val, TAILLE_POLICE, p1, COUL_VAL_VERIFIE);
		}
	}
}
void affiche_titre(char *titre)
{
	POINT p;
	p.x=0,p.y=HAUTEUR;
	aff_pol(titre,TAILLE_POLICE,p,COUL_TITRE);
}
void affiche_case_pb(SUDOKU S)
{
	POINT p1,p2;
	int i,j,cmp=0;
	for(p1.y=0,p2.y=TAILLE_CASE,i=0 ; p2.y<=9*TAILLE_CASE ; p1.y+=TAILLE_CASE,p2.y+=TAILLE_CASE,i++)
	{
		for(p1.x=0,p2.x=TAILLE_CASE,j=0; p2.x<=9*TAILLE_CASE; p1.x+=TAILLE_CASE,p2.x+=TAILLE_CASE,j++) 
		{
			for(int k=1;k<=9;k++) if(((S.T[i][j].indice>>k)&1)==0) cmp++;
			if(!(cmp) && S.T[i][j].est_travail==VRAI && !(S.T[i][j].val)) draw_fill_rectangle(p1,p2,COUL_FOND_PB);
			cmp=0;
		}
	}
}
void sudoku_afficher(SUDOKU S,char *titre) //char *titre pour afficher le titre
{
	fill_screen(COUL_FOND);
	affiche_titre(titre);
	dessine_quadrillage();
	affiche_case_pb(S);
	affiche_nombre(S);
	affiche_all();
}
void affiche_gagner()
{
	fill_screen(noir);
	char *fin="GAGNER !:-)";
	POINT hg;
	hg.y=HAUTEUR;hg.x=0;
	aff_pol(fin,TAILLE_POLICE,hg, 0xFFFFFFFF);
}
