#include <stdlib.h>
#include <stdio.h>

//~ local
#include "pile.h"
#include "constantes.h"

PILE creer_pile()
{
	PILE p=NULL;
	p=malloc(sizeof(int));
	if(p==NULL)
	{
		fprintf(stderr,"ERREUR:echec d'allocation de mémoire :/");
		exit(EXIT_FAILURE);
	}	
	return p;
}
int est_vide(PILE p)
{
	if(p->suiv==NULL)
		return VRAI;
	return FAUX;
}
PILE empile(PILE p,int val,int x,int y)
{
	PILE tmp;
	tmp=malloc(sizeof(struct pile));
	if(tmp==NULL)
	{
		fprintf(stderr,"ERREUR:echec d'allocation de mémoire, impossible de rajouté une valeur :/");
		exit(EXIT_FAILURE);
	}
	tmp->T.v=val;
	tmp->T.x=x;
	tmp->T.y=y;
	tmp->suiv=p;
	return tmp;
}
PILE depile(PILE p)
{
	PILE ltmp;
	if(est_vide(p)==VRAI)
	{
		fprintf(stderr,"ATTENTION: la pile est vide, écriture impossible :/ ");
		exit(EXIT_FAILURE);
	}
	ltmp=p->suiv;
	free(p);
	return ltmp;
}
struct elmt prendre(PILE p)
{
	return p->T;
}
void debug(PILE p)
{
	printf("SUDOKU DATA PILE:\n");
	while(p->suiv!=NULL)
	{
		printf("<");	
		printf("[val:%d]",p->T.v);
		printf("[x:%d]",p->T.x);
		printf("[y:%d]",p->T.y);
		printf(">\n");		
		p=p->suiv;
	}
	printf("\n");
}
