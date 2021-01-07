#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouvrier.h"
#include <stdlib.h>

GtkWidget *FTfenetre_erreur;
void
on_FTafficher_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(button,"FTfenetre_ajout");
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
fenetre_afficher=create_FTfenetre_afficher();
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(fenetre_ajout);

treeview1=lookup_widget(fenetre_afficher,"FTtreeview1");
afficher_ouv(treeview1);


}

int choix_ouv=0; 
int *c=&choix_ouv;
void
on_FTajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
ouv p;
GtkWidget *input1, *input2 ,*input3,*input5;
GtkWidget *combobox1,*combobox2,*combobox3,*output;
GtkWidget *fenetre_ajout;
char s[20];
char j[20];
char m[20];
char an[20];
resultat_ouv(choix_ouv,s);

input1=lookup_widget(button,"FTcin");
input2=lookup_widget(button,"FTnom");
input3=lookup_widget(button,"FTprenom");
input5=lookup_widget(button,"FTadresse");
combobox1=lookup_widget(button,"FTcomboboxj");
combobox2=lookup_widget(button,"FTcomboboxm");
combobox3=lookup_widget(button,"FTcomboboxan");
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(m,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(an,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
sprintf(p.date_naissance,"%s/%s/%s",j,m,an);
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.sexe,s);


if(verif_id_ouv(p.cin))
{ajouter_ouv(p);
*c=0;}
else
{FTfenetre_erreur=create_FTFenetre_erreur();
gtk_widget_show(FTfenetre_erreur);
output=lookup_widget(FTfenetre_erreur,"FTlabel49");
gtk_label_set_text(GTK_LABEL(output),"L'id tapé est deja reservé");}









}




void
on_FTtreeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkWidget *FTfenetre_afficher,*treeview1;
GtkTreeIter iter;
gchar *nom;
gchar *prenom;
gchar *date;
gchar *adresse;
gchar *cin;
gchar *sexe;
ouv p;


GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&date,4,&adresse,5,&sexe,-1);

strcpy(p.cin,cin);
strcpy(p.nom,nom);
strcpy(p.prenom,prenom);
strcpy(p.date_naissance,date);
strcpy(p.adresse,adresse);
strcpy(p.sexe,sexe);
	
supprimer_ouv(p.cin);
FTfenetre_afficher=create_FTfenetre_afficher();
gtk_widget_show(FTfenetre_afficher);
treeview1=lookup_widget(FTfenetre_afficher,"FTtreeview1");
afficher_ouv(treeview1);
FTfenetre_afficher=lookup_widget(treeview,"FTfenetre_afficher");
gtk_widget_destroy(FTfenetre_afficher);


}

}


void
on_FTretour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout, *fenetre_afficher;
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
fenetre_ajout=lookup_widget(button,"FTfenetre_ajout");
fenetre_ajout=create_FTfenetre_ajout();
gtk_widget_show(fenetre_ajout);
gtk_widget_destroy(fenetre_afficher);
}

int confirmer_ouv=0;
int *confirm_ouv=&confirmer_ouv;
void
on_FTbutton_supp_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *input,*treeview,*output;
GtkWidget *fenetre_afficher;
ouv p;
input=lookup_widget(button,"FTentry_supp");
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input)));
if(!verif_id_ouv(p.cin))
{if(confirmer_ouv)
{supprimer_ouv(p.cin);
confirmer_ouv=0;
fenetre_afficher=create_FTfenetre_afficher();
treeview=lookup_widget(fenetre_afficher,"FTtreeview1");
gtk_widget_show(fenetre_afficher);
afficher_ouv(treeview);
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
gtk_widget_destroy(fenetre_afficher);}}
else
{FTfenetre_erreur=create_FTFenetre_erreur();
gtk_widget_show(FTfenetre_erreur);
output=lookup_widget(FTfenetre_erreur,"FTlabel49");
gtk_label_set_text(GTK_LABEL(output),"L'id saisie est inexistant");}



}

void
on_FTcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
*confirm_ouv=1;
else
*confirm_ouv=0;

}


void
on_FTbutton_actualiser_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview1;
GtkWidget *fenetre_afficher;




fenetre_afficher=create_FTfenetre_afficher();
gtk_widget_show(fenetre_afficher);

treeview1=lookup_widget(fenetre_afficher,"FTtreeview1");
afficher_ouv(treeview1);
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
}
ouv tab_ouv[1000];
int n_tab;

void
on_FTbuttonvalider_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *input,*output;
int annee;
char id[20];
char texte[1000]="";
n_tab=charger_liste(tab_ouv,n_tab);
input=lookup_widget(button,"FTspinbutton");
annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
meilleur_ouv(tab_ouv,n_tab,"absenteisme.txt",annee,id);
rechercher_ouv("ouvrier.txt",texte, id);
output=lookup_widget(button,"label_affichage");
gtk_label_set_text(GTK_LABEL(output),texte);


}


void
on_FTmodifier_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

ouv p;
GtkWidget *input1, *input2 ,*input3,*input4,*input5,*input6,*treeview;
GtkWidget *fenetre_afficher;
input1=lookup_widget(button,"FTcin_modif");
input2=lookup_widget(button,"FTnom_modif");
input3=lookup_widget(button,"FTprenom_modif");
input4=lookup_widget(button,"FTdate_naissance_modif");
input5=lookup_widget(button,"FTadresse_modif");
input6=lookup_widget(button,"FTcombobox");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
rech_modif(&p);
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input2)),"")!=0)
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input3)),"")!=0)
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input4)),"")!=0)
strcpy(p.date_naissance,gtk_entry_get_text(GTK_ENTRY(input4)));
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input5)),"")!=0)
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6))!=NULL)
{if(strcmp("Male",gtk_combo_box_get_active_text(GTK_COMBO_BOX(input6)))==0)
strcpy(p.sexe,"Male");
else
strcpy(p.sexe,"Femelle");}
modifier_ouv(p);
fenetre_afficher=create_FTfenetre_afficher();
treeview=lookup_widget(fenetre_afficher,"FTtreeview1");
gtk_widget_show(fenetre_afficher);
afficher_ouv(treeview);
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
}




void
on_FTradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
*c=0;

}


void
on_FTradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*c=1;
}




void
on_FTbuttonabs_clicked                 (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *FTfenetre_abs;
GtkWidget *fenetre_afficher;
GtkWidget *treeview2;

fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
FTfenetre_abs=lookup_widget(button,"FTfenetre_abs");
FTfenetre_abs=create_FTfenetre_abs();
gtk_widget_show(FTfenetre_abs);
gtk_widget_destroy(fenetre_afficher);

treeview2=lookup_widget(FTfenetre_abs,"FTtreeview2");
afficher_abs(treeview2);

}

int a_ouv;
int *w=&a_ouv;
ouv tab2[1000];
int n2;
void
on_FTbuttonmarquer_clicked             (GtkWidget      *button,
                                        gpointer         user_data)
{
int i;
ouv_abs p;
GtkWidget *input1, *input2 ,*input3,*input4;
GtkWidget *FTfenetre_abs,*treeview2,*combobox;
char prs[20];
int j,m,an;
res_ouv(a_ouv,prs);

input1=lookup_widget(button,"FTcomboboxid");
input2=lookup_widget(button,"FTspinbuttonj");
input3=lookup_widget(button,"FTspinbuttonm");
input4=lookup_widget(button,"FTspinbuttona");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
an=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
sprintf(p.jour,"%d",j);
sprintf(p.mois,"%d",m);
sprintf(p.annee,"%d",an);
strcpy(p.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(p.pres,prs);
ajouter_abs(p);
*w=0;
FTfenetre_abs=create_FTfenetre_abs();
gtk_widget_show(FTfenetre_abs);
n2=charger_liste(tab2,n2);
combobox=lookup_widget(FTfenetre_abs,"FTcomboboxid");
for(i=0;i<n2;i++)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),tab2[i].cin);
treeview2=lookup_widget(FTfenetre_abs,"FTtreeview2");
afficher_abs(treeview2);
FTfenetre_abs=lookup_widget(button,"FTfenetre_abs");
gtk_widget_destroy(FTfenetre_abs);

}


void
on_FTbuttonreturn_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *FTfenetre_abs, *fenetre_afficher,*treeview1;
FTfenetre_abs=lookup_widget(button,"FTfenetre_abs");
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
fenetre_afficher=create_FTfenetre_afficher();
gtk_widget_show(fenetre_afficher);
gtk_widget_destroy(FTfenetre_abs);
treeview1=lookup_widget(fenetre_afficher,"FTtreeview1");
afficher_ouv(treeview1);

}
void
on_FTbuttonrefresh_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *FTtreeview2;
GtkWidget *FTfenetre_abs;
GtkWidget *combobox;
int i;
FTfenetre_abs=create_FTfenetre_abs();
gtk_widget_show(FTfenetre_abs);
n2=charger_liste(tab2,n2);
combobox=lookup_widget(FTfenetre_abs,"FTcomboboxid");
for(i=0;i<n2;i++)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),tab2[i].cin);


FTtreeview2=lookup_widget(FTfenetre_abs,"FTtreeview2");
afficher_abs(FTtreeview2);
FTfenetre_abs=lookup_widget(button,"FTfenetre_abs");
gtk_widget_destroy(FTfenetre_abs);

}




void
on_FTbuttoncharger_id_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{ GtkWidget *combobox;
int i;
n2=charger_liste(tab2,n2);
combobox=lookup_widget(button,"FTcomboboxid");
for(i=0;i<n2;i++)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),tab2[i].cin);
}


void
on_FTradiobutton_pres_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
*w=1;


}


void
on_FTradiobutton_abs_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
*w=0;

}


void
on_FTtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{GtkWidget *FTfenetre_abs,*treeview2,*combobox;
GtkTreeIter iter;
gchar *id;
gchar *jour;
gchar *mois;
gchar *annee;
gchar *prs;
ouv_abs p;
int i;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&jour,2,&mois,3,&annee,4,&prs,-1);
strcpy(p.id,id);
strcpy(p.jour,jour);
strcpy(p.mois,mois);
strcpy(p.annee,annee);
strcpy(p.pres,prs);



	
supprimer_abs(p);
FTfenetre_abs=create_FTfenetre_abs();
gtk_widget_show(FTfenetre_abs);
n2=charger_liste(tab2,n2);
combobox=lookup_widget(FTfenetre_abs,"FTcomboboxid");
for(i=0;i<n2;i++)
gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),tab2[i].cin);
treeview2=lookup_widget(FTfenetre_abs,"FTtreeview2");
afficher_abs(treeview2);
FTfenetre_abs=lookup_widget(treeview,"FTfenetre_abs");
gtk_widget_destroy(FTfenetre_abs);

}
}


void
on_FTbuttonrech_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
char id[30];
GtkWidget *fenetre_afficher,*input,*output;
GtkWidget *treeview1;
input=lookup_widget(button,"FTentryrech");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
if(!verif_id_ouv(id))
{fenetre_afficher=create_FTfenetre_afficher();
gtk_widget_show(fenetre_afficher);
treeview1=lookup_widget(fenetre_afficher,"FTtreeview1");
afficher_ouv_rechercher(treeview1,id);
fenetre_afficher=lookup_widget(button,"FTfenetre_afficher");
gtk_widget_destroy(fenetre_afficher);}
else
{FTfenetre_erreur=create_FTFenetre_erreur();
gtk_widget_show(FTfenetre_erreur);
output=lookup_widget(FTfenetre_erreur,"FTlabel49");
gtk_label_set_text(GTK_LABEL(output),"L'id saisie est inexistant");}



}


void
on_FTbutton_chercher_abs_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{char Id[30];
GtkWidget *FTfenetre_abs,*input,*output;
GtkWidget *treeview2;
input=lookup_widget(button,"FTabs_rech");
strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input)));
if(!verif_id_abs(Id))
{FTfenetre_abs=create_FTfenetre_abs();
gtk_widget_show(FTfenetre_abs);
treeview2=lookup_widget(FTfenetre_abs,"FTtreeview2");
afficher_abs_rechercher(treeview2,Id);
FTfenetre_abs=lookup_widget(button,"FTfenetre_abs");
gtk_widget_destroy(FTfenetre_abs);}
else
{FTfenetre_erreur=create_FTFenetre_erreur();
gtk_widget_show(FTfenetre_erreur);
output=lookup_widget(FTfenetre_erreur,"FTlabel49");
gtk_label_set_text(GTK_LABEL(output),"L'id saisie est inexistant");}

}


void
on_FTbuttonok_clicked                  (GtkWidget      *button,
                                        gpointer         user_data)
{


gtk_widget_destroy(FTfenetre_erreur);



}





