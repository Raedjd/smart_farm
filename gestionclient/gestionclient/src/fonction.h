#ifndef HEADER_H
#define HEADER_H
#include <string.h>
#include <gtk/gtk.h>

char rech[30];

typedef struct
{
int j;
int m;
int a;
}date;

typedef struct
{
char id[20];
char nom[30];
char prenom[30];
char sexe[10];
char age[20];
char numtel[20];
char mdp[30];
date da;
}client;

void ajouter(client c);
void supprimer(client c);
void rechercher(GtkWidget *liste,char rech[]);
void modifier(client c);
void afficher(GtkWidget *liste);
//void taux(float T[],char *f,int nb,int annee);

#endif // HEADER_H
