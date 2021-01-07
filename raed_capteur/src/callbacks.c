#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "capteur_raed.h"
#include "capteur_raed.c"
#include <stdlib.h>
#include <string.h>


void
on_ajouter1_clicked                   ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{   GtkWidget *fenetre_ajout;
     GtkWidget *fenetre_princ;
fenetre_ajout=lookup_widget (objet_graphique,"window2");
fenetre_ajout=create_window2 ();
gtk_widget_show(fenetre_ajout);
afficher_capteur(fenetre_ajout);
fenetre_princ=lookup_widget (objet_graphique,"window1");
gtk_widget_destroy(fenetre_princ);
   
   

}


///////////////////////////////////////////////////////////////////////

void
on_modifier1_clicked                   ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *fenetre_mod;
    GtkWidget *fenetre_princ;
fenetre_mod=lookup_widget (objet_graphique,"window2");
fenetre_mod=create_window2 ();
gtk_widget_show(fenetre_mod);
afficher_capteur(fenetre_mod);
fenetre_princ=lookup_widget (objet_graphique,"window1");
gtk_widget_destroy(fenetre_princ);

}

////////////////////////////////////////////////////////////////////////
void
on_supprimer1_clicked                  ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *fenetre_supp;
    GtkWidget *fenetre_princ;
fenetre_supp=lookup_widget (objet_graphique,"window3");
fenetre_supp=create_window3();
gtk_widget_show(fenetre_supp);
afficher_capteur(fenetre_supp);
fenetre_princ=lookup_widget (objet_graphique,"window1");
gtk_widget_destroy(fenetre_princ);

}

////////////////////////////////////////////////////////////////////////////
void
on_consulter_clicked                  ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
  GtkWidget *fenetre_princ;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet_graphique,"window4");
fenetre_afficher=create_window4();

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_capteur(treeview1);
fenetre_princ=lookup_widget (objet_graphique,"window1");
gtk_widget_destroy(fenetre_princ);

}

///////////////////////////////////////////////////////////////////////////////////
int x;
int a;
void
on_ajout_clicked                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  capteur C;
   GtkWidget *IdentifianteCapt;
   GtkWidget *MarqueCapt;
   GtkWidget *TypeCapt;
   GtkWidget *JourCapt;
   GtkWidget *MoisCapt;
   GtkWidget *AnneeCapt;
   GtkWidget *ComboboxValeurMini;
   GtkWidget *ComboboxValeurMaxi;
   GtkWidget *ComboboxZoCov;
   GtkWidget *outputMsg;
   int ajout,verif;
   char text[200];
  
  
  
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet_graphique,"window2");
IdentifianteCapt=lookup_widget(objet_graphique,"entry_id");
MarqueCapt=lookup_widget(objet_graphique,"entry_mq");
strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(IdentifianteCapt)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(MarqueCapt)));
/////////////////////////////////////////////////////////
JourCapt=lookup_widget(objet_graphique,"spinbutton1");
MoisCapt=lookup_widget(objet_graphique,"spinbutton2");
AnneeCapt=lookup_widget(objet_graphique,"spinbutton3");
C.JourCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourCapt));
C.MoisCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisCapt));
C.AnneeCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeCapt));
///////////////////////////////////////////////////////////
ComboboxValeurMaxi=lookup_widget(objet_graphique,"combobox_max");
ComboboxValeurMini=lookup_widget(objet_graphique,"combobox_min");
ComboboxZoCov=lookup_widget(objet_graphique,"combobox7");
strcpy(C.captValMin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMini)));
strcpy(C.captValMax,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMaxi)));
strcpy(C.captZone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
if(x==1)
{strcpy(C.captType,"Temperature");}
else
if(x==2)
{strcpy(C.captType,"Humidite");}
       
//ajout=ajouter_capt(C);

verif=exist_capteur(C.captID);

switch(verif)
    
{
    case 0:  
    { ajout=ajouter_capt(C); 
     strcpy (text,"Ajout Réussi");
     outputMsg=lookup_widget(objet_graphique,("Msg"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    break;
    case 1:
    { strcpy (text,"Identifiant déja existe");
    outputMsg=lookup_widget(objet_graphique,("Msg"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
}
 }
//////////////////////////////////////////////////////////////////////
void
on_modif_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{   capteur C;
   GtkWidget *IdentifianteCapt;
   GtkWidget *MarqueCapt;
   GtkWidget *TypeCapt;
   GtkWidget *JourCapt;
   GtkWidget *MoisCapt;
   GtkWidget *AnneeCapt;
   GtkWidget *ComboboxValeurMini;
   GtkWidget *ComboboxValeurMaxi;
   GtkWidget *ComboboxZoCov;
   GtkWidget *outputMsg;
   int mod,verif;
   char text[200];
  
   
GtkWidget *fenetre_ajout;

fenetre_ajout=lookup_widget(objet_graphique,"window2");
IdentifianteCapt=lookup_widget(objet_graphique,"entry_id");
MarqueCapt=lookup_widget(objet_graphique,"entry_mq");
strcpy(C.captID,gtk_entry_get_text(GTK_ENTRY(IdentifianteCapt)));
strcpy(C.captMarque,gtk_entry_get_text(GTK_ENTRY(MarqueCapt)));
/////////////////////////////////////////////////////////
JourCapt=lookup_widget(objet_graphique,"spinbutton1");
MoisCapt=lookup_widget(objet_graphique,"spinbutton2");
AnneeCapt=lookup_widget(objet_graphique,"spinbutton3");
C.JourCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourCapt));
C.MoisCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisCapt));
C.AnneeCap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeCapt));
///////////////////////////////////////////////////////////
ComboboxValeurMaxi=lookup_widget(objet_graphique,"combobox_max");
ComboboxValeurMini=lookup_widget(objet_graphique,"combobox_min");
ComboboxZoCov=lookup_widget(objet_graphique,"combobox7");
strcpy(C.captValMin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMini)));
strcpy(C.captValMax,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxValeurMaxi)));
strcpy(C.captZone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
if(x==1)
{strcpy(C.captType,"Temperature");}
else
if(x==2)
{strcpy(C.captType,"Humidite");}
 // mod=modifier_capt(C); 
verif=exist_capteur(C.captID);

switch(verif)
    
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    outputMsg=lookup_widget(objet_graphique,("Msg"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
    case 1:
   
    {  mod=modifier_capt(C);
     strcpy (text,"Modifie Réussi");
     outputMsg=lookup_widget(objet_graphique,("Msg"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    break; 
    break;
} 

}
///////////////////////////////////////////////////////////////////////////////////////

void
on_button_affich1_clicked               ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet_graphique,"window2");

gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet_graphique,"window4");
fenetre_afficher=create_window4();

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_capteur(treeview1);

gtk_widget_destroy(fenetre_ajout);

}

////////////////////////////////////////////////////////////////////////////////
void
on_button7_ret_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *fenetre_principale, *fenetre_ajout_modif;
fenetre_ajout_modif=lookup_widget(objet_graphique,"window2");
fenetre_principale=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(fenetre_ajout_modif);
fenetre_principale=create_window1();
gtk_widget_show(fenetre_principale);

}

int conf=0;
int *r=&conf;
void
on_supp_clicked                      ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{    GtkWidget *input1;
          
     GtkWidget  *fenetre_supp;
     GtkWidget *outputMsg;
     int supp,verif;
     char text[200];
    char ID[20];
     

fenetre_supp=lookup_widget(objet_graphique,"window3");
input1=lookup_widget(objet_graphique,"entry_supp");   
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));
if(conf)
//supp=supprimer_capt(ID);

{verif=exist_capteur(ID);


switch(verif)
    
{
    case 0:
   
     
    { strcpy (text,"Identifiant à supprimer n'existe pas");
    outputMsg=lookup_widget(objet_graphique,("label51"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
  
    break;
    case 1:
     
     {
      supp=supprimer_capt(ID);
     strcpy (text,"Suppression Réussi");
     outputMsg=lookup_widget(objet_graphique,("label53"));
     gtk_label_set_text(GTK_LABEL(outputMsg),text);
     }
    
    break; 
    break;
}
}
else 
{strcpy (text,"La confirmation est obligatoire!");
    outputMsg=lookup_widget(objet_graphique,("label52"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}

/////////////////////////////////////////////////////////////////////////////////////
void
on_button10_affich_clicked             ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *fenetre_supp;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
fenetre_afficher=lookup_widget(objet_graphique,"window4");
fenetre_afficher=create_window4();

gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_capteur(treeview1);
fenetre_supp=lookup_widget(objet_graphique,"window3");
gtk_widget_destroy(fenetre_supp);


}

//////////////////////////////////////////////////////////////////////////////////
void
on_button9_ret_clicked                  ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *fenetre_principale, *fenetre_ajout_supp;
fenetre_ajout_supp=lookup_widget(objet_graphique,"window3");
fenetre_principale=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(fenetre_ajout_supp);
fenetre_principale=create_window1();
gtk_widget_show(fenetre_principale);

}

//////////////////////////////////////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{  GtkTreeIter iter;
	gchar *captID;
	gchar *captMarque; 
	gchar *captType; 
	gchar *JourCap; 
	gchar *MoisCap;
	gchar *AnneeCap; 
        gchar *captValMin;
        gchar *captValMax;
	gchar *captZone;
	capteur C;
	FILE *f=NULL;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&captID,1,&captMarque,2,&captType,3,&JourCap,4,&MoisCap,5,&AnneeCap,6,&captValMin,7,&captValMax,8,&captZone,-1);

	strcpy(C.captID,captID);
	strcpy(C.captMarque,captMarque);
	strcpy(C.captType,captType);
	C.JourCap=JourCap;
	C.MoisCap=MoisCap;
	C.AnneeCap=AnneeCap;
	strcpy(C.captValMin,captValMin);
	strcpy(C.captValMax,captValMax);
	strcpy(C.captZone,captZone);
        afficher_capteur(treeview);

}
}
///////////////////////////////////////////////////////////////////////////////////////////
void
on_recherche_clicked                    ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *Fenetrerech;
   GtkWidget *idy;
   GtkWidget *treeviewrech;
      GtkWidget *outputMsg;
   int verif;
    char text[200];
   char id[20];
   
Fenetrerech=lookup_widget(objet_graphique,"window4");
idy=lookup_widget(objet_graphique,"entry_rech");
treeviewrech=lookup_widget(objet_graphique,"treeview2_rech");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idy)));
verif=exist_capteur(id);

switch(verif)
    
{
    case 0:  
    { strcpy (text,"Identifiant n'existe pas");
    outputMsg=lookup_widget(objet_graphique,("label64"));
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
    }
    break;
    case 1:
   
    {  rechercher_capteur(treeviewrech, id);
       remove(treeviewrech);
       strcpy (text,"Identifiant existe");
       outputMsg=lookup_widget(objet_graphique,("label64"));
       gtk_label_set_text(GTK_LABEL(outputMsg),text);
      }
    break; 
    break;
} 

}


///////////////////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}

//////////////////////////////////////////////////////////////////////////////////////////////
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}
}

//////////////////////////////////////////////////////////////////////////////////////////////

void
on_button7_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{  GtkWidget *fenetre_principale, *fenetre_aff;
fenetre_aff=lookup_widget(objet_graphique,"window4");
fenetre_principale=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(fenetre_aff);
fenetre_principale=create_window1();
gtk_widget_show(fenetre_principale);

}
//////////////////////////////////////////////////////////////////////////////////////////////

void
on_treeview2_rech_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkTreeIter iter;
	gchar *captID;
	gchar *captMarque; 
	gchar *captType; 
	gchar *JourCap; 
	gchar *MoisCap;
	gchar *AnneeCap; 
        gchar *captValMin;
        gchar *captValMax;
	gchar *captZone;
	capteur C;
	FILE *f=NULL;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&captID,1,&captMarque,2,&captType,3,&JourCap,4,&MoisCap,5,&AnneeCap,6,&captValMin,7,&captValMax,8,&captZone,-1);

	strcpy(C.captID,captID);
	strcpy(C.captMarque,captMarque);
	strcpy(C.captType,captType);
	C.JourCap=JourCap;
	C.MoisCap=MoisCap;
	C.AnneeCap=AnneeCap;
	strcpy(C.captValMin,captValMin);
	strcpy(C.captValMax,captValMax);
	strcpy(C.captZone,captZone);
        afficher_capteur(treeview);

}

}

/////////////////////////////////////////////////////////////////////////////////////////////
void
on_button8_actu_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{GtkWidget  *fenetre_aff,*treeview;
fenetre_aff=create_window4();
gtk_widget_show(fenetre_aff);
treeview=lookup_widget(fenetre_aff,"treeview1");
afficher_capteur(treeview);

fenetre_aff=lookup_widget(objet_graphique,"window4");

gtk_widget_destroy(fenetre_aff);

}
//////////////////////////////////////////////////////////////////////////////////////////////

void
on_button8_al_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *fenetre_al;
  GtkWidget *fenetre_princ;
fenetre_al=lookup_widget (objet_graphique,"window5");
fenetre_al=create_window5 ();
gtk_widget_show(fenetre_al);
afficher_capteur(fenetre_al);
fenetre_princ=lookup_widget (objet_graphique,"window1");
gtk_widget_destroy(fenetre_princ);

}

//////////////////////////////////////////////////////////////////////////////////////////////
void
on_button9_tm_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *ValeurtmpMin1;
   GtkWidget *ValeurtmpMin2;
   GtkWidget *ValeurtmpMax1;
   GtkWidget *ValeurtmpMax2;
      GtkWidget *output;
int id ,n=1 ,i, j , a,mo,nt,ct [50];
float val;
char texte [200]="";
//float max2=60 , min2=40,max1=0, min1=-10;
float max2,max1,min1,min2;

ValeurtmpMin1=lookup_widget(objet_graphique,"spinbutton4");
ValeurtmpMin2=lookup_widget(objet_graphique,"spinbutton5");
ValeurtmpMax1=lookup_widget(objet_graphique,"spinbutton6");
ValeurtmpMax2=lookup_widget(objet_graphique,"spinbutton7");
min1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurtmpMin1));
min2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurtmpMin2));
max1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurtmpMax1));
max2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurtmpMax2));
FILE *f; 
f= fopen ("temperature.txt","r");
if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %f",&id,&j,&mo ,&a, &val)!=EOF){
	if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
		i =0;
while ((i <n) && (ct[i]!=id ))
i++;
if (i==n) {ct[i]=id ; n++ ;}} }
sprintf (texte,"il y a : %d capteurs de temperature alarmentes ",n);
output=lookup_widget(objet_graphique,("label45"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (n);
}
}

/////////////////////////////////////////////////////////////////////////////////////////////

void
on_button10_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{   GtkWidget *ValeurhumMin1;
   GtkWidget *ValeurhumMin2;
   GtkWidget *ValeurhumMax1;
   GtkWidget *ValeurhumMax2;
      GtkWidget *output;
//float max2=100 , min2=1,max1=300 , min1=10;
int id ,n=1 ,i, j , a,mo,nh,ch [50];
float val;
char texte [200]="";
float max2,max1,min1,min2;
ValeurhumMin1=lookup_widget(objet_graphique,"spinbutton8");
ValeurhumMin2=lookup_widget(objet_graphique,"spinbutton9");
ValeurhumMax1=lookup_widget(objet_graphique,"spinbutton10");
ValeurhumMax2=lookup_widget(objet_graphique,"spinbutton11");
min1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurhumMin1));
min2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurhumMin2));
max1=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurhumMax1));
max2=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(ValeurhumMax2));
FILE *f; 
f= fopen ("humidite.txt","r");
if (f!=NULL) {
while(fscanf (f,"%d %d %d %d %f",&id,&j,&mo ,&a, &val)!=EOF){
		if ((val<max1 && val>min1)||(val<max2 && val>min2)) {
		i =0;
while ((i <n) && (ch[i]!=id ))
i++;
if (i==n) {ch[i]=id ; n++ ;}} }
sprintf (texte,"il y a : %d capteurs de humidité alarmentes ",n);
output=lookup_widget(objet_graphique,("label46"));
gtk_label_set_text(GTK_LABEL(output),texte);
fclose (f);
return (n);}

}
////////////////////////////////////////////////////////////////////////////////////////////

void
on_button11_clicked                       (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ GtkWidget *fenetre_principale, *fenetre_ajout_supp;
fenetre_ajout_supp=lookup_widget(objet_graphique,"window5");
fenetre_principale=lookup_widget(objet_graphique,"window1");

gtk_widget_destroy(fenetre_ajout_supp);
fenetre_principale=create_window1();
gtk_widget_show(fenetre_principale);


}
///////////////////////////////////////////////////////////////////////////////////////////

void
on_checkbutton_conf_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
*r=1;
else
*r=0;
}
/////////////////////////////////////////////////////////////////////////////////////////
void
on_button12_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget  *fenetre_aff;
fenetre_aff=create_window3();
gtk_widget_show(fenetre_aff);

afficher_capteur(fenetre_aff);

fenetre_aff=lookup_widget(objet_graphique,"window3");

gtk_widget_destroy(fenetre_aff);

}

