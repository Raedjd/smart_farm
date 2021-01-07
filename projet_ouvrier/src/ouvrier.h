#include <gtk/gtk.h>

typedef struct
{
char cin[20];
char nom[20];
char prenom[30];
char date_naissance[30];
char adresse[30];
char sexe[20];
int nbre_abs;


}ouv;
void ajouter_ouv(ouv p);
void afficher_ouv(GtkWidget *liste);
void supprimer_ouv(char id[]);
void modifier_ouv(ouv p);
int charger_liste(ouv tab_ouv[],int n);
void meilleur_ouv(ouv tab_ouv[],int n,char nomFichier[],int annee,char cin[]);
int nbre_total_abs(ouv tab_ouv[],int n,int annee,char nomFichier[]);
void rechercher_ouv(char nomFichier[],char texte[],char id[]);
void resultat_ouv(int choix,char sexe[]);
void afficher_ouv_rechercher(GtkWidget *liste,char id[]);
int verif_id_ouv(char id[]);
void rech_modif(ouv *p);


////Gestion d'absenteisme
typedef struct
{
char id[20];
char jour[20];
char mois[20] ;
char annee[20];
char pres[20];
}ouv_abs;
void ajouter_abs(ouv_abs p);
void afficher_abs(GtkWidget *liste);
void res_ouv(int choix,char prs[]);
void supprimer_abs(ouv_abs p);
void afficher_abs_rechercher(GtkWidget *liste,char Id[]);
int verif_id_abs(char id[]);





