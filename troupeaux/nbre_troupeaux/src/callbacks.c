#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "nbre_troupeaux.h"
void
on_button_aff_nb_troupeaux_clicked     (GtkWidget      *button,
                                        gpointer         user_data)
{GtkWidget *output;
char aff[1000];
int n_brebi=0,n_veau=0;
nbre_troupeaux(&n_brebi,&n_veau);
sprintf(aff,"nombre de brebi:%d\nnombre de veau:%d",n_brebi,n_veau);
output=lookup_widget(button,"label_aff_nb_troupeaux");
gtk_label_set_text(GTK_LABEL(output),aff);
}




