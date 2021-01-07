/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed1;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");

  return window1;
}

GtkWidget*
create_windowtauxabsta (void)
{
  GtkWidget *windowtauxabsta;
  GtkWidget *fixed2;
  GtkWidget *entryaouvta;
  GtkWidget *labelaouvta;
  GtkWidget *buttonvaliderta;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label4;
  GtkWidget *labeltauxabsta;
  GtkWidget *labeltauxabsaffta;

  windowtauxabsta = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowtauxabsta), _("Taux Abs"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (windowtauxabsta), fixed2);

  entryaouvta = gtk_entry_new ();
  gtk_widget_show (entryaouvta);
  gtk_fixed_put (GTK_FIXED (fixed2), entryaouvta, 176, 80);
  gtk_widget_set_size_request (entryaouvta, 160, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryaouvta), 8226);

  labelaouvta = gtk_label_new (_("Ann\303\251e souhait\303\251e"));
  gtk_widget_show (labelaouvta);
  gtk_fixed_put (GTK_FIXED (fixed2), labelaouvta, 32, 80);
  gtk_widget_set_size_request (labelaouvta, 112, 24);

  buttonvaliderta = gtk_button_new ();
  gtk_widget_show (buttonvaliderta);
  gtk_fixed_put (GTK_FIXED (fixed2), buttonvaliderta, 352, 80);
  gtk_widget_set_size_request (buttonvaliderta, 88, 32);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (buttonvaliderta), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label4 = gtk_label_new_with_mnemonic (_("Valider"));
  gtk_widget_show (label4);
  gtk_box_pack_start (GTK_BOX (hbox1), label4, FALSE, FALSE, 0);

  labeltauxabsta = gtk_label_new (_("Taux d'absenteisme"));
  gtk_widget_show (labeltauxabsta);
  gtk_fixed_put (GTK_FIXED (fixed2), labeltauxabsta, 16, 144);
  gtk_widget_set_size_request (labeltauxabsta, 144, 24);

  labeltauxabsaffta = gtk_label_new ("");
  gtk_widget_show (labeltauxabsaffta);
  gtk_fixed_put (GTK_FIXED (fixed2), labeltauxabsaffta, 176, 152);
  gtk_widget_set_size_request (labeltauxabsaffta, 152, 256);

  g_signal_connect ((gpointer) buttonvaliderta, "clicked",
                    G_CALLBACK (on_buttonvaliderta_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowtauxabsta, windowtauxabsta, "windowtauxabsta");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, entryaouvta, "entryaouvta");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, labelaouvta, "labelaouvta");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, buttonvaliderta, "buttonvaliderta");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, image1, "image1");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, label4, "label4");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, labeltauxabsta, "labeltauxabsta");
  GLADE_HOOKUP_OBJECT (windowtauxabsta, labeltauxabsaffta, "labeltauxabsaffta");

  return windowtauxabsta;
}

