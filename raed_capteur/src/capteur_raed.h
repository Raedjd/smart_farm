#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct
{
	char captID[20];
	char captMarque[20];
	char captType[20];
         int  JourCap;
         int MoisCap;
         int AnneeCap;
	 char captValMin[20];
	 char captValMax[20];
	 char captZone[20];

}capteur;


int ajouter_capt(capteur C);
int supprimer_capt(char ID[]);
int modifier_capt(capteur C);
int exist_capteur(char *id);
void rechercher_capteur(GtkWidget *liste, char ID[]);
void afficher_capteur(GtkWidget *liste);



#endif // CAPTEUR_H_INCLUDED

