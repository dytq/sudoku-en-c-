
#ifndef __CONSTANTES_H
#define __CONSTANTES_H

// Les tailles de case et de police sont prévues
// pour tout avoir proportionel, il suffit de changer la valeur de TAILLE_CASE
// et tout s'affiche en proportion

// Echelle:

#define TAILLE_CASE 70 // La taille d'une case pour un pc de taille d'écran 15 pouces: 70
#define LARGEUR (9*TAILLE_CASE+1)   // La taille horizontale de la fenêtre
#define HAUTEUR ((9+1)*TAILLE_CASE) // La taille verticale   de la fenêtre
#define TAILLE_POLICE ((2*TAILLE_CASE)/3)
#define TAILLE_POLICE_INDICES (TAILLE_POLICE/7) 

// Les différentes couleurs:

#define COUL_TITRE 			0x40A497  		// Couleur du titre
#define COUL_FOND  			0xFAF7F8     	// Couleur de fond d'une case
#define COUL_FOND_PB 		0xF4254E        // Couleur de fond d'une case qui ne peut plus prendre aucune valeur
#define COUL_TRAIT 			0x445151       	// Couleur des traits de séparation
#define COUL_VAL_DEPART 	0xC70000    	// Couleur de la police des valeurs de départ
#define COUL_VAL_TRAVAIL 	0xFEE753     	// Couleur de la police des valeurs de travail
#define COUL_VAL_INDICES 	0x0B625D	 	// Couleur de la police des valeurs d'indices
#define COUL_VAL_VERIFIE    green 			// Couleur dela police des valeurs verifie
	
//Booléens:

#define VRAI 1
#define FAUX 0

//Autres constantes:

#define VIDE 0

#endif
