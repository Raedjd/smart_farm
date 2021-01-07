#include <gtk/gtk.h>
typedef struct
{
   int jour;
   int mois;
   int annee;
}date;

typedef struct
{
    char matricule[20];
    char type[20];
    char marque[20];
    char fournisseur[20];
    char garantie[20];
    date date_mise_fct;
    char reference[20];
    char disponibilite[20];
    char etat_fonctionnement[20];
}equi_agr;


void ajouter_equ(equi_agr n);
void afficher_equ(GtkWidget *liste);
void supprimer_equ(char refsp[]);
void modifier_equ(equi_agr n);
void chercher_equ(GtkWidget *liste, char ref[]);
int verif_equ(char ref[]);



