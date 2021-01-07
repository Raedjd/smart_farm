#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

enum
{
	EID,
	EPRENOM,
	ENOM,
	ESEXE,
	EAGE,
	ENUMTEL,
	EJ,
	EM,
	EA,
	COLUMNS,
};

void ajouter(client c)
{
   FILE *f;
f=fopen("clients.txt","a+") ;
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %d %d %d \n",c.id,c.prenom,c.nom,c.mdp,c.numtel,c.sexe,c.age,c.da.j,c.da.m,c.da.a);
fclose(f);
}
}

void rechercher(GtkWidget *liste,char rech[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
	char nom[30];
	char prenom[30];
	char sexe[10];
	char mdp[30];
	char age[20];
	char numtel[20];
	int j;
	int m;
	int a;

FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("numtel",renderer,"text",ENUMTEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("age",renderer,"text",EAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("j",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("m",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("a",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

    f=fopen("clients.txt","r");
    if (f == NULL)
    {
      return;
    }
else
{
f=fopen("clients.txt","a+");
while (fscanf (f,"%s %s %s %s %s %s %s %d %d %d \n",id,prenom,nom,mdp,numtel,sexe,age,&j,&m,&a)!=EOF)
{
if ( strcmp(rech,id)!=0 || strcmp(rech,prenom)!=0 || strcmp(rech,nom)!=0 || strcmp(rech,strcat(strcat(prenom," "),nom))!=0 || strcmp(rech,strcat(strcat(nom," "),prenom))!=0 )
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,EID,id,EPRENOM,prenom,ENOM,nom,ENUMTEL,numtel,ESEXE,sexe,EAGE,age,EJ,&j,EM,&m,EA,&a,-1);
}
}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}
}

void supprimer(client c)
{
client c2;
FILE *f,*g;
f=fopen("clients.txt","r");
g=fopen("tempo.txt","w");

    if (f==NULL || g==NULL)
     return;
else
{
    while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d \n",c2.id,c2.prenom,c2.nom,c2.mdp,c2.numtel,c2.sexe,c2.age,&c2.da.j,&c2.da.m,&c2.da.a)!=EOF)
    {
	if(strcmp(c2.id,c.id)!=0)
fprintf(g,"%s %s %s %s %s %s %s %d %d %d \n",c2.id,c2.prenom,c2.nom,c2.mdp,c2.numtel,c2.sexe,c2.age,c2.da.j,c2.da.m,c2.da.a);
    }
    }

fclose(f);
fclose(g);
remove("clients.txt");
rename("tempo.txt","clients.txt");
}

void modifier(client c)
{

FILE *f;
FILE *g;
client c2;

f=fopen("clients.txt","r");
g=fopen("tempo.txt","a");

    if ( f==NULL || g==NULL )
    return;
    else
    {
    while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d \n",c2.id,c2.prenom,c2.nom,c2.mdp,c2.numtel,c2.sexe,c2.age,&c2.da.j,&c2.da.m,&c2.da.a)!=EOF)
    {
	if(strcmp(c2.id,c.id)!=0)
        {

fprintf(g,"%s %s %s %s %s %s %s %d %d %d \n",c2.id,c2.prenom,c2.nom,c2.mdp,c2.numtel,c2.sexe,c2.age,c2.da.j,c2.da.m,c2.da.a);
}
else
fprintf(g,"%s %s %s %s %s %s %s %d %d %d \n",c.id,c.prenom,c.nom,c.mdp,c.numtel,c.sexe,c.age,c.da.j,c.da.m,c.da.a);
    }
    }

fclose(g);
fclose(f);
remove("clients.txt");
rename("tempo.txt","clients.txt");
}

void afficher(GtkWidget *liste)
{
    	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[20];
	char nom[30];
	char prenom[30];
	char sexe[10];
	char mdp[30];
	char age[20];
	char numtel[20];
	int *j;
	int *m;
	int *a;

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numtel",renderer,"text",ENUMTEL,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Age",renderer,"text",EAGE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
    
    f=fopen("clients.txt","r");
    if (f ==NULL)
    {
      return;
    }
else
{
f=fopen("clients.txt","a+");
while (fscanf (f,"%s %s %s %s %s %s %s %d %d %d \n",id,prenom,nom,mdp,numtel,sexe,age,&j,&m,&a)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter,EID,id,EPRENOM,prenom,ENOM,nom,ENUMTEL,numtel,ESEXE,sexe,EAGE,age,EJ,&j,EM,&m,EA,&a,-1);

}
fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}
}

/*void taux(float T[],int nb,int annee)
{
int j,m,a,id,val,i;
FILE *f;
    for (i=0;i<12;i++)
	T[i]=0; 
f=fopen("absenteisme.txt","r");
if (f != NULL)
{
while(fscanf(f,"%d %d %d %d %d",&id,&j,&m,&a,&val)!=EOF)
{ if(a==annee && val==0)
(m-1)++;
}
}
for (i=0;i<12;i++)
T[i]=T[i]/12;
    
}
}
*/
