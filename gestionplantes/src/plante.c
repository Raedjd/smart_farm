#include <stdio.h>
#include <stdlib.h>
#include"plante.h"
#include <string.h>
#include<gtk/gtk.h>

enum
{
 	ID,
	NOM,
	EMPLACEMENT,
	PERIODE,
	DATE,
	NOMBRE,
	TEMPS,	
	COLUMNS
};

//////////////////ajouter une plante

void ajouter_plante(plante p)
{
FILE *f;
f=fopen("plantes.txt","a+");
if (f!=NULL)
{fprintf(f,"%s %s %s %s %s %s %s  \n",p.id,p.nom,p.emplacement,p.periode,p.date,p.nombre,p.temps);

}
fclose(f);
}
////////////////fonction supprimer

void supprimer_plante (plante p)
{

char id[30];
char nom[30];
char emplacement[30];
char periode[30];
char date[30];
char nombre[20];
char temps[30];

FILE *f,*g;
	f=fopen("plantes.txt","r");
	g=fopen("plantes2.txt","w");

	if (f==NULL || g==NULL )
	return;
	else
{while(fscanf(f,"%s %s %s %s %s %s %s \n",p.id,p.nom,p.emplacement,p.periode,p.date,p.nombre,p.temps)!=EOF)
	{if(strcmp(p.id,id)!=0 || strcmp(p.nom,nom)!=0 || strcmp(p.emplacement,emplacement)!=0 || strcmp(p.periode,periode)!=0 || strcmp(p.date,date)!=0 || strcmp(p.nombre,nombre)!=0|| strcmp(p.temps,temps)!=0)
	fprintf(g,"%s %s %s %s %s %s %s \n",id,nom,emplacement,periode,date,nombre,temps);

}
fclose(f);
fclose(g);
remove("plantes.txt");
rename("plantes2.txt","plantes.txt");
}}


/////////////fonction  afficher 

void afficher_plante(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

 	char nombre[20];
	char id[20];
	char periode[20];
    	char nom[20];
	char emplacement[20];
    	char date[30];
	char temps[30];

	store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("periode",renderer,"text", PERIODE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("emplacement",renderer,"text",EMPLACEMENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
 renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("temps",renderer,"text",TEMPS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nombre",renderer,"text",NOMBRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
 


	f=fopen("plantes.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("plantes.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s ",id,nom,emplacement,periode,date,nombre,temps)!=EOF)
		{
	
           
gtk_list_store_append(store,&iter);						    gtk_list_store_set(store,&iter,ID,id,NOM,nom,EMPLACEMENT,emplacement,PERIODE,periode,DATE,date,NOMBRE,nombre,TEMPS,temps,-1);
            }
                
                    
        
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}



//////annee_seche
int valeur_max(float tab[],int n)
{
    int i,pos;
    float max;
    max=tab[0];
    for(i=1;i<n;i++)
    {
        if(tab[i]>max)
            {max=tab[i];
           pos=i;}
    }
    return pos;

}

int annee_seche(int tab_an[],float tab_temp[])
{
    FILE *f;
    int i;
    int id,j,m,a,n;
    float temp;
    f=fopen("temperature.txt","r");
    if(f!=NULL)

    {fscanf(f,"%d %d %d %d %f",&id,&j,&m,&a,&temp);
    tab_an[0]=a;
    i=1;
        while(fscanf(f,"%d %d %d %d %f",&id,&j,&m,&a,&temp)!=EOF)
           {
        if(a!=tab_an[i-1])
                        {tab_an[i]=a;
                        i++;}
           }


n=i;

rewind(f);


    while(fscanf(f,"%d %d %d %d %f",&id,&j,&m,&a,&temp)!=EOF)
{for(i=0;i<n;i++)
   { if(tab_an[i]==a)
        tab_temp[i]+=temp/365;}
}
    }
return n;
}

