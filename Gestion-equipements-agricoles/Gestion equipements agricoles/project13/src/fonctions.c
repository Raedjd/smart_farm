#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
    EREFERENCE,
    EMATRICULE,
    ETYPE,
    EMARQUE,
    EFOURNISSEUR,
    EETAT_FCT,
    EGARANTIE,
    EJOUR_FCT,
    EMOIS_FCT,
    EANNEE_FCT,
    EDISPONIBILITE,
    COLUMNS,
};

    
void ajouter_equ(equi_agr n)
{

 FILE *f;
 f=fopen("liste_des_equipements_agricoles.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s %s %s %d %d %d\n",n.reference,n.matricule,n.type,n.marque,n.fournisseur,n.etat_fonctionnement,n.garantie,n.disponibilite,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

 fclose(f);
 }

}

void afficher_equ(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char reference[20];
char matricule[20];
char type[20];
char marque[20];
char fournisseur[20];
char etat_fct[20];
char garantie[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];
char disponibilite[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",EMATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("fournisseur",renderer,"text",EFOURNISSEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_fct",renderer,"text",EETAT_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("garantie",renderer,"text",EGARANTIE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("disponibilite",renderer,"text",EDISPONIBILITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_fct",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_fct",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_fct",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_equipements_agricoles.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_equipements_agricoles.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",reference,matricule,type,marque,fournisseur,etat_fct,garantie,disponibilite,jour_fct,mois_fct,annee_fct)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EREFERENCE,reference,EMATRICULE,matricule,ETYPE,type,EMARQUE,marque,EFOURNISSEUR,fournisseur,EETAT_FCT,etat_fct,EGARANTIE,garantie,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,EDISPONIBILITE,disponibilite,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void chercher_equ(GtkWidget *liste, char ref[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char reference[20];
char matricule[20];
char type[20];
char marque[20];
char fournisseur[20];
char etat_fct[20];
char garantie[20];
char jour_fct[20];
char mois_fct[20];
char annee_fct[20];
char disponibilite[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",EMATRICULE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("fournisseur",renderer,"text",EFOURNISSEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("etat_fct",renderer,"text",EETAT_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("garantie",renderer,"text",EGARANTIE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("disponibilite",renderer,"text",EDISPONIBILITE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	
	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_fct",renderer,"text",EJOUR_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_fct",renderer,"text",EMOIS_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_fct",renderer,"text",EANNEE_FCT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_equipements_agricoles.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_equipements_agricoles.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",reference,matricule,type,marque,fournisseur,etat_fct,garantie,disponibilite,jour_fct,mois_fct,annee_fct)!=EOF)
		{
            if(strcmp(reference,ref)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EREFERENCE,reference,EMATRICULE,matricule,ETYPE,type,EMARQUE,marque,EFOURNISSEUR,fournisseur,EETAT_FCT,etat_fct,EGARANTIE,garantie,EJOUR_FCT,jour_fct,EMOIS_FCT,mois_fct,EANNEE_FCT,annee_fct,EDISPONIBILITE,disponibilite,-1);
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void modifier_equ(equi_agr n)
{
    char reference1[20];	
    char matricule1[20];
    char type1[20];
    char marque1[20];
    char fournisseur1[20];
    char garantie1[20];
    char disponibilite1[20];
    char etat_fonctionnement1[20];
    int jdf;
    int mdf;
    int adf;
	

FILE *f;
FILE *f1;

f=fopen("liste_des_equipements_agricoles.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",reference1,matricule1,type1,marque1,fournisseur1,etat_fonctionnement1,garantie1,disponibilite1,&jdf,&mdf,&adf)!=EOF)
{
if (strcmp(n.reference,reference1)==0)
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",n.reference,n.matricule,n.type,n.marque,n.fournisseur,n.etat_fonctionnement,n.garantie,n.disponibilite,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

else
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",reference1,matricule1,type1,marque1,fournisseur1,etat_fonctionnement1,garantie1,disponibilite1,jdf,mdf,adf);

}
fclose(f);
fclose(f1);
remove("liste_des_equipements_agricoles.txt");
rename("modif.txt","liste_des_equipements_agricoles.txt");
}

void supprimer_equ(char refsp[])
{
FILE *f;
FILE *f1;
equi_agr n;
f=fopen("liste_des_equipements_agricoles.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",n.reference,n.matricule,n.type,n.marque,n.fournisseur,n.etat_fonctionnement,n.garantie,n.disponibilite,&n.date_mise_fct.jour,&n.date_mise_fct.mois,&n.date_mise_fct.annee)!=EOF)
{
	if (strcmp(n.reference,refsp)!=0)	
	fprintf(f1,"%s %s %s %s %s %s %s %s %d %d %d\n",n.reference,n.matricule,n.type,n.marque,n.fournisseur,n.etat_fonctionnement,n.garantie,n.disponibilite,n.date_mise_fct.jour,n.date_mise_fct.mois,n.date_mise_fct.annee);

}
fclose(f);
fclose(f1);
remove("liste_des_equipements_agricoles.txt");
rename("doc.txt","liste_des_equipements_agricoles.txt");
}


int verif_equ(char ref[])
{
    
    FILE *f=NULL;
    equi_agr n;
    int test;
    f=fopen("liste_des_equipements_agricoles.txt","r");
    test=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %s %s %s %d %d %d \n",n.reference,n.matricule,n.type,n.marque,n.fournisseur,n.etat_fonctionnement,n.garantie,n.disponibilite,&n.date_mise_fct.jour,&n.date_mise_fct.mois,&n.date_mise_fct.annee)!=EOF)
       {
         if(strcmp(n.reference,ref)==0)
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}

