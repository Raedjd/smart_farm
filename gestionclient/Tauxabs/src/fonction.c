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
	ENUM,
	ETA,
};

/*void afficher (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int i;
	float T[50];
	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("#mois", renderer, "text",ENUM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Taux abs", renderer, "text",ETA,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 
	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_INT, G_TYPE_float);
	for (i=1;i<13;i++)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, ENUM, &i, ETA, &T[i], -1);
		}
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);

}
*/
void taux(float T[],int annee,int nb,char *fichier)
{
float tab[50];
int j,m,a,id,val,i;
FILE *f;
nb=9;
    for (i=0;i<12;i++)
{
	T[i]=0;
	tab[i]=0;
}
f=fopen(fichier,"r");
if (f != NULL)
{
while(fscanf(f,"%d %d %d %d %d",&id,&j,&m,&a,&val)!=EOF)
{ 
if(a==annee && val==0)
{
for(i=1;i<13;i++)
{
if(m==i)
tab[i]++;
}
}  
}
}
for(i=0;i<12;i++)
T[i]=(tab[i]/(30*nb))*100;
fclose(f);
}

