
#include<gtk/gtk.h>


//annee plus seche 
int valeur_max(float tab[],int n);
int annee_seche(int tab_an[],float tab_temp[]);



//reste


typedef struct 
{
	char id[20];
	char nom [20];
	char emplacement[20];
	char nombre[20];	
	char periode[20];
	char date[20];	
	char temps[20];
	
}plante;

void ajouter_plante(plante p);
void supprimer_plante (plante p);
void afficher_plante(GtkWidget *liste);




