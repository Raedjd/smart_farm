#ifndef HEADER_H
#define HEADER_H
#include <string.h>
#include <gtk/gtk.h>

//float T[50];
int nb;
int annee;

void afficher (GtkWidget *liste);
void taux(float T[],int annee,int nb,char *fichier);

#endif // HEADER_H
