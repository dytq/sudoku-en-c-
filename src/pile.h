struct elmt{
	int v;
	int x;
	int y;
};
struct pile{
	struct elmt T;
	struct pile *suiv;	
};
typedef struct pile *PILE;

//Fonction qui crée une pile:
PILE creer_pile();

//Fonction qui vérifie si la pile est vide:
int est_vide(PILE p);

//Fonction qui empile les valeurs: 'val':valeur de la case,'x':l'axe des abscisses,'y':l'axe des ordonnées :
PILE empile(PILE p,int val,int x,int y);

//Fonction qui dépile la valeur du début de la pile:
PILE depile(PILE p);

//Fonction qui prend en argument la pile et qui donne struct elmt(les éléments, valeurs et coordonées): 
struct elmt prendre(PILE p);

//Fonction qui affiche la pile:
void debug(PILE p);
