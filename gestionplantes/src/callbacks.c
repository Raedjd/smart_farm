#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "plante.h"
int x=0;

void
on_radio1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_radio2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_radio3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=3;}
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_affiche;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

gtk_widget_destroy(fenetre_ajout);
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");
fenetre_affiche=create_fenetre_affiche();

gtk_widget_show(fenetre_affiche);

treeview1=lookup_widget(fenetre_affiche,"treeview1");
afficher_plante(treeview1);

}


void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
int j,m,an,per;
char texte1[30]="8:00=>10:00";


plante p;

GtkWidget *Radio1;
GtkWidget *Radio2;
GtkWidget *Radio3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *input1, *input2 , *input4 , *input6 , *input3  ;
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet,"fenetre_ajout");

Radio1=lookup_widget(objet,"radio1");
Radio2=lookup_widget(objet,"radio2");
Radio3=lookup_widget(objet,"radio3");
input3=lookup_widget(objet,"emplacement");
Jour=lookup_widget(objet,"jour");
Mois=lookup_widget(objet,"mois");
Annee=lookup_widget(objet,"annee");
input1=lookup_widget(objet,"id");
input2=lookup_widget(objet,"nom");
input4=lookup_widget(objet,"periode");
input6=lookup_widget(objet,"nombre");
// radio button 
if(x==1)
strcpy(texte1,"8:00=>10:00");
else
if(x==2)
strcpy(texte1,"11:00=>16:00");
else
if(x==3)
strcpy(texte1,"17:00=>19:00");


strcpy(p.temps,texte1);
//spin button
j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
an=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));
per=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(input4));

sprintf(p.date,"%d/%d/%d",j,m,an);
sprintf(p.periode,"%d",per);

// combobox
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"A")==0)
strcpy(p.emplacement,"A");
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"B")==0)
strcpy(p.emplacement,"B");
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"C")==0)
strcpy(p.emplacement,"C");
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"D")==0)
strcpy(p.emplacement,"D");
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"E")==0)
strcpy(p.emplacement,"E");
if(strcmp(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)),"F")==0)
strcpy(p.emplacement,"F");
//text input
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.nombre,gtk_entry_get_text(GTK_ENTRY(input6)));

ajouter_plante(p);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* nom;
gchar* emplacement;
gchar* periode;
gchar* date;
gchar* nombre;
gchar* temps;
plante p;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&emplacement,3,&periode,4,&date,5,&nombre,6,&temps,-1);
		strcpy(p.id,id);
		strcpy(p.nom,nom);
		strcpy(p.emplacement,emplacement);
		strcpy(p.periode,periode);
		strcpy(p.date,date);
		strcpy(p.temps,temps);		
		supprimer_plante(p);
		afficher_plante(treeview);
	}

}


void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_affiche;
fenetre_affiche=lookup_widget(objet,"fenetre_affiche");

gtk_widget_destroy(fenetre_affiche);
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);

}


void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

}










void
on_showbutton_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
int tab_an[100];
float tab_temp[100]={0};

GtkWidget *output;
int i;
int pos;
int n;
char ch1[100]="";
char ch2[100]="";
char aff[1000];
n=annee_seche(tab_an,tab_temp);
pos=valeur_max(tab_temp,n);
output=lookup_widget(objet,"label21");
for(i=0;i<n;i++)
{sprintf(ch2,"%d\n",tab_an[i]);
strcat(ch1,ch2);}
sprintf(aff,"Les annees pris en consideration par cette recherche sont:\n%s \nL'annee plus seche est %d ",ch1,tab_an[pos]);
gtk_label_set_text(GTK_LABEL(output),aff);
}

