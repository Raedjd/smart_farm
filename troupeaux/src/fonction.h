#include <gtk/gtk.h>
typedef struct
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct
{
char identifiant[30];
char type[30];
date naissance;
date visite;
char genre[30];
char etat[30];
} troupeaux;

void ajouter (troupeaux t );
void afficher(GtkWidget *liste);
void chercher(GtkWidget *liste, char idrech[]);
void supprimer(char idsp[]);

