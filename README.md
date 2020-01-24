# Sudoku en c 
## 0.Avant propos
Bibliothèque utilisé uvsq_graphics(sdl,debian(mais possibilité de changé le Makefile pour l'installation des composants)) disponible -> https://github.com/Heisenberk/uvsqgraphics.<br>
- Le détail du projet(+capture d'écran) c'est dans la documentation(doc/sudokuproject.pdf)
- Code source (src/*)
## 1.Quick-Start
### 1.Installation des composants
Installer sdl puis uvsq_graphics
### 2.Compilation du projet
cd src && make
### 3.Execution du projet
 - ./sudoku (ouverture par défaut) 
 - Sinon il faut chargé une map:<br>
  ./sudoku <le_niveau_a_chargé.sudoku>
## 1. Tout ce qui concerne l'affichage
afficher.c
afficher.h

## 2. La définition des constantes pour l'affichage
constantes.h

## 3. La définition du type SUDOKU et les fonctions de manupulation de cetype
gestion_sudoku.c
gestion_sudoku.h

## 4. Lecture et écriture vers et depuis le fichier
lire_ecrire.c
lire_ecrire.h

## 5. Definition de la pile pour le retour en arrière
pile.c
pile.h

## 5. Le programme principal
sudoku.c
