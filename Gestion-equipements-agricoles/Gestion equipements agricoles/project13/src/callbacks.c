#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
int x_equ=1;
int y_equ=0;
int a_equ=1;
int b_equ=0;



void
on_treeview_leqag_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* reference;
	gchar* matricule;
	gchar* type;
	gchar* marque;
	gchar* fournisseur;
	gchar* etat_fct;
	gchar* garantie;
	gchar* jour_fct;
        gchar* mois_fct;
        gchar* annee_fct;
	gchar* disponibilite;
	GtkWidget *geqagr,*treeview_leqag;

	equi_agr n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &reference, 1, &matricule, 2, &type , 3, &marque, 4, &fournisseur, 5, &etat_fct , 6, &garantie , 7, &disponibilite , 8, &jour_fct , 9, &mois_fct , 10, &annee_fct ,-1);
  		strcpy(n.reference,reference);
		strcpy(n.matricule,matricule);
		strcpy(n.type,type);
                strcpy(n.marque,marque);
		strcpy(n.fournisseur,fournisseur);
		strcpy(n.etat_fonctionnement,etat_fct);
                strcpy(n.garantie,garantie);
                strcpy(n.disponibilite,disponibilite);
                n.date_mise_fct.jour=jour_fct;
                n.date_mise_fct.mois=mois_fct;
                n.date_mise_fct.annee=annee_fct;
		supprimer_equ(n.reference);
		geqagr=create_geqagr();
		gtk_widget_show(geqagr);
		treeview_leqag=lookup_widget(geqagr,"treeview_leqag");
		afficher_equ(treeview_leqag);
		gtk_widget_show(treeview_leqag);
		geqagr=lookup_widget(treeview,"geqagr");
		gtk_widget_destroy(geqagr);

                
                
                
                
}
}





void
on_button_ajteq_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Fenetregeqag;
    GtkWidget *Fenetreajeqag;
    Fenetregeqag=lookup_widget(objet,"geqagr");
    gtk_widget_destroy(Fenetregeqag);
    Fenetreajeqag=create_ajeqag();
    gtk_widget_show(Fenetreajeqag);

}


void
on_button_mdfeq_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Fenetregeqag;
    GtkWidget *Fenetremdfeqag;
    Fenetregeqag=lookup_widget(objet,"geqagr");
    gtk_widget_destroy(Fenetregeqag);
    Fenetremdfeqag=create_mdfeqag();
    gtk_widget_show(Fenetremdfeqag);

}


void
on_button_suppeq_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetregeqag;
    GtkWidget *Fenetresuppeqag;
    Fenetregeqag=lookup_widget(objet,"geqagr");
    gtk_widget_destroy(Fenetregeqag);
    Fenetresuppeqag=create_suppeqag();
    gtk_widget_show(Fenetresuppeqag);

}


void
on_button_recheq_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetregeqag;
    GtkWidget *Fenetrerecheqag;
    Fenetregeqag=lookup_widget(objet,"geqagr");
    gtk_widget_destroy(Fenetregeqag);
    Fenetrerecheqag=create_recheqag();
    gtk_widget_show(Fenetrerecheqag);
}


void
on_button_retgeq_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_affeq_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_leqag;

treeview_leqag=lookup_widget(objet,"treeview_leqag");

afficher_equ(treeview_leqag);
}


void
on_button_bscnfaj_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
equi_agr n;

  GtkWidget *Fenetreajeqag;
  GtkWidget *Fenetregeqag;
  GtkWidget *input1, *input2, *input3, *input4;
  GtkWidget *jour,*mois,*annee;
  GtkWidget *type,*etat_fct;
   


Fenetreajeqag=lookup_widget(objet,"ajeqag");
input1=lookup_widget(objet,"entry_bsrefaj");
input2=lookup_widget(objet,"entry_bsmtaj");
input3=lookup_widget(objet,"entry_bsmraj");
input4=lookup_widget(objet,"entry_bsfsaj");
type=lookup_widget(objet,"combobox_bstpaj");
etat_fct=lookup_widget(objet,"combobox_bsefctaj");
jour=lookup_widget(objet,"spinbutton_bsjdfaj");
mois=lookup_widget(objet,"spinbutton_bsmdfaj");
annee=lookup_widget(objet,"spinbutton_bsadfaj");

strcpy(n.reference,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.matricule,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(n.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(n.fournisseur,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(n.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(n.etat_fonctionnement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat_fct)));
n.date_mise_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_mise_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_mise_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(x_equ==1)
{strcpy(n.disponibilite,"oui");}
else
if(x_equ==2)
{strcpy(n.disponibilite,"non");}

if(y_equ==1)
{strcpy(n.garantie,"oui");}
else
if(y_equ==0)
{strcpy(n.garantie,"non");}

ajouter_equ(n);
x_equ=1;
y_equ=0;


    gtk_widget_destroy(Fenetreajeqag);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
}



void
on_button_bsanlaj_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Fenetregeqag;
    GtkWidget *Fenetreajeqag;
    Fenetreajeqag=lookup_widget(objet,"ajeqag");
    gtk_widget_destroy(Fenetreajeqag);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
}


void
on_radiobutton_bsoaj_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x_equ=1;
}
}




void
on_radiobutton_bsnaj_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x_equ=2;
}
}



void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{                                       
if(gtk_toggle_button_get_active(togglebutton))
{
y_equ=1;
}
}

void
on_button_bscnfmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
equi_agr n;

  GtkWidget *Fenetremdfeqag;
  GtkWidget *Fenetregeqag;
  GtkWidget *input1, *input2, *input3, *input4;
  GtkWidget *jour,*mois,*annee;
  GtkWidget *type,*etat_fct;


Fenetremdfeqag=lookup_widget(objet,"mdfeqag");
input1=lookup_widget(objet,"entry_bsrefmdf");
input2=lookup_widget(objet,"entry_bsmtmdf");
input3=lookup_widget(objet,"entry_bsmrmdf");
input4=lookup_widget(objet,"entry_bsfsmdf");
type=lookup_widget(objet,"combobox_bstpmdf");
etat_fct=lookup_widget(objet,"combobox_bsefctmdf");
jour=lookup_widget(objet,"spinbutton_bsjdfmdf");
mois=lookup_widget(objet,"spinbutton_bsmdfmdf");
annee=lookup_widget(objet,"spinbutton_bsadfmdf");


strcpy(n.reference,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.matricule,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(n.marque,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(n.fournisseur,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(n.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(n.etat_fonctionnement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat_fct)));
n.date_mise_fct.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_mise_fct.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_mise_fct.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(a_equ==1)
{strcpy(n.disponibilite,"oui");}
else
if(a_equ==2)
{strcpy(n.disponibilite,"non");}

if(b_equ==1)
{strcpy(n.garantie,"oui");}
else
if(b_equ==0)
{strcpy(n.garantie,"non");}

modifier_equ(n);
a_equ=1;
b_equ=0;


    gtk_widget_destroy(Fenetremdfeqag);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
}





void
on_button_bsanlmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetregeqag;
    GtkWidget *Fenetremdfeqag;
    Fenetremdfeqag=lookup_widget(objet,"mdfeqag");
    gtk_widget_destroy(Fenetremdfeqag);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);

}


void
on_checkbuttonbsouimdf_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
b_equ=1;
}
}

void
on_radiobutton_bsomdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a_equ=1;
}
}


void
on_radiobutton_bsnmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a_equ=2;
}
}

void
on_treeview_bstxtrech_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* reference;
	gchar* matricule;
	gchar* type;
	gchar* marque;
	gchar* fournisseur;
	gchar* etat_fct;
	gchar* garantie;
	gchar* jour_fct;
        gchar* mois_fct;
        gchar* annee_fct;
	gchar* disponibilite;

	equi_agr n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &reference, 1, &matricule, 2, &type , 3, &marque, 4, &fournisseur, 5, &etat_fct , 6, &garantie , 7, &disponibilite , 8, &jour_fct , 9, &mois_fct , 10, &annee_fct ,-1);
  		strcpy(n.reference,reference);
		strcpy(n.matricule,matricule);
		strcpy(n.type,type);
                strcpy(n.marque,marque);
		strcpy(n.fournisseur,fournisseur);
		strcpy(n.etat_fonctionnement,etat_fct);
                strcpy(n.garantie,garantie);
                strcpy(n.disponibilite,disponibilite);
                n.date_mise_fct.jour=jour_fct;
                n.date_mise_fct.mois=mois_fct;
                n.date_mise_fct.annee=annee_fct;


         afficher_equ(treeview);
          }

}


void
on_button_bsretrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

    GtkWidget *Fenetregeqag;
    GtkWidget *Fenetrerecheqag;
    Fenetrerecheqag=lookup_widget(objet,"recheqag");
    gtk_widget_destroy(Fenetrerecheqag);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
}


void
on_button_bscnfrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetrerecheqag;
   GtkWidget *ref;
   GtkWidget *treeviewrech;
   char refrech[20];
   

ref=lookup_widget(objet,"entry_bsrefrech");


strcpy(refrech,gtk_entry_get_text(GTK_ENTRY(ref)));
Fenetrerecheqag=create_recheqag();
gtk_widget_show(Fenetrerecheqag);
treeviewrech=lookup_widget(Fenetrerecheqag,"treeview_bstxtrech");
gtk_widget_show(treeviewrech);

chercher_equ(treeviewrech, refrech);
Fenetrerecheqag=lookup_widget(objet,"recheqag");
gtk_widget_destroy(Fenetrerecheqag);

}


void
on_button_cnfsuppeq_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetresuppeq;
   GtkWidget *Fenetregeqag;
   GtkWidget *ref;
   GtkWidget *output;
   char refsp[20];
   char msg[20];
   int t;
ref=lookup_widget(objet,"entry_bsrefsupp");
output=lookup_widget(objet,"label_bsspsc");
strcpy(refsp,gtk_entry_get_text(GTK_ENTRY(ref)));
t=verif_equ(refsp);
if(t!=1)
{
   strcpy(msg,"Donnée invalide");
    gtk_label_set_text(GTK_LABEL(output),msg);
}
else
{
    supprimer_equ(refsp);
    strcpy(msg,"Suppression Réussi");
    gtk_label_set_text(GTK_LABEL(output),msg);
    Fenetresuppeq=lookup_widget(objet,"suppeqag");
	gtk_widget_destroy(Fenetresuppeq);
    Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
}
   

}


void
on_button_anlsuppeq_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Fenetregeqag;
    GtkWidget *Fenetresuppeq;
	Fenetregeqag=create_geqagr();
    gtk_widget_show(Fenetregeqag);
    Fenetresuppeq=lookup_widget(objet,"suppeqag");
	gtk_widget_destroy(Fenetresuppeq);

}

