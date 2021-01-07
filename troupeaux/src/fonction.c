#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "fonction.h"
#include <gtk/gtk.h>

enum
{
    EIDENTIFIANT,
    ETYPE,
    EGENRE,
    EETAT_ANIMAL,
    EJOUR_DN,
    EMOIS_DN,
    EANNEE_DN,
    EJOUR_VM,
    EMOIS_VM,
    EANNEE_VM,
    
    COLUMNS,
};
void ajouter(troupeaux t)
{
FILE*f=NULL; 
f=fopen("liste_troupeaux.txt","a");
fprintf(f,"%s %s %s %s %d %d %d %d %d %d\n",t.identifiant,t.type,t.genre,t.etat,t.naissance.jour,t.naissance.mois,t.naissance.annee,t.visite.jour,t.visite.mois,t.visite.annee);
fclose(f);
}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char type[20];
char genre[20];
char etat_animal[20];
char jour_dn[20];
char mois_dn[20];
char annee_dn[20];
char jour_vm[20];
char mois_vm[20];
char annee_vm[20];



store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",EGENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_animal",renderer,"text",EETAT_ANIMAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_dn",renderer,"text",EJOUR_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_dn",renderer,"text",EMOIS_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_dn",renderer,"text",EANNEE_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_vm",renderer,"text",EJOUR_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_vm",renderer,"text",EMOIS_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_vm",renderer,"text",EANNEE_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_troupeaux.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_troupeaux.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",identifiant,type,genre,etat_animal,jour_dn,mois_dn,annee_dn,jour_vm,mois_vm,annee_vm)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ETYPE,type,EGENRE,genre,EETAT_ANIMAL,etat_animal,EJOUR_DN,jour_dn,EMOIS_DN,mois_dn,EANNEE_DN,annee_dn,EJOUR_VM,jour_vm,EMOIS_VM,mois_vm,EANNEE_VM,annee_vm,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void chercher(GtkWidget *liste, char idrech[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char type[20];
char genre[20];
char etat_animal[20];
char jour_dn[20];
char mois_dn[20];
char annee_dn[20];
char jour_vm[20];
char mois_vm[20];
char annee_vm[20];



store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("genre",renderer,"text",EGENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_animal",renderer,"text",EETAT_ANIMAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_dn",renderer,"text",EJOUR_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_dn",renderer,"text",EMOIS_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_dn",renderer,"text",EANNEE_DN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_vm",renderer,"text",EJOUR_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_vm",renderer,"text",EMOIS_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_vm",renderer,"text",EANNEE_VM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_troupeaux.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_troupeaux.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",identifiant,type,genre,etat_animal,jour_dn,mois_dn,annee_dn,jour_vm,mois_vm,annee_vm)!=EOF)
		{
                  if(strcmp(identifiant,idrech)==0)
                { 
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ETYPE,type,EGENRE,genre,EETAT_ANIMAL,etat_animal,EJOUR_DN,jour_dn,EMOIS_DN,mois_dn,EANNEE_DN,annee_dn,EJOUR_VM,jour_vm,EMOIS_VM,mois_vm,EANNEE_VM,annee_vm,-1);
		}
                }
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void supprimer(char idsp[])
{
FILE *f;
FILE *f1;
troupeaux n;
f=fopen("liste_troupeaux.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",n.identifiant,n.type,n.genre,n.etat,&n.naissance.jour,&n.naissance.mois,&n.naissance.annee,&n.visite.jour,&n.visite.mois,&n.visite.annee)
!=EOF)
{
	if (strcmp(n.identifiant,idsp)!=0)	
	fprintf(f1,"%s %s %s %s %d %d %d %d %d %d\n",n.identifiant,n.type,n.genre,n.etat,n.naissance.jour,n.naissance.mois,n.naissance.annee,n.visite.jour,n.visite.mois,n.visite.annee);

}
fclose(f);
fclose(f1);
remove("liste_troupeaux.txt");
rename("doc.txt","liste_troupeaux.txt");
}

void modifier(troupeaux n)
{
char id1[20];
char type1[20];
char genre1[20];
char etat_animal1[20];
int jour_dn;
int mois_dn;
int annee_dn;
int jour_vm;
int mois_vm;
int annee_vm;
	

FILE *f;
FILE *f1;

f=fopen("liste_troupeaux.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %s %s %s %d %d %d %d %d %d\n",id1,type1,genre1,etat_animal1,&jour_dn,&mois_dn,&annee_dn,&jour_vm,&mois_vm,&annee_vm)!=EOF)
{
if (strcmp(n.identifiant,id1)==0)
	fprintf(f1,"%s %s %s %s %d %d %d %d %d %d\n",n.identifiant,n.type,n.genre,n.etat,n.naissance.jour,n.naissance.mois,n.naissance.annee,n.visite.jour,n.visite.mois,n.visite.annee);

else
	fprintf(f1,"%s %s %s %s %d %d %d %d %d %d\n",id1,type1,genre1,etat_animal1,jour_dn,mois_dn,annee_dn,jour_vm,mois_vm,annee_vm);
}
fclose(f);
fclose(f1);
remove("liste_troupeaux.txt.txt");
rename("modif.txt","liste_troupeaux.txt");
}

