#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//~ local
#include "gestion_sudoku.h"
#include "constantes.h"

SUDOKU lire_fichier (char *nom) {
	SUDOKU S;
	char c;
	FILE*F;
	printf("ouverture du fichier :%s\n",nom);
	F=fopen(nom,"r");
	int i=0,j=0;
	while((c=fgetc(F))!=EOF)
	{
		S.T[i][j].val=c-'0';
		S.T[i][j].est_travail=FAUX;
		if(c=='.') 
		{
			S.T[i][j].est_travail=VRAI;
			S.T[i][j].val=VIDE;			
		}
		if(c=='*')
		{
			c=fgetc(F);
			S.T[i][j].est_travail=VRAI;
			S.T[i][j].val=c-48;
		}
		j++;
		if(c==10)
		{
			j=0;
			i++;
		}
	}
	fclose(F);
	return S;
}

void ecrire_fichier(SUDOKU S,char* nom) {
	
	//Recherche un nom valable
	
	char nom_1[100];
	
	char init[100];
	char tmp[100];
	int cmp=0;
	init[0]='\0';
	while(*nom!='.')
	{
		sprintf(tmp,"%c",*nom);
		strcat(init,tmp);
		nom=nom+1;
		cmp++;
	}
	nom=nom-cmp;
	cmp++;
	if(*(nom+cmp)!='s')
	{
		int c=0,d=0,u=0;
		nom=nom+cmp;
		c=*nom-'0';
		nom++;
		d=*nom-'0';
		nom++;
		u=*nom-'0';		
		
		int x=(c*100)+(d*10)+u+1;
		char  nbr_save[200];
		if(x>999)
		{
			fprintf(stderr,"SAUVEGARDE IMPOSSIBLE:PLUS DE PLACE :( :");
			exit(EXIT_FAILURE);
		}
		nom_1[0]='\0';
		sprintf(nbr_save,"%d",x);
		if(x<10)
		{
			strcat(nom_1,init);
			strcat(nom_1,".00");
		}
		if(x>=10&&x<100) 
		{
			strcat(nom_1,init);
			strcat(nom_1,".0");
		}
		if(x>=100)
		{
			strcat(nom_1,init);  
			strcat(nom_1,".");
		}		
		strcat(nom_1,nbr_save);
		strcat(nom_1, ".sudoku");
			
		printf("Fichier sauvegardé: '%s'\n",nom_1);
	}
	else 
	{
		nom_1[0]='\0';
		strcat(nom_1,init);
		strcat(nom_1,".001.sudoku");
		printf("Fichier sauvegardé: '%s'\n",nom_1);
	}
	
	//ecriture dans le fichier
	
	FILE* F_write;
	F_write=fopen(nom_1,"w");
	int j,i;
	i=0;
	j=0;
	while(i<9)
	{
		if(S.T[i][j].val==0)
		{
			fputc('.',F_write);
		}
		else
		{
			if(S.T[i][j].est_travail==VRAI)
			{
				fputc('*',F_write);
				fputc(S.T[i][j].val+48,F_write);
			}
			else
				fputc(S.T[i][j].val+48,F_write);
		}
		j++;		
		if(j>=9)
		{
			fputc('\n',F_write);
			i++;
			j=0;
		}
	}
	fclose(F_write);
}
