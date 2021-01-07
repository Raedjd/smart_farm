#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur_raed.h"
#include <gtk/gtk.h>
int ajouter_capt(capteur C)
{
FILE *f=NULL;
f=fopen("cap.txt","a+") ;

if(f!=NULL)
{
fprintf(f,"%s %s %s %d %d %d %s %s %s \n" , C.captID , C.captMarque ,
C.captType ,C.JourCap ,C.MoisCap,C.AnneeCap,C.captValMin,C.captValMax,C.captZone );
fclose(f);
return 1;
}
else
return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int exist_capteur(char *id)
{
FILE*f=NULL;
capteur C;
f=fopen("cap.txt","r");// ouverture du fichier capteur en  mode lecture 
   while(fscanf(f, "%s %s %s %d %d %d %s %s %s \n" ,C.captID , C.captMarque ,C.captType ,&C.JourCap,&C.MoisCap,&C.AnneeCap,C.captValMin,C.captValMax,C.captZone )!=EOF)
{
if(strcmp(C.captID,id)==0)
return 1;   //id existe deja 
}
fclose(f);
return 0;
}

//////////////////////////////////////
enum
{ 
 EcaptID,
    EcaptMarque,
     EcaptType,
      EJourCap,
       EMoisCap,
        EAnneeCap,
        EcaptValMin,
        EcaptValMax,
        EcaptZone,

 COLUMNS };
void afficher_capteur(GtkWidget  *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char captID[20];
	char captMarque[20];
	char captType[20];
	int  JourCap;
	int MoisCap;
        int AnneeCap;
	char captValMin[20];
	char captValMax[20];
	char captZone[20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captID",renderer, "text",EcaptID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("captMarque",renderer,"text",EcaptMarque,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" captType",renderer, "text", EcaptType,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" JourCap",renderer, "text", EJourCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MoisCap",renderer, "text",EMoisCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("AnneeCap",renderer, "text",EAnneeCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" captValMin",renderer, "text",EcaptValMin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captValMax",renderer, "text",EcaptValMax,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captZone",renderer, "text",EcaptZone,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_INT,  G_TYPE_INT, 		G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("cap.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("cap.txt","a+");
	 	while(fscanf(f,"%s %s %s %d %d %d %s %s %s \n",captID,captMarque,captType,&JourCap,&MoisCap,&AnneeCap,captValMin,
	captValMax,captZone )!=EOF)	          						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EcaptID,captID,EcaptMarque,captMarque,EcaptType,captType,EJourCap,JourCap,
			EMoisCap,MoisCap,EAnneeCap,AnneeCap,EcaptValMin,captValMin,EcaptValMax,captValMax,EcaptZone,captZone,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

/////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
int supprimer_capt(char ID[])

{
FILE *f;
FILE *tmp;
capteur C;
f=fopen("cap.txt","r");

tmp=fopen("tempo.txt","a+");

    if (f!=NULL)
    {

  while(fscanf(f, "%s %s %s %d %d %d %s %s %s \n" ,C.captID , C.captMarque ,
C.captType ,&C.JourCap ,&C.MoisCap,&C.AnneeCap,C.captValMin,C.captValMax,C.captZone )!=EOF)
    {
	if(strcmp(C.captID,ID)!=0)
        {fprintf(tmp,"%s %s %s %d %d %d %s %s %s \n" , C.captID , C.captMarque ,
C.captType ,C.JourCap ,C.MoisCap,C.AnneeCap,C.captValMin,C.captValMax,C.captZone );
}


    }

    }
fclose(f);
fclose(tmp);
remove("cap.txt");
rename("tempo.txt","cap.txt");
return 1;
}
//////////////////////////////////////////////////////////////////////////////////////
int modifier_capt(capteur C)
{
    char id[20];	
    char marque[20];
    char type[20];
     int jours;
    int  mois;
    int annee;
    char min[20];
    char max[20];
    char zone[20];
 
	

FILE *f;
FILE *tmp;

f=fopen("cap.txt","r");
tmp=fopen("cap1.txt","a+");
while (fscanf(f,"%s %s %s %d %d %d %s %s %s \n",id,marque,type,&jours,&mois,&annee,min,max,zone)!=EOF)
{
if (strcmp(C.captID,id)==0)
	{fprintf(tmp,"%s %s %s %d %d %d %s %s %s \n" , C.captID , C.captMarque ,
C.captType ,C.JourCap ,C.MoisCap,C.AnneeCap,C.captValMin,C.captValMax,C.captZone );
}
else
	fprintf(tmp,"%s %s %s %d %d %d %s %s %s \n",id,marque,type,jours,mois,annee,min,max,zone);
}
fclose(f);
fclose(tmp);
remove("cap.txt");
rename("cap1.txt","cap.txt");
return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rechercher_capteur(GtkWidget *liste, char ID[])

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char captID[20];
	char captMarque[20];
	char captType[20];
	int  JourCap;
	int MoisCap;
        int AnneeCap;
	char captValMin[20];
	char captValMax[20];
	char captZone[20];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captID",renderer, "text",EcaptID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("captMarque",renderer,"text",EcaptMarque,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" captType",renderer, "text", EcaptType,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" JourCap",renderer, "text", EJourCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MoisCap",renderer, "text",EMoisCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("AnneeCap",renderer, "text",EAnneeCap,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" captValMin",renderer, "text",EcaptValMin,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captValMax",renderer, "text",EcaptValMax,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("captZone",renderer, "text",EcaptZone,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_INT,  G_TYPE_INT, 		G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("cap.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("cap.txt","a+");
	 	while(fscanf(f,"%s %s %s %d %d %d %s %s %s \n",captID,captMarque,captType,&JourCap,&MoisCap,&AnneeCap,captValMin,
	captValMax,captZone )!=EOF)
	          	{
            if(strcmp(captID,ID)==0)                						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EcaptID,captID,EcaptMarque,captMarque,EcaptType,captType,EJourCap,JourCap,
			EMoisCap,MoisCap,EAnneeCap,AnneeCap,EcaptValMin,captValMin,EcaptValMax,captValMax,EcaptZone,captZone,-1);
		}
                 }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
}


