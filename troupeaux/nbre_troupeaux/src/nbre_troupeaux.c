#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "nbre_troupeaux.h"
void nbre_troupeaux(int *n_brebi,int *n_veau)
{
char id[20];
char type[20];
char genre[20];
char etat_animal[20];
int jour_dn;
int mois_dn;
int annee_dn;
int jour_vm;
int mois_vm;
int annee_vm;
FILE *f=fopen("liste_troupeaux.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d",id,type,genre,etat_animal,&jour_dn,&mois_dn,&annee_dn,&jour_vm,&mois_vm,&annee_vm)!=EOF)
{if(strcmp(type,"Brebi")==0)
(*n_brebi)++;
else
(*n_veau)++;
}
fclose(f);
}
}


