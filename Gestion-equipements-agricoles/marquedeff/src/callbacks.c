#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int a=1;

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Fenetre1;
  GtkWidget *min,*max,*annee,*msg,*aff;
 int mindef,maxdef,anneedef;
    char y[50];
    int i=0;
    int tab_annee[50];
    int t;
    int id;
    int k;
    int test=0,n,nb,vide=0;
    char tab_marque[50][50];
	int  tab_nb[50]={0};
 
//Fenetre1=lookup_widget(objet,"window2");
min=lookup_widget(objet,"spinbutton2");
max=lookup_widget(objet,"spinbutton3");
annee=lookup_widget(objet,"spinbutton1");
aff=lookup_widget(objet,"label7");
msg=lookup_widget(objet,"entry1");

mindef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
maxdef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(max));
anneedef= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
gtk_widget_show (aff);
if(a==1)
{nb=defectueux(mindef,maxdef,anneedef,"temperature.txt",tab_marque,tab_nb,"temperature");
if(!nb)
vide=1;
n=annee_dispo(tab_annee,"temperature.txt");
for(k=0;k<n;k++)
{if(tab_annee[k]==anneedef)
{test=1;
break;}}
}
else
{nb=defectueux(mindef,maxdef,anneedef,"humidite.txt",tab_marque,tab_nb,"humidite");
if(!nb)
vide=1;
n=annee_dispo(tab_annee,"humidite.txt");
for(k=0;k<n;k++)
{if(tab_annee[k]==anneedef)
{test=1;
break;}}
}
if(test&&!vide)
{t=max_tab_nb(tab_nb,nb);
gtk_label_set_text(GTK_LABEL(aff),"La marque la plus deffectueuse est :");
gtk_entry_set_text(msg,tab_marque[t]);
gtk_widget_show (msg);}
else if(!test)
{gtk_label_set_text(GTK_LABEL(aff),"L'année saisie n'est pas prise en\nconsidération");
gtk_widget_hide(msg);}
else if(vide)
{gtk_label_set_text(GTK_LABEL(aff),"Pas de capteur défectueux \npour cette année");
gtk_widget_hide(msg);}



remove("deffectueuxt.txt"); 


}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a=1;
}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
a=2;
}
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetrere1;
    GtkWidget *Fenetrere2;
    Fenetrere2=lookup_widget(objet,"window2");
    gtk_widget_destroy(Fenetrere2);
    Fenetrere1=create_window1();
    gtk_widget_show(Fenetrere1);
}

