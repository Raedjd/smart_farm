#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

int x,y;

void
on_button_ajtrp_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetreajttroup;
    Fenetregtroup=lookup_widget(objet,"gtroup");
    gtk_widget_destroy(Fenetregtroup);
    Fenetreajttroup=create_ajttroup();
    gtk_widget_show(Fenetreajttroup);
}


void
on_button_afftrp_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_ltrp;

treeview_ltrp=lookup_widget(objet,"treeview_ltrp");

afficher(treeview_ltrp);
}


void
on_button_mdftrp_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetremdftroup;
    Fenetregtroup=lookup_widget(objet,"gtroup");
    gtk_widget_destroy(Fenetregtroup);
    Fenetremdftroup=create_mdftroup();
    gtk_widget_show(Fenetremdftroup);
}


void
on_button_supptrp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetresupptroup;
    Fenetregtroup=lookup_widget(objet,"gtroup");
    gtk_widget_destroy(Fenetregtroup);
    Fenetresupptroup=create_supptroup();
    gtk_widget_show(Fenetresupptroup);
}


void
on_button_retgtrp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_treeview_ltrp_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
       GtkTreeIter iter;
	gchar* identifiant;
	gchar* type;
	gchar* genre;
	gchar* etat_animal;
	gchar* j_naissance;
	gchar* m_naissance;
	gchar* a_naissance;
        gchar* j_vm;
        gchar* m_vm;
	gchar* a_vm;

	troupeaux n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &type, 2, &genre , 3, &etat_animal, 4, &j_naissance, 5, &m_naissance , 6, &a_naissance , 7, &j_vm , 8, &m_vm , 9, &a_vm ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.type,type);
                strcpy(n.genre,genre);
		strcpy(n.etat,etat_animal);
		n.naissance.jour=j_naissance;
                n.naissance.mois=m_naissance;
                n.naissance.annee=a_naissance;
                n.visite.jour=j_vm;
                n.visite.mois=m_vm;
                n.visite.annee=a_vm;
                
                
                afficher(treeview);
}
}

void
on_radiobutton_kdmajt_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}


void
on_radiobutton_kdfajt_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}
}


void
on_button_kdanlajt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetreajttroup;
    Fenetreajttroup=lookup_widget(objet,"ajttroup");
    gtk_widget_destroy(Fenetreajttroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);
}


void
on_button_kdcnfajt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)

{
  troupeaux n;
  GtkWidget *Fenetreajttroup;
  GtkWidget *Fenetregtroup;
  GtkWidget *input;
  GtkWidget *jourdn,*moisdn,*anneedn,*jourvm,*moisvm,*anneevm;
  GtkWidget *type,*etat;
{
Fenetreajttroup=lookup_widget(objet,"ajttroup");
input=lookup_widget(objet,"entry_kdidajt");
jourdn=lookup_widget(objet,"spinbutton_kdjdnajt");
moisdn=lookup_widget(objet,"spinbutton_kdmdnajt");
anneedn=lookup_widget(objet,"spinbutton_kdadnajt");
type=lookup_widget(objet,"combobox_kdtpaj");
etat=lookup_widget(objet,"combobox_kdesaj");
jourvm=lookup_widget(objet,"spinbutton_kdjdvajt");
moisvm=lookup_widget(objet,"spinbutton_kdmdvajt");
anneevm=lookup_widget(objet,"spinbutton_kdadvajt");

strcpy(n.identifiant,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(n.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(n.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
n.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourdn));
n.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisdn));
n.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneedn));
n.visite.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourvm));
n.visite.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisvm));
n.visite.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneevm));
} 
if(x==1)
{strcpy(n.genre,"Male");}
else
 if(x==2)
{strcpy(n.genre,"Femelle");}

ajouter(n);

    gtk_widget_destroy(Fenetreajttroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);

}


void
on_radiobutton_kdmmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=1;
}
}


void
on_radiobutton_kdfmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=2;
}
}


void
on_button_kdanlmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetremdftroup;
    Fenetremdftroup=lookup_widget(objet,"mdftroup");
    gtk_widget_destroy(Fenetremdftroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);
}


void
on_button_kdcnfmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
  troupeaux n;
  GtkWidget *Fenetremdftroup;
  GtkWidget *Fenetregtroup;
  GtkWidget *input;
  GtkWidget *jourdn,*moisdn,*anneedn,*jourvm,*moisvm,*anneevm;
  GtkWidget *type,*etat;
{
Fenetremdftroup=lookup_widget(objet,"mdftroup");
input=lookup_widget(objet,"entry_kdidmdf");
jourdn=lookup_widget(objet,"spinbutton_kdjdnmdf");
moisdn=lookup_widget(objet,"spinbutton_kdmdnmdf");
anneedn=lookup_widget(objet,"spinbutton_kdadnmdf");
type=lookup_widget(objet,"combobox_kdtpmdf");
etat=lookup_widget(objet,"combobox_kdesmdf");
jourvm=lookup_widget(objet,"spinbutton_kdjdvmdf");
moisvm=lookup_widget(objet,"spinbutton_kdmdvmdf");
anneevm=lookup_widget(objet,"spinbutton_kdadvmdf");

strcpy(n.identifiant,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(n.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(n.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));
n.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourdn));
n.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisdn));
n.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneedn));
n.visite.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourvm));
n.visite.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moisvm));
n.visite.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneevm));
} 
if(y==1)
{strcpy(n.genre,"Male");}
else
 if(y==2)
{strcpy(n.genre,"Femelle");}
 
modifier(n);
 
    gtk_widget_destroy(Fenetremdftroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);
}


void
on_treeview_kdtxtrech_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
       GtkTreeIter iter;
	gchar* identifiant;
	gchar* type;
	gchar* genre;
	gchar* etat_animal;
	gchar* j_naissance;
	gchar* m_naissance;
	gchar* a_naissance;
        gchar* j_visite;
        gchar* m_visite;
	gchar* a_visite;

	troupeaux n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &type, 2, &genre , 3, &etat_animal, 4, &j_naissance, 5, &m_naissance , 6, &a_naissance , 7, &j_visite , 8, &m_visite , 9, &a_visite ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.type,type);
                strcpy(n.genre,genre);
		strcpy(n.etat,etat_animal);
		n.naissance.jour=j_naissance;
                n.naissance.mois=m_naissance;
                n.naissance.annee=a_naissance;
                n.visite.jour=j_visite;
                n.visite.mois=m_visite;
                n.visite.annee=a_visite;
                
                
                afficher(treeview);
}
}


void
on_button_kdretrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *Fenetregtroup;
    GtkWidget *Fenetrerechtroup;
    Fenetrerechtroup=lookup_widget(objet,"rechtroup");
    gtk_widget_destroy(Fenetrerechtroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);
}


void
on_button_kdcnfrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetrerechtroup;
   GtkWidget *id;
   GtkWidget *treeviewrech;
   char idrech[20];
   
Fenetrerechtroup=lookup_widget(objet,"rechtroup");
id=lookup_widget(objet,"entry_kdidrech");
treeviewrech=lookup_widget(objet,"treeview_kdtxtrech");

strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(id)));

chercher(treeviewrech, idrech);
}


void
on_button_khcnfsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetresupptroup;
   GtkWidget *Fenetregtroup;
   GtkWidget *id;
   GtkWidget *output;
   char idsp[20];
id=lookup_widget(objet,"entry_khidsp");
strcpy(idsp,gtk_entry_get_text(GTK_ENTRY(id)));
supprimer(idsp);

    gtk_widget_destroy(Fenetresupptroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);

}


void
on_button_khanlsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregtroup;
    GtkWidget *Fenetresupptroup;
    Fenetresupptroup=lookup_widget(objet,"supptroup");
    gtk_widget_destroy(Fenetresupptroup);
    Fenetregtroup=create_gtroup();
    gtk_widget_show(Fenetregtroup);
}


void
on_button_kdgrch_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
     GtkWidget *Fenetregtroup;
    GtkWidget *Fenetrerechtroup;
    Fenetregtroup=lookup_widget(objet,"gtroup");
    gtk_widget_destroy(Fenetregtroup);
    Fenetrerechtroup=create_rechtroup();
    gtk_widget_show(Fenetrerechtroup);
}

