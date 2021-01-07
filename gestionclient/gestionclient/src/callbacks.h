#include <gtk/gtk.h>
#include <fonction.h>

void
on_buttonmodifiergc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonajoutergc_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonsupprimergc_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonrecherchergc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonaffichergc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonafficherajgc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretourajgc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonaffichersugc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretoursugc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretourafgc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonaffichermogc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonretourmogc_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_buttonajouterajgc_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonsupprimersugc_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonrechercherafgc_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonmodifiermogc_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonhommeajgc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonhommemogc_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
