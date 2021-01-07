#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

void ajoutercapdef(int id,char c[],int t)
{
    FILE *f;
    f=fopen("deffectueuxt.txt","a");
    fprintf(f,"%d %s %d\n",id,c,t);
    fclose(f);
}


int defectueux(int min,int max,int annee,char fichier[],char tab_marque[50][50],int tab_nb[],char type_cap[])
{   
     FILE *f;
    int id,j,m,a;
char zone[20];
char type[20];
char marque[20];
char etat[20];
    int id1,t1,t2,t3;
    float valeur;
    FILE *f1,*f2;
    int i,k,test;
    f=fopen("liste_des_capteurs.txt","r");
    if(f!=NULL)
    { while(fscanf(f,"%d %s %s %s %s %d %d %d  \n",&id,zone,type,marque,etat,&j,&m,&a)!=EOF)
    {
        f1=fopen(fichier,"r");
        if(f1!=NULL)
        {while(fscanf(f1,"%d %d %d %d %f",&id1,&t1,&t2,&t3,&valeur)!=EOF)
        {
        if((valeur>max || valeur <min)&& t3==annee&& id1==id&&strcmp(type,type_cap)==0 )
                   {
               
                           ajoutercapdef(id1,marque,t3);
                          
                    }
        
        }
        }
        fclose(f1);
        }}
fclose(f);
f2=fopen("deffectueuxt.txt","r");
if(f2!=NULL){
fscanf(f2,"%d %s %d\n",&id,marque,&a);
strcpy(tab_marque[0],marque);
    i=1;
        while(fscanf(f2,"%d %s %d\n",&id,marque,&a)!=EOF)
           {test=1;
        for(k=0;k<i;k++)
    {if(strcmp(tab_marque[k],marque)==0)
    {test=0;
    break;}}
if(test)
 {strcpy(tab_marque[i],marque);
          i++;}
}
}
else 
return 0;///return 0 si f2==NULL (le fichier est vide ,pas de capteurs défectueux)
rewind(f2);
while(fscanf(f2,"%d %s %d\n",&id,marque,&a)!=EOF)
{for(k=0;k<i;k++)
{if(strcmp(tab_marque[k],marque)==0)
tab_nb[k]++;
}
}
fclose(f2);
return i;

}
/////////Remplis tableaux avec les années dispo sur fichier
int  annee_dispo(int tab[],char fichier[])
{int id,j,m,an,i;
float valeur;
FILE *f =fopen(fichier,"r");
if(f!=NULL)
{fscanf(f,"%d %d %d %d %f",&id,&j,&m,&an,&valeur);
tab[0]=an;
i=1;
while(fscanf(f,"%d %d %d %d %f",&id,&j,&m,&an,&valeur)!=EOF)
{if (an!=tab[i-1])
{tab[i]=an;
i++;}
}
}
return i;
fclose(f);}
int max_tab_nb(int tab_nb[],int n)
{
int max,i,p;
max=tab_nb[0];
for(i=0;i<n;i++)
{if(tab_nb[i]>max)
{max=tab_nb[i];
p=i;}
}
return p;}



