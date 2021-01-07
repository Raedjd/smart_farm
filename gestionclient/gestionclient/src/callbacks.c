#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <string.h>
#include <gtk/gtk.h>
#include "fonction.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int x,y;

void
on_buttonmodifiergc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowmodifiergc;

windowmaingc=lookup_widget(objet,"windowmaingc");

gtk_widget_destroy(windowmaingc);
windowmodifiergc=lookup_widget(objet,"windowmodifiergc");
windowmodifiergc=create_windowmodifiergc();

gtk_widget_show(windowmodifiergc);
}

void
on_buttonajoutergc_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowajoutergc;

windowmaingc=lookup_widget(objet,"windowmaingc");

gtk_widget_destroy(windowmaingc);
windowajoutergc=lookup_widget(objet,"windowajoutergc");
windowajoutergc=create_windowajoutergc();

gtk_widget_show(windowajoutergc);
}

void
on_buttonsupprimergc_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowsupprimergc;

windowmaingc=lookup_widget(objet,"windowmaingc");

gtk_widget_destroy(windowmaingc);
windowsupprimergc=lookup_widget(objet,"windowsupprimergc");
windowsupprimergc=create_windowsupprimergc();

gtk_widget_show(windowsupprimergc);
}

void
on_buttonrecherchergc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *windowmaingc;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;

windowmaingc=lookup_widget(objet,"windowmaingc");

gtk_widget_destroy(windowmaingc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();

gtk_widget_show(windowaffichergc);
treeview1=lookup_widget(windowaffichergc,"treeview1");

afficher(treeview1);
}

void
on_buttonaffichergc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *windowmaingc;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;

windowmaingc=lookup_widget(objet,"windowmaingc");

gtk_widget_destroy(windowmaingc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();

gtk_widget_show(windowaffichergc);

treeview1=lookup_widget(windowaffichergc,"treeview1");

afficher(treeview1);
}

void
on_buttonafficherajgc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *windowajoutergc;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;

windowajoutergc=lookup_widget(objet,"windowajoutergc");

gtk_widget_destroy(windowajoutergc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();

gtk_widget_show(windowaffichergc);
treeview1=lookup_widget(windowaffichergc,"treeview1");

afficher(treeview1);
}

void
on_buttonretourajgc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowajoutergc;

windowajoutergc=lookup_widget(objet,"windowajoutergc");

gtk_widget_destroy(windowajoutergc);
windowmaingc=lookup_widget(objet,"windowmaingc");
windowmaingc=create_windowmaingc();

gtk_widget_show(windowmaingc);
}

void
on_buttonaffichersugc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *windowsupprimergc;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;

windowsupprimergc=lookup_widget(objet,"windowsupprimergc");

gtk_widget_destroy(windowsupprimergc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();

gtk_widget_show(windowaffichergc);
treeview1=lookup_widget(windowaffichergc,"treeview1");

afficher(treeview1);
}

void
on_buttonretoursugc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowsupprimergc;

windowsupprimergc=lookup_widget(objet,"windowsupprimergc");

gtk_widget_destroy(windowsupprimergc);
windowmaingc=lookup_widget(objet,"windowmaingc");
windowmaingc=create_windowmaingc();

gtk_widget_show(windowmaingc);
}

void
on_buttonretourafgc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowaffichergc;

windowaffichergc=lookup_widget(objet,"windowaffichergc");

gtk_widget_destroy(windowaffichergc);
windowmaingc=lookup_widget(objet,"windowmaingc");
windowmaingc=create_windowmaingc();

gtk_widget_show(windowmaingc);
}

void
on_buttonaffichermogc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
GtkWidget *windowmodifiergc;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;

windowmodifiergc=lookup_widget(objet,"windowmodifiergc");

gtk_widget_destroy(windowmodifiergc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();

gtk_widget_show(windowaffichergc);
treeview1=lookup_widget(windowaffichergc,"treeview1");

afficher(treeview1);
}

void
on_buttonretourmogc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmaingc;
GtkWidget *windowmodifiergc;

windowmodifiergc=lookup_widget(objet,"windowmodifiergc");

gtk_widget_destroy(windowmodifiergc);
windowmaingc=lookup_widget(objet,"windowmaingc");
windowmaingc=create_windowmaingc();

gtk_widget_show(windowmaingc);
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
		gchar* id;
		gchar* prenom;
		gchar* nom;
		gchar* mdp;
		gchar* sexe;
		gchar* age;
		gchar* numtel;
		gint* j;
		gint* m;
		gint* a;
		client c;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &id, 1, &prenom, 2, &nom ,3,&numtel,4,&sexe,5,&age,6,&j,7,&m,8,&a,-1);
		strcpy(c.id,id);
		strcpy(c.prenom,prenom);
		strcpy(c.nom,nom);
		strcpy(c.sexe,sexe);
		strcpy(c.age,age);
		strcpy(c.numtel,numtel);
		c.da.j=j;
		c.da.m=m;
		c.da.a=a;
		supprimer(c);
		afficher(treeview);
	}
}

void
on_buttonajouterajgc_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;

GtkWidget *input1, *input2, *input3, *input4, *input5,*input6, *input7, *input8, *input9, *input10;
GtkWidget *windowajoutergc;

windowajoutergc=lookup_widget(objet,"windowajoutergc");

input1=lookup_widget(objet,"entryidajgc");
input2=lookup_widget(objet,"entryprenomajgc");
input3=lookup_widget(objet,"entrynomajgc");
input4=lookup_widget(objet,"entrymdpajgc");
input5=lookup_widget(objet,"entrynumtelajgc");
//input6=lookup_widget(objet,"radiobuttonsexeajgc");
input7=lookup_widget(objet,"comboboxageajgc");
input8=lookup_widget(objet,"spinbuttondijajgc");
input9=lookup_widget(objet,"spinbuttondimajgc");
input10=lookup_widget(objet,"spinbuttondiaajgc");

//sscanf(gtk_entry_get_text(GTK_ENTRY(input1)), "%d", &c.id);
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(input4)));
//sscanf(gtk_entry_get_text(GTK_ENTRY(input5)), "%d", &c.numtel);
strcpy(c.numtel,gtk_entry_get_text(GTK_ENTRY(input5)));
if(x==1)
strcpy(c.sexe,"homme");
else
strcpy(c.sexe,"femme");
//sscanf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)), "%d", &c.age);
strcpy(c.age,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
c.da.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
c.da.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
c.da.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));

ajouter(c);
}

void
on_buttonsupprimersugc_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;

GtkWidget *input1;
GtkWidget *windowsupprimergc;

windowsupprimergc=lookup_widget(objet,"windowsupprimergc");

input1=lookup_widget(objet,"entryidsugc");

//sscanf(gtk_entry_get_text(GTK_ENTRY(input1)), "%d", &c.id);
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer(c);
}

void
on_buttonrechercherafgc_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *windowaffichergc;
GtkWidget *treeview1;
char rech[30];

windowaffichergc=lookup_widget(objet,"windowaffichergc");

input1=lookup_widget(objet,"entryrechercherafgc");

strcpy(rech,gtk_entry_get_text(GTK_ENTRY(input1)));

/*gtk_widget_destroy(windowaffichergc);
windowaffichergc=lookup_widget(objet,"windowaffichergc");
windowaffichergc=create_windowaffichergc();
*/
gtk_widget_show(windowaffichergc);

treeview1=lookup_widget(windowaffichergc,"treeview1");

rechercher(treeview1,rech);
}

void
on_buttonmodifiermogc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;

GtkWidget *input1, *input2, *input3, *input4, *input5,*input6, *input7, *input8, *input9, *input10;
GtkWidget *windowmodifiergc;

windowmodifiergc=lookup_widget(objet,"windowmodifiergc");

input1=lookup_widget(objet,"entryidmogc");
input2=lookup_widget(objet,"entryprenommogc");
input3=lookup_widget(objet,"entrynommogc");
input4=lookup_widget(objet,"entrymdpmogc");
input5=lookup_widget(objet,"entrynumtelmogc");
//input6=lookup_widget(objet,"radiobuttonsexemogc");
input7=lookup_widget(objet,"comboboxagemogc");
input8=lookup_widget(objet,"spinbuttondijmogc");
input9=lookup_widget(objet,"spinbuttondimmogc");
input10=lookup_widget(objet,"spinbuttondiamogc");

//sscanf(gtk_entry_get_text(GTK_ENTRY(input1)), "%d", &c.id);
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.mdp,gtk_entry_get_text(GTK_ENTRY(input4)));
//sscanf(gtk_entry_get_text(GTK_ENTRY(input5)), "%d", &c.numtel);
strcpy(c.numtel,gtk_entry_get_text(GTK_ENTRY(input5)));
if(y==1)
strcpy(c.sexe,"homme");
else
strcpy(c.sexe,"femme");
//sscanf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)), "%d", &c.age);
strcpy(c.age,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
c.da.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
c.da.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
c.da.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
modifier(c);
}

void
on_radiobuttonhommeajgc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
else
x=0;
}

void
on_radiobuttonhommemogc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
y=1;
else
y=0;
}

