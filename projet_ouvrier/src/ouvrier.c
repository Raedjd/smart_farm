#include <stdio.h>
#include <string.h>
#include <ouvrier.h>
#include <gtk/gtk.h>




int verif_id_ouv(char id[])
{FILE *f;
ouv p;
f=fopen("ouvrier.txt","r");
if(f!=NULL)
{while(fscanf(f,"%s %s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse,p.sexe)!=EOF)
{if(strcmp(id,p.cin)==0)
return 0;}
}
else 
return 1;}
void ajouter_ouv(ouv p)
{

FILE *f;
f=fopen("ouvrier.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse,p.sexe);
fclose(f);
}
}
void afficher_ouv(GtkWidget *liste)
{

enum
{
CIN,
NOM,
PRENOM,
DATE,
ADRESSE,
SEXE,
COLUMNS
};


GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;
char cin[20];
char nom[30];
char prenom[30];
char date[30];
char adresse[20];
char sexe[20];
store=NULL;
 
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date de naissance",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("ouvrier.txt","r");
if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE,date,ADRESSE,adresse,SEXE,sexe,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void supprimer_ouv(char id[])
{
char cin[30];
char nom[20];
char prenom[30];
char date[30];
char adresse[30];
char sexe[20];
FILE *f,*g;
f=fopen("ouvrier.txt","r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
return ;
else
{
while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{
if(strcmp(id,cin)==0)
continue;
else
fprintf(g,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe);
}
fclose(f);
fclose(g);
remove("ouvrier.txt");
rename("dump.txt","ouvrier.txt");
}

}
void modifier_ouv(ouv p)
{
char cin[30];
char nom[20];
char prenom[30];
char date[30];
char adresse[30];
char sexe[20];
FILE *f,*g;
f=fopen("ouvrier.txt","r");
g=fopen("dump.txt","w");
if(f==NULL||g==NULL)
return ;
else
while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{
if(strcmp(p.cin,cin)==0)
fprintf(g,"%s %s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse,p.sexe);
else
fprintf(g,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe);
}
fclose(f);
fclose(g);
remove("ouvrier.txt");
rename("dump.txt","ouvrier.txt");
}
int charger_liste(ouv tab_ouv[],int n)
{

    n=0;
    FILE *f=NULL;
    f=fopen("ouvrier.txt","r");
    if(f!=NULL)
    {

        while(fscanf(f,"%s %s %s %s %s %s\n",tab_ouv[n].cin,tab_ouv[n].nom,tab_ouv[n].prenom,tab_ouv[n].date_naissance,tab_ouv[n].adresse,tab_ouv[n].sexe)!=EOF)
        {
            n++;
        }
    fclose(f);

    }
    return n;
}

void meilleur_ouv(ouv tab_ouv[],int n,char nomFichier[],int annee,char cin[])
{ int i,min;


if(nbre_total_abs(tab_ouv,n,annee,nomFichier))
{min=tab_ouv[0].nbre_abs;
strcpy(cin,tab_ouv[i].cin);
for(i=1;i<n;i++)
{
    if(tab_ouv[i].nbre_abs<min)
        {min=tab_ouv[i].nbre_abs;
        strcpy(cin,tab_ouv[i].cin);}
}

}
}

int nbre_total_abs(ouv tab_ouv[],int n,int annee,char nomFichier[])
{
    int j,m,a,i,v;
    char cin[20];
    FILE *f=NULL;
    for(i=0;i<n;i++)
        tab_ouv[i].nbre_abs=0;
    f=fopen(nomFichier,"r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %d \n",cin,&j,&m,&a,&v)!=EOF)
        {
            for(i=0;i<n;i++)
            {
                if(strcmp(tab_ouv[i].cin,cin)==0&&annee==a&&v==0)
                    {tab_ouv[i].nbre_abs++;
                    break;}
            }
        }
    fclose(f);
    return 1;
    }
}
void rechercher_ouv(char nomFichier[],char texte[],char id[])
{
char cin[20],nom[20],prenom[20],adresse[20],date[20],sexe[20];
FILE *f=fopen(nomFichier,"r");
if(f!=NULL)
{while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{
if(strcmp(cin,id)==0)
{sprintf(texte,"id:%s\nnom:%s\nprenom%s\ndate de naissance:%s\nadresse:%s\nsexe:%s\n",cin,nom,prenom,date,adresse,sexe);
break;}}
}
}
void resultat_ouv(int choix,char sexe[])
{if(choix==1)
strcpy(sexe,"Male");
else if(choix==0)
strcpy(sexe,"Femelle");
}

void afficher_abs(GtkWidget *liste)
{

enum
{
ID,
JOUR,
MOIS,
ANNEE,
VALEUR,
COLS
};


GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;
char id[20];
char jour[20];
char mois[20] ;
char annee[20];
char pres[20];
store=NULL;
 
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Presence",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("abs.txt","r");
if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s %s \n",id,jour,mois,annee,pres)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID,id,JOUR,jour,MOIS,mois,ANNEE,annee,VALEUR,pres,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void ajouter_abs(ouv_abs p)
{
FILE *f;
f=fopen("abs.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",p.id,p.jour,p.mois,p.annee,p.pres);
fclose(f);
}
}
void res_ouv(int choix,char prs[])
{if(choix==1)
strcpy(prs,"Présent");
else if(choix==0)
strcpy(prs,"Absent");
}


void supprimer_abs(ouv_abs p)
{
char Id[20];
char jour[20];
char mois[20] ;
char annee[20];
char prs[20];
FILE *f,*g;
f=fopen("abs.txt","r");
g=fopen("dump_abs.txt","w");
if(f==NULL||g==NULL)
return ;
else
{
while(fscanf(f,"%s %s %s %s %s \n",Id,&jour,&mois,&annee,prs)!=EOF)
{
if(strcmp(p.id,Id)==0&&strcmp(p.jour,jour)==0&&strcmp(p.mois,mois)==0&&strcmp(p.annee,annee)==0&&strcmp(p.pres,prs)==0)
continue;
else
fprintf(g,"%s %s %s %s %s \n",Id,jour,mois,annee,prs);
}
fclose(f);
fclose(g);
remove("abs.txt");
rename("dump_abs.txt","abs.txt");
}
}




void afficher_ouv_rechercher(GtkWidget *liste,char id[])
{
enum
{
CIN,
NOM,
PRENOM,
DATE,
ADRESSE,
SEXE,
COLUMNS
};

GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;
char cin[20];
char nom[30];
char prenom[30];
char date[30];
char adresse[20];
char sexe[20];
store=NULL;
 
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("date de naissance",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("ouvrier.txt","r");
if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{if(strcmp(id,cin)==0)
{gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,DATE,date,ADRESSE,adresse,SEXE,sexe,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void afficher_abs_rechercher(GtkWidget *liste,char Id[])
{

enum
{
ID,
JOUR,
MOIS,
ANNEE,
VALEUR,
COLS
};


GtkCellRenderer *renderer;

GtkTreeViewColumn *column;

GtkTreeIter iter;

GtkListStore *store;
char id[20];
char jour[20];
char mois[20] ;
char annee[20];
char pres[20];
store=NULL;
 
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Presence",renderer,"text",VALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("abs.txt","r");
if(f==NULL)
return;
else
{
while(fscanf(f,"%s %s %s %s %s \n",id,jour,mois,annee,pres)!=EOF)
{if(strcmp(Id,id)==0)
{gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID,id,JOUR,jour,MOIS,mois,ANNEE,annee,VALEUR,pres,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
int verif_id_abs(char id[])
{FILE *f;
ouv_abs p;
f=fopen("abs.txt","r");
if(f!=NULL)
{while(fscanf(f,"%s %s %s %s %s  \n",p.id,p.jour,p.mois,p.annee,p.pres)!=EOF)
{if(strcmp(id,p.id)==0)
return 0;}
}
else 
return 1;}
void rech_modif(ouv *p)
{
char cin[20],nom[20],prenom[20],adresse[20],date[20],sexe[20];
FILE *f=fopen("ouvrier.txt","r");
if(f!=NULL)
{while(fscanf(f,"%s %s %s %s %s %s \n",cin,nom,prenom,date,adresse,sexe)!=EOF)
{
if(strcmp(cin,p->cin)==0)
{strcpy(p->nom,nom);
strcpy(p->prenom,prenom);
strcpy(p->date_naissance,date);
strcpy(p->adresse,adresse);
strcpy(p->sexe,sexe);
break;}
}
}
}

