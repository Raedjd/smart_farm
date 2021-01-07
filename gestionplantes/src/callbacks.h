#include <gtk/gtk.h>


void
on_radio1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                     	(GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_showbutton_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
