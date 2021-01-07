#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"




void
on_buttonvaliderta_clicked             (GtkWidget       *objet,
                                        gpointer        user_data)
{

GtkWidget *entryaouvta;
GtkWidget *labeltauxabsafta;
GtkWidget *windowtauxabsta;
GtkWidget *treeview1;
//GtkWidget *liste;

int i,x;
float Tab[50],T[50];
char s1[20],s2[20],s3[20];
windowtauxabsta=lookup_widget(objet,"windowtauxabsta");

labeltauxabsafta=lookup_widget(objet,"labeltauxabsafta");
entryaouvta=lookup_widget(objet,"entryaouvta");
//strcpy(annee,gtk_entry_get_text(GTK_ENTRY(entryaouvta)));
sscanf(gtk_entry_get_text(GTK_ENTRY(entryaouvta)), "%d", &annee);
taux(T,annee,nb,"absenteisme.txt");

for(i=0;i<12;i++)
{
x=T[i];
sscanf(i, "%s", s1);
sscanf(x, "%s", s2);
strcpy(s3,"T[");
strcat(s3,s1);
strcat(s3,"]= ");
strcat(s3,s2);
strcat(s3,"\n");
gtk_label_set_text(GTK_LABEL(labeltauxabsafta),s3);
}

//treeview1=lookup_widget(windowtauxabsta,"treeview1");

//afficher(liste);
}

/*void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gfloat* T[50];
	gint* i;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &i, 1, &T[50],-1);
		
		afficher(treeview);
	}
}
*/
