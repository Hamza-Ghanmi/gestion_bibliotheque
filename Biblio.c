#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <time.h>

struct auteur
{
    int code_auteur;
    char nom_auteur[50];
    char prenom_auteur[50];
    int date_naissance[3];
    char nationalite[50];
};
struct livre
{
    int code_livre;
    char titre_livre[50];
    int nbre_pages;
    float prix_achat;
    int date_achat[3];
    int code_auteur;
    char maison[50];
    char disponible;
};
struct etudiant
{
    int cin;
    char nom_etudiant[50];
    char prenom_etudiant[50];
    int date_naissance_e[3];
    int code_classe;
};
struct emprunt
{
    int dhe[5];
    int cin_emprunt;
    int code_livre_emprunt;
    int dhr[5];
};
struct livre tlivre[100];
struct auteur tauteur[100];
struct etudiant tetudiant[100];
struct emprunt temprunt[100];
void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void extract_date(int date[])
{
    time_t x;
    time(&x);
    struct tm y=*(localtime(&x));
    date[1]=y.tm_mon+1;
    date[0]=y.tm_mday;
    date[2]=y.tm_year+1900;
}
void extract_time(int heure[])
{
    time_t x;
    time(&x);
    struct tm y=*(localtime(&x));
    heure[1]=y.tm_min;
    heure[0]=y.tm_hour;
}
int extract_info_Fauteur()
{
    FILE *Fauteur;
    int m=0;
    Fauteur=fopen("Fauteur.txt","a+");
    rewind(Fauteur);
    do{
        fscanf(Fauteur,"%d %s %s %d %d %d %s \n",&tauteur[m].code_auteur,tauteur[m].nom_auteur,tauteur[m].prenom_auteur,&tauteur[m].date_naissance[0],&tauteur[m].date_naissance[1],&tauteur[m].date_naissance[2],tauteur[m].nationalite);
        m+=1;
      }while(feof(Fauteur)==0);
    fclose(Fauteur);
   if ((m==1)&&(tauteur[0].date_naissance[0]==0)&&(tauteur[0].date_naissance[1]==0)&&(tauteur[0].date_naissance[2]==0))
        return 0;
    else
        return m;
}
int extract_info_Flivre()
{
    FILE *Flivre;
    int n=0;
    Flivre=fopen("Flivre.txt","a+");
    rewind(Flivre);
    do{
        fscanf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",&tlivre[n].code_livre,tlivre[n].titre_livre,&tlivre[n].nbre_pages,&tlivre[n].prix_achat,&tlivre[n].date_achat[0],&tlivre[n].date_achat[1],&tlivre[n].date_achat[2],&tlivre[n].code_auteur,tlivre[n].maison,&tlivre[n].disponible);
        n+=1;
      }while(feof(Flivre)==0);
    fclose(Flivre);
    if ((n==1)&&(tlivre[0].date_achat[0]==0)&&(tlivre[0].date_achat[1]==0)&&(tlivre[0].date_achat[2]==0))
        return 0;
    else
        return n;
}
int extract_info_Fetudiant()
{
    FILE *Fetudiant;
    int p=0;
    Fetudiant=fopen("Fetudiant.txt","a+");
    rewind(Fetudiant);
    do{
        fscanf(Fetudiant,"%d %s %s %d %d %d %d\n",&tetudiant[p].cin,tetudiant[p].nom_etudiant,tetudiant[p].prenom_etudiant,&tetudiant[p].date_naissance_e[0],&tetudiant[p].date_naissance_e[1],&tetudiant[p].date_naissance_e[2],&tetudiant[p].code_classe);
        p+=1;
      }while(feof(Fetudiant)==0);
    fclose(Fetudiant);
   if ((p==1)&&(tetudiant[0].date_naissance_e[0]==0)&&(tetudiant[0].date_naissance_e[1]==0)&&(tetudiant[0].date_naissance_e[2]==0))
        return 0;
    else
        return p;
}
int extract_info_Fempruntretour()
{
    FILE *Fempruntretour;
    int q=0;
    Fempruntretour=fopen("Fempruntretour.txt","a+");
    rewind(Fempruntretour);
    do{
        fscanf(Fempruntretour,"%d %d %d %d %d %d %d %d %d %d %d %d\n",&temprunt[q].dhe[0],&temprunt[q].dhe[1],&temprunt[q].dhe[2],&temprunt[q].dhe[3],&temprunt[q].dhe[4],&temprunt[q].cin_emprunt,&temprunt[q].code_livre_emprunt,&temprunt[q].dhr[0],&temprunt[q].dhr[1],&temprunt[q].dhr[2],&temprunt[q].dhr[3],&temprunt[q].dhr[4]);
        q+=1;
      }while(feof(Fempruntretour)==0);
    fclose(Fempruntretour);
   if ((q==1)&&(temprunt[q].dhe[4]==0)&&(temprunt[q].dhe[3]==0)&&(temprunt[q].dhe[2]==0))
        return 0;
    else
        return q;
}
int recherche_max(int tab[],int n)
{
    int i,max=tab[0];
    for (i=1;i<n;i++)
    if (tab[i]>max)
       max=tab[i];
    return max;
}
int recherche_min(int tab[],int n)
{
    int i,min=tab[0];
    for (i=1;i<n;i++)
    if (tab[i]<min)
       min=tab[i];
    return min;
}
void affichage_auteur(int m)
{
    int i;
    gotoxy(21,12);
    printf("___________________________________________________________________________");
    gotoxy(21,13);
    printf("| Code Auteur | Nom auteur | Prenom auteur | Date naissance | nationalite |");
    gotoxy(21,14);
    printf("___________________________________________________________________________");
    for(i=0;i<m;i++)
    {
        gotoxy(21,15+i);
        printf("| %d",tauteur[i].code_auteur);
        gotoxy(35,15+i);
        printf("| %s",tauteur[i].nom_auteur);
        gotoxy(48,15+i);
        printf("| %s",tauteur[i].prenom_auteur);
        gotoxy(64,15+i);
        printf("| %d/%d/%d",tauteur[i].date_naissance[0],tauteur[i].date_naissance[1],tauteur[i].date_naissance[2]);
        gotoxy(81,15+i);
        printf("| %s",tauteur[i].nationalite);
        gotoxy(95,15+i);
        printf("|");
    }
    gotoxy(21,15+m);
    printf("___________________________________________________________________________");
}
void affichage_livre(int n)
{
    int i;
    gotoxy(5,12);
    printf("_____________________________________________________________________________________________________________");
    gotoxy(5,13);
    printf("| Code Livre | Titre Livre | Nbre Pages | Prix d'achat | Date d'achat | Code Auteur |  Maison  | disponible |");
    gotoxy(5,14);
    printf("_____________________________________________________________________________________________________________");
    for(i=0;i<n;i++)
    {
        gotoxy(5,15+i);
        printf("| %d",tlivre[i].code_livre);
        gotoxy(18,15+i);
        printf("| %s",tlivre[i].titre_livre);
        gotoxy(32,15+i);
        printf("| %d",tlivre[i].nbre_pages);
        gotoxy(45,15+i);
        printf("| %f",tlivre[i].prix_achat);
        gotoxy(60,15+i);
        printf("| %d/%d/%d",tlivre[i].date_achat[0],tlivre[i].date_achat[1],tlivre[i].date_achat[2]);
        gotoxy(75,15+i);
        printf("| %d",tlivre[i].code_auteur);
        gotoxy(89,15+i);
        printf("| %s",tlivre[i].maison);
        gotoxy(100,15+i);
        printf("| %c",tlivre[i].disponible);
        gotoxy(113,15+i);
        printf("|");
    }
    gotoxy(5,15+n);
    printf("_____________________________________________________________________________________________________________");
}
void affichage_etudiant(int p)
{
    int i;
    gotoxy(21,12);
    printf("___________________________________________________________________________");
    gotoxy(21,13);
    printf("|   CIN   | Nom etudiant | Prenom etudiant | Date naissance | Code classe |");
    gotoxy(21,14);
    printf("___________________________________________________________________________");
    for(i=0;i<p;i++)
    {
        gotoxy(21,15+i);
        printf("| %d",tetudiant[i].cin);
        gotoxy(31,15+i);
        printf("| %s",tetudiant[i].nom_etudiant);
        gotoxy(46,15+i);
        printf("| %s",tetudiant[i].prenom_etudiant);
        gotoxy(64,15+i);
        printf("| %d/%d/%d",tetudiant[i].date_naissance_e[0],tetudiant[i].date_naissance_e[1],tetudiant[i].date_naissance_e[2]);
        gotoxy(81,15+i);
        printf("| %d",tetudiant[i].code_classe);
        gotoxy(95,15+i);
        printf("|");
    }
    gotoxy(21,15+p);
    printf("___________________________________________________________________________");
}
void affichage_emprunt_retour(int q)
{
    int i;
    gotoxy(30,12);
    printf("___________________________________________________________");
    gotoxy(30,13);
    printf("|  Date Emprunt  |   CIN   | Code Livre |   Date Retour   |");
    gotoxy(30,14);
    printf("___________________________________________________________");
    for(i=0;i<q;i++)
    {
        gotoxy(30,15+i);
        printf("| %d:%d %d/%d/%d",temprunt[i].dhe[0],temprunt[i].dhe[1],temprunt[i].dhe[2],temprunt[i].dhe[3],temprunt[i].dhe[4]);
        gotoxy(47,15+i);
        printf("| %d",temprunt[i].cin_emprunt);
        gotoxy(57,15+i);
        printf("| %d",temprunt[i].code_livre_emprunt);
        gotoxy(70,15+i);
        printf("| %d:%d %d/%d/%d",temprunt[i].dhr[0],temprunt[i].dhr[1],temprunt[i].dhr[2],temprunt[i].dhr[3],temprunt[i].dhr[4]);
        gotoxy(88,15+i);
        printf("|");
    }
    gotoxy(30,15+q);
    printf("___________________________________________________________");
}

int test_integer(char test[])
{
    int i,b=0;
    for(i=0;i<strlen(test);i++)
        if (!isdigit(test[i]))
           b=1;
    return b;
}
int test_float(char test[])
{
    int i,j=0,b=0,c=0;
    for(i=0;i<strlen(test);i++)
    {
        if (!isdigit(test[i])&&(test[i]!='.'))
           b=1;
        else if (test[i]=='.')
           j+=1;
    }
    if ((j>1)||(b==1))
        c=1;
    return c;
}
int test_alpaha(char test[])
{
    int i,b=0;
    for(i=0;i<strlen(test);i++)
        if (!isalpha(test[i]))
           b=1;
    return b;
}
int verif_auteur(int m, int code_auteur)
{
    int i,b=-1;
    for(i=0;i<m;i++)
    {
        if (tauteur[i].code_auteur==code_auteur)
            b=i;
    }
    return b;
}
int verif_livre(int n, int code_livre)
{
    int i,b=-1;
    for(i=0;i<n;i++)
    {
        if (tlivre[i].code_livre==code_livre)
            b=i;
    }
    return b;
}
int verif_etudiant(int p, int cin)
{
    int i,b=-1;
    for(i=0;i<p;i++)
    {
        if (tetudiant[i].cin==cin)
            b=i;
    }
    return b;
}
int verif_emprunt(int q,int code_livre)
{
    int i,b=-1;
    for(i=0;i<q;i++)
    {
        if (temprunt[i].code_livre_emprunt==code_livre)
            b=i;
    }
    return b;
}
void interface_nouveau_auteur()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*            Ajout d'un auteur                 *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code auteur   : |__________|                 *");
    gotoxy(35,5);
    printf("* Nom auteur    : |__________|                 *");
    gotoxy(35,6);
    printf("* Prenom auteur : |__________|                 *");
    gotoxy(35,7);
    printf("* Date naissance: |__/__/____|                 *");
    gotoxy(35,8);
    printf("* Nationalite   : |__________|                 *");
    gotoxy(35,9);
    printf("*                                              *");
    gotoxy(35,10);
    printf("*                                              *");
    gotoxy(35,11);
    printf("* Voulez-vous ajouter un autre auteur O/N : |_|*");
    gotoxy(35,12);
    printf("************************************************");

}
void interface_nouveau_livre()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*         Creation d\'un nouveau livre          *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code Livre    : |__________|                 *");
    gotoxy(35,5);
    printf("* Titre Livre   : |__________|                 *");
    gotoxy(35,6);
    printf("* Nbre Pages    : |__________|                 *");
    gotoxy(35,7);
    printf("* Prix d\'achat  : |__________|                 *");
    gotoxy(35,8);
    printf("* Date d\'achat  : |__/__/____|                 *");
    gotoxy(35,9);
    printf("* Code Auteur   : |__________|                 *");
    gotoxy(35,10);
    printf("* Maison        : |__________|                 *");
    gotoxy(35,11);
    printf("* Disponible O/N : |_|                         *");
    gotoxy(35,12);
    printf("*                                              *");
    gotoxy(35,13);
    printf("*                                              *");
    gotoxy(35,14);
    printf("* Voulez-vous ajouter un autre livre O/N : |_| *");
    gotoxy(35,15);
    printf("************************************************");
}
void interface_ajout_etudiant()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*             Ajout d'un etudiant              *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* CIN            : |__________|                *");
    gotoxy(35,5);
    printf("* Nom etudiant   : |__________|                *");
    gotoxy(35,6);
    printf("* Prenom etudiant: |__________|                *");
    gotoxy(35,7);
    printf("* Date naissance : |__/__/____|                *");
    gotoxy(35,8);
    printf("* Code classe    : |__________|                *");
    gotoxy(35,9);
    printf("*                                              *");
    gotoxy(35,10);
    printf("*                                              *");
    gotoxy(35,11);
    printf("*Voulez-vous ajouter un autre etudiant O/N: |_|*");
    gotoxy(35,12);
    printf("************************************************");
}
int saisie_code_auteur()
{
    char test[50];
    do{
        interface_nouveau_auteur();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_code_livre()
{
    char test[50];
    do{
        interface_nouveau_livre();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_cin()
{
    char test[50];
    do{
        interface_ajout_etudiant();
        gotoxy(55,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>8));
    return atoi(test);
}
void saisie_nom_auteur(char test[],int code_auteur)
{
    do{
        interface_nouveau_auteur();
        gotoxy(54,4);
        printf("%d",code_auteur);
        gotoxy(54,5);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_prenom_auteur(char test[],int code_auteur,char nom_auteur[])
{
    do{
        interface_nouveau_auteur();
        gotoxy(54,4);
        printf("%d",code_auteur);
        gotoxy(54,5);
        printf("%s",nom_auteur);
        gotoxy(54,6);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_nom_etudiant(char test[],int cin)
{
    do{
        interface_ajout_etudiant();
        gotoxy(55,4);
        printf("%d",cin);
        gotoxy(55,5);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_prenom_etudian(char test[],int cin,char nom_etudiant[])
{
    do{
        interface_ajout_etudiant();
        gotoxy(55,4);
        printf("%d",cin);
        gotoxy(55,5);
        printf("%s",nom_etudiant);
        gotoxy(55,6);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_titre_livre(char test[],int code_livre)
{
    do{
        interface_nouveau_livre();
        gotoxy(54,4);
        printf("%d",code_livre);
        gotoxy(54,5);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
int saisie_nbre_pages(int code_livre,char titre_livre[])
{
    char test[50];
    do{
        interface_nouveau_livre();
        gotoxy(54,4);
        printf("%d",code_livre);
        gotoxy(54,5);
        printf("%s",titre_livre);
        gotoxy(54,6);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
float saisie_prix_achat(int code_livre,char titre_livre[],int nbre_pages)
{
    char test[50];
    do{
        interface_nouveau_livre();
        gotoxy(54,4);
        printf("%d",code_livre);
        gotoxy(54,5);
        printf("%s",titre_livre);
        gotoxy(54,6);
        printf("%d",nbre_pages);
        gotoxy(54,7);
        scanf("%s",test);
      }while((test_float(test)==1)||(strlen(test)>10));
    return atof(test);
}
int saisie_annee_auteur(int code_auteur,char nom_auteur[],char prenom_auteur[])
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_auteur();
            gotoxy(54,4);
            printf("%d",code_auteur);
            gotoxy(54,5);
            printf("%s",nom_auteur);
            gotoxy(54,6);
            printf("%s",prenom_auteur);
            gotoxy(60,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_annee_livre(int code_livre,char titre_livre[],int nbre_pages,float prix_achat)
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_livre();
            gotoxy(54,4);
            printf("%d",code_livre);
            gotoxy(54,5);
            printf("%s",titre_livre);
            gotoxy(54,6);
            printf("%d",nbre_pages);
            gotoxy(54,7);
            printf("%f",prix_achat);
            gotoxy(60,8);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_annee_etudiant(int cin,char nom_etudiant[],char prenom_etudiant[])
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_ajout_etudiant();
            gotoxy(55,4);
            printf("%d",cin);
            gotoxy(55,5);
            printf("%s",nom_etudiant);
            gotoxy(55,6);
            printf("%s",prenom_etudiant);
            gotoxy(61,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_mois_auteur(int code_auteur,char nom_auteur[],char prenom_auteur[],int annee)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_auteur();
            gotoxy(54,4);
            printf("%d",code_auteur);
            gotoxy(54,5);
            printf("%s",nom_auteur);
            gotoxy(54,6);
            printf("%s",prenom_auteur);
            gotoxy(60,7);
            printf("%d",annee);
            gotoxy(57,7);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee)&&(date[1]<mois)));
    return mois;
}
int saisie_mois_livre(int code_livre,char titre_livre[],int nbre_pages,float prix_achat,int annee)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_livre();
            gotoxy(54,4);
            printf("%d",code_livre);
            gotoxy(54,5);
            printf("%s",titre_livre);
            gotoxy(54,6);
            printf("%d",nbre_pages);
            gotoxy(54,7);
            printf("%f",prix_achat);
            gotoxy(60,8);
            printf("%d",annee);
            gotoxy(57,8);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee)&&(date[1]<mois)));
    return mois;
}
int saisie_mois_etudiant(int cin,char nom_etudiant[],char prenom_etudiant[],int annee)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_ajout_etudiant();
            gotoxy(55,4);
            printf("%d",cin);
            gotoxy(55,5);
            printf("%s",nom_etudiant);
            gotoxy(55,6);
            printf("%s",prenom_etudiant);
            gotoxy(61,7);
            printf("%d",annee);
            gotoxy(58,7);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee)&&(date[1]<mois)));
    return mois;
}
int verif_jour(int annee,int mois,int jour)
{
    int b=0;
    if (((mois==1)||(mois==3)||(mois==5)||(mois==7)||(mois==8)||(mois==10)||(mois==12))&&(jour<=31))
        b=1;
    else if (((mois==4)||(mois==6)||(mois==9)||(mois==11))&&(jour<=30))
            b=1;
    else if ((mois==2)&&(((annee-1500)%4)==0)&&(jour<=29))
            b=1;
    else if ((mois==2)&&(jour<=28))
            b=1;
    return b;
}
int saisie_jour_auteur(int code_auteur,char nom_auteur[],char prenom_auteur[],int annee,int mois)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_auteur();
            gotoxy(54,4);
            printf("%d",code_auteur);
            gotoxy(54,5);
            printf("%s",nom_auteur);
            gotoxy(54,6);
            printf("%s",prenom_auteur);
            gotoxy(60,7);
            printf("%d",annee);
            gotoxy(57,7);
            printf("%d",mois);
            gotoxy(54,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee,mois,jour)==0)||((date[2]==annee)&&(date[1]==mois)&(date[0]<jour)));
    return jour;
}
int saisie_jour_livre(int code_livre,char titre_livre[],int nbre_pages,float prix_achat,int annee,int mois)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_nouveau_livre();
            gotoxy(54,4);
            printf("%d",code_livre);
            gotoxy(54,5);
            printf("%s",titre_livre);
            gotoxy(54,6);
            printf("%d",nbre_pages);
            gotoxy(54,7);
            printf("%f",prix_achat);
            gotoxy(60,8);
            printf("%d",annee);
            gotoxy(57,8);
            printf("%d",mois);
            gotoxy(54,8);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee,mois,jour)==0)||((date[2]==annee)&&(date[1]==mois)&(date[0]<jour)));
    return jour;
}
int saisie_jour_etudiant(int cin,char nom_etudiant[],char prenom_etudiant[],int annee,int mois)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_ajout_etudiant();
            gotoxy(55,4);
            printf("%d",cin);
            gotoxy(55,5);
            printf("%s",nom_etudiant);
            gotoxy(55,6);
            printf("%s",prenom_etudiant);
            gotoxy(61,7);
            printf("%d",annee);
            gotoxy(58,7);
            printf("%d",mois);
            gotoxy(55,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee,mois,jour)==0)||((date[2]==annee)&&(date[1]==mois)&(date[0]<jour)));
    return jour;
}
void saisie_date_naissance(int code_auteur,char nom_auteur[],char prenom_auteur[],int date_naissance[])
{
    date_naissance[2]=saisie_annee_auteur(code_auteur,nom_auteur,prenom_auteur);
    date_naissance[1]=saisie_mois_auteur(code_auteur,nom_auteur,prenom_auteur,date_naissance[2]);
    date_naissance[0]=saisie_jour_auteur(code_auteur,nom_auteur,prenom_auteur,date_naissance[2],date_naissance[1]);
}
void saisie_date_achat(int code_livre,char titre_livre[],int nbre_pages,float prix_achat,int date_achat[])
{
    date_achat[2]=saisie_annee_livre(code_livre,titre_livre,nbre_pages,prix_achat);
    date_achat[1]=saisie_mois_livre(code_livre,titre_livre,nbre_pages,prix_achat,date_achat[2]);
    date_achat[0]=saisie_jour_livre(code_livre,titre_livre,nbre_pages,prix_achat,date_achat[2],date_achat[1]);
}
void saisie_date_naissance_e(int cin,char nom_etudiant[],char prenom_etudiant[],int date_naissance_e[])
{
    date_naissance_e[2]=saisie_annee_etudiant(cin,nom_etudiant,prenom_etudiant);
    date_naissance_e[1]=saisie_mois_etudiant(cin,nom_etudiant,prenom_etudiant,date_naissance_e[2]);
    date_naissance_e[0]=saisie_jour_etudiant(cin,nom_etudiant,prenom_etudiant,date_naissance_e[2],date_naissance_e[1]);
}
int saisie_code_auteur_l(int m,int code_livre,char titre_livre[],int nbre_pages,float prix_achat,int date_achat[])
{
    char test[50];
    int code_auteur;
    do{
        do{
            interface_nouveau_livre();
            gotoxy(54,4);
            printf("%d",code_livre);
            gotoxy(54,5);
            printf("%s",titre_livre);
            gotoxy(54,6);
            printf("%d",nbre_pages);
            gotoxy(54,7);
            printf("%f",prix_achat);
            gotoxy(60,8);
            printf("%d",date_achat[2]);
            gotoxy(57,8);
            printf("%d",date_achat[1]);
            gotoxy(54,8);
            printf("%d",date_achat[0]);
            gotoxy(54,9);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>10));
        code_auteur=atoi(test);
      }while(verif_auteur(m,code_auteur)==-1);
      return code_auteur;
}
int saisie_code_classe(int cin,char nom_etudiant[],char prenom_etudiant[],int date_naissance_e[])
{
    char test[50];
    do{
         interface_ajout_etudiant();
         gotoxy(55,4);
         printf("%d",cin);
         gotoxy(55,5);
         printf("%s",nom_etudiant);
         gotoxy(55,6);
         printf("%s",prenom_etudiant);
         gotoxy(61,7);
         printf("%d",date_naissance_e[2]);
         gotoxy(58,7);
         printf("%d",date_naissance_e[1]);
         gotoxy(55,7);
         printf("%d",date_naissance_e[0]);
         gotoxy(55,8);
         scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
void saisie_nationalite(char test[],int code_auteur,char nom_auteur[],char prenom_auteur[],int date_naissance[])
{
    do{
        interface_nouveau_auteur();
        gotoxy(54,4);
        printf("%d",code_auteur);
        gotoxy(54,5);
        printf("%s",nom_auteur);
        gotoxy(54,6);
        printf("%s",prenom_auteur);
        gotoxy(60,7);
        printf("%d",date_naissance[2]);
        gotoxy(57,7);
        printf("%d",date_naissance[1]);
        gotoxy(54,7);
        printf("%d",date_naissance[0]);
        gotoxy(54,8);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_maison(char test[],int code_livre,char titre_livre[],int nbre_pages,float prix_achat,int date_achat[],int code_auteur)
{
    do{
        interface_nouveau_livre();
        gotoxy(54,4);
        printf("%d",code_livre);
        gotoxy(54,5);
        printf("%s",titre_livre);
        gotoxy(54,6);
        printf("%d",nbre_pages);
        gotoxy(54,7);
        printf("%f",prix_achat);
        gotoxy(60,8);
        printf("%d",date_achat[2]);
        gotoxy(57,8);
        printf("%d",date_achat[1]);
        gotoxy(54,8);
        printf("%d",date_achat[0]);
        gotoxy(54,9);
        printf("%d",code_auteur);
        gotoxy(54,10);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
int creation_nouveau_auteur(int m)
{
    FILE *Fauteur;
    char b='N';
    int code_auteur;
    do{
        code_auteur=saisie_code_auteur();
        if (verif_auteur(m,code_auteur)==-1)
        {
            tauteur[m].code_auteur=code_auteur;
            saisie_nom_auteur(tauteur[m].nom_auteur,code_auteur);
            saisie_prenom_auteur(tauteur[m].prenom_auteur,code_auteur,tauteur[m].nom_auteur);
            saisie_date_naissance(code_auteur,tauteur[m].nom_auteur,tauteur[m].prenom_auteur,tauteur[m].date_naissance);
            saisie_nationalite(tauteur[m].nationalite,code_auteur,tauteur[m].nom_auteur,tauteur[m].prenom_auteur,tauteur[m].date_naissance);
            do{
                interface_nouveau_auteur();
                gotoxy(54,4);
                printf("%d",code_auteur);
                gotoxy(54,5);
                printf("%s",tauteur[m].nom_auteur);
                gotoxy(54,6);
                printf("%s",tauteur[m].prenom_auteur);
                gotoxy(60,7);
                printf("%d",tauteur[m].date_naissance[2]);
                gotoxy(57,7);
                printf("%d",tauteur[m].date_naissance[1]);
                gotoxy(54,7);
                printf("%d",tauteur[m].date_naissance[0]);
                gotoxy(54,8);
                printf("%s",tauteur[m].nationalite);
                gotoxy(80,11);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            Fauteur=fopen("Fauteur.txt","a");
            fprintf(Fauteur,"%d %s %s %d %d %d %s \n",code_auteur,tauteur[m].nom_auteur,tauteur[m].prenom_auteur,tauteur[m].date_naissance[0],tauteur[m].date_naissance[1],tauteur[m].date_naissance[2],tauteur[m].nationalite);
            fclose(Fauteur);
            m+=1;
        }
        else
        {
            do{
                interface_nouveau_auteur();
                gotoxy(54,4);
                printf("%d",code_auteur);
                gotoxy(46,10);
                printf("\"ce code auteur est utilise\"");
                gotoxy(80,11);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
        }
      }while(toupper(b)=='O');
    return m;
}
int creation_nouveau_livre(int n,int m)
{
    FILE *Flivre;
    char b='N';
    int code_livre;
    do{
        code_livre=saisie_code_livre();
        if (verif_livre(n,code_livre)==-1)
        {
            tlivre[n].code_livre=code_livre;
            saisie_titre_livre(tlivre[n].titre_livre,code_livre);
            tlivre[n].nbre_pages=saisie_nbre_pages(code_livre,tlivre[n].titre_livre);
            tlivre[n].prix_achat=saisie_prix_achat(code_livre,tlivre[n].titre_livre,tlivre[n].nbre_pages);
            saisie_date_achat(code_livre,tlivre[n].titre_livre,tlivre[n].nbre_pages,tlivre[n].prix_achat,tlivre[n].date_achat);
            tlivre[n].code_auteur=saisie_code_auteur_l(m,code_livre,tlivre[n].titre_livre,tlivre[n].nbre_pages,tlivre[n].prix_achat,tlivre[n].date_achat);
            saisie_maison(tlivre[n].maison,code_livre,tlivre[n].titre_livre,tlivre[n].nbre_pages,tlivre[n].prix_achat,tlivre[n].date_achat,tlivre[n].code_auteur);
            gotoxy(55,11);
            printf("%c",'O');
            tlivre[n].disponible='O';
            do{
                interface_nouveau_livre();
                gotoxy(54,4);
                printf("%d",code_livre);
                gotoxy(54,5);
                printf("%s",tlivre[n].titre_livre);
                gotoxy(54,6);
                printf("%d",tlivre[n].nbre_pages);
                gotoxy(54,7);
                printf("%f",tlivre[n].prix_achat);
                gotoxy(60,8);
                printf("%d",tlivre[n].date_achat[2]);
                gotoxy(57,8);
                printf("%d",tlivre[n].date_achat[1]);
                gotoxy(54,8);
                printf("%d",tlivre[n].date_achat[0]);
                gotoxy(54,9);
                printf("%d",tlivre[n].code_auteur);
                gotoxy(54,10);
                printf("%s",tlivre[n].maison);
                gotoxy(55,11);
                printf("%c",'O');
                gotoxy(79,14);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            Flivre=fopen("Flivre.txt","a");
            fprintf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",code_livre,tlivre[n].titre_livre,tlivre[n].nbre_pages,tlivre[n].prix_achat,tlivre[n].date_achat[0],tlivre[n].date_achat[1],tlivre[n].date_achat[2],tlivre[n].code_auteur,tlivre[n].maison,tlivre[n].disponible);
            fclose(Flivre);
            n+=1;
        }
        else
        {
            do{
                interface_nouveau_livre();
                gotoxy(54,4);
                printf("%d",code_livre);
                gotoxy(46,13);
                printf("\"ce code livre est utilise\"");
                gotoxy(79,14);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
        }
      }while(toupper(b)=='O');
    return n;
}
int ajout_nouvel_etudiant(int p)
{
    FILE *Fetudiant;
    char b='N';
    int cin;
    do{
        cin=saisie_cin();
        if (verif_etudiant(p,cin)==-1)
        {
            tetudiant[p].cin=cin;
            saisie_nom_etudiant(tetudiant[p].nom_etudiant,cin);
            saisie_prenom_etudian(tetudiant[p].prenom_etudiant,cin,tetudiant[p].nom_etudiant);
            saisie_date_naissance_e(cin,tetudiant[p].nom_etudiant,tetudiant[p].prenom_etudiant,tetudiant[p].date_naissance_e);
            tetudiant[p].code_classe=saisie_code_classe(cin,tetudiant[p].nom_etudiant,tetudiant[p].prenom_etudiant,tetudiant[p].date_naissance_e);
            do{
                interface_ajout_etudiant();
                gotoxy(55,4);
                printf("%d",cin);
                gotoxy(55,5);
                printf("%s",tetudiant[p].nom_etudiant);
                gotoxy(55,6);
                printf("%s",tetudiant[p].prenom_etudiant);
                gotoxy(61,7);
                printf("%d",tetudiant[p].date_naissance_e[2]);
                gotoxy(58,7);
                printf("%d",tetudiant[p].date_naissance_e[1]);
                gotoxy(55,7);
                printf("%d",tetudiant[p].date_naissance_e[0]);
                gotoxy(55,8);
                printf("%d",tetudiant[p].code_classe);
                gotoxy(80,11);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            Fetudiant=fopen("Fetudiant.txt","a");
            fprintf(Fetudiant,"%d %s %s %d %d %d %d\n",cin,tetudiant[p].nom_etudiant,tetudiant[p].prenom_etudiant,tetudiant[p].date_naissance_e[0],tetudiant[p].date_naissance_e[1],tetudiant[p].date_naissance_e[2],tetudiant[p].code_classe);
            fclose(Fetudiant);
            p+=1;
        }
        else
        {
            do{
                interface_ajout_etudiant();
                gotoxy(55,4);
                printf("%d",cin);
                gotoxy(46,10);
                printf("\"ce code etudiant est utilise\"");
                gotoxy(80,11);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
        }
      }while(toupper(b)=='O');
    return p;
}
void interface_code_auteur_modifier()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*   Saisissez le code de l'auteur a modifier   *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code auteur   : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("************************************************");
}
void interface_code_livre_modifier()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*    Saisissez le code du livre a modifier     *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code Livre    : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("************************************************");
}
void interface_cin_modifier()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*  Saisissez le CIN de l'etudiant a modifier   *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("*        CIN    : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("************************************************");
}
int saisie_code_auteur_m()
{
    char test[50];
    do{
        interface_code_auteur_modifier();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_code_livre_m()
{
    char test[50];
    do{
        interface_code_livre_modifier();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_cin_m()
{
    char test[50];
    do{
        interface_cin_modifier();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
void interface_modification_auteur(int code_auteur_m)
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*        modification du auteur \"%d\"",code_auteur_m);
    gotoxy(82,1);
    printf("*");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* nom auteur    : |__________|                 *");
    gotoxy(35,5);
    printf("* prenom auteur : |__________|                 *");
    gotoxy(35,6);
    printf("* Date naissance: |__/__/____|                 *");
    gotoxy(35,7);
    printf("* Nationalite   : |__________|                 *");
    gotoxy(35,8);
    printf("*                                              *");
    gotoxy(35,9);
    printf("*                                              *");
    gotoxy(35,10);
    printf("*Voulez-vous confirmer la modification O/N :|_|*");
    gotoxy(35,11);
    printf("************************************************");
}
void interface_modification_livre(int code_livre_m)
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*        modification du livre \"%d\"",code_livre_m);
    gotoxy(82,1);
    printf("*");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Titre Livre   : |__________|                 *");
    gotoxy(35,5);
    printf("* Nbre Pages    : |__________|                 *");
    gotoxy(35,6);
    printf("* Prix d'achat  : |__________|                 *");
    gotoxy(35,7);
    printf("* Date d'achat  : |__/__/____|                 *");
    gotoxy(35,8);
    printf("* Code Auteur   : |__________|                 *");
    gotoxy(35,9);
    printf("* Maison        : |__________|                 *");
    gotoxy(35,10);
    printf("*                                              *");
    gotoxy(35,11);
    printf("*                                              *");
    gotoxy(35,12);
    printf("*Voulez-vous confirmer la modification O/N :|_|*");
    gotoxy(35,13);
    printf("************************************************");
}
void interface_modification_etudiant(int cin)
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*      modification de l'etudiant \"%d\"",cin);
    gotoxy(82,1);
    printf("*");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Nom etudiant   : |__________|                *");
    gotoxy(35,5);
    printf("* Prenom etudiant: |__________|                *");
    gotoxy(35,6);
    printf("* Date naissance : |__/__/____|                *");
    gotoxy(35,7);
    printf("* Code classe    : |__________|                *");
    gotoxy(35,8);
    printf("*                                              *");
    gotoxy(35,9);
    printf("*                                              *");
    gotoxy(35,10);
    printf("*Voulez-vous confirmer la modification O/N :|_|*");
    gotoxy(35,11);
    printf("************************************************");
}
void saisie_nom_auteur_m(char test[],int code_auteur_m)
{
    system("cls");
    do{
        interface_modification_auteur(code_auteur_m);
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_prenom_auteur_m(char test[],int code_auteur_m,char nom_auteur_m[])
{
    system("cls");
    do{
        interface_modification_auteur(code_auteur_m);
        gotoxy(54,4);
        printf("%s",nom_auteur_m);
        gotoxy(54,5);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_nom_etudiant_m(char test[],int cin)
{
    system("cls");
    do{
        interface_modification_etudiant(cin);
        gotoxy(55,4);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_prenom_etudiant_m(char test[],int cin,char nom_etudiant_m[])
{
    system("cls");
    do{
        interface_modification_etudiant(cin);
        gotoxy(55,4);
        printf("%s",nom_etudiant_m);
        gotoxy(55,5);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void saisie_titre_livre_m(char test[],int code_livre_m)
{
    system("cls");
    do{
        interface_modification_livre(code_livre_m);
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
int saisie_nbre_pages_m(int code_livre_m,char titre_livre_m[])
{
    char test[50];
    do{
        interface_modification_livre(code_livre_m);
        gotoxy(54,4);
        printf("%s",titre_livre_m);
        gotoxy(54,5);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
float saisie_prix_achat_m(int code_livre_m,char titre_livre_m[],int nbre_pages_m)
{
    char test[50];
    do{
        interface_modification_livre(code_livre_m);
        gotoxy(54,4);
        printf("%s",titre_livre_m);
        gotoxy(54,5);
        printf("%d",nbre_pages_m);
        gotoxy(54,6);
        scanf("%s",test);
      }while((test_float(test)==1)||(strlen(test)>10));
    return atof(test);
}
int saisie_annee_auteur_m(int code_auteur_m,char nom_auteur_m[],char prenom_auteur_m[])
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_auteur(code_auteur_m);
            gotoxy(54,4);
            printf("%s",nom_auteur_m);
            gotoxy(54,5);
            printf("%s",prenom_auteur_m);
            gotoxy(60,6);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_annee_livre_m(int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m)
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_livre(code_livre_m);
            gotoxy(54,4);
            printf("%s",titre_livre_m);
            gotoxy(54,5);
            printf("%d",nbre_pages_m);
            gotoxy(54,6);
            printf("%f",prix_achat_m);
            gotoxy(60,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_annee_etudiant_m(int cin,char nom_etudiant_m[],char prenom_etudiant_m[])
{
    char test[50];
    int annee,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_etudiant(cin);
            gotoxy(55,4);
            printf("%s",nom_etudiant_m);
            gotoxy(55,5);
            printf("%s",prenom_etudiant_m);
            gotoxy(61,6);
            scanf("%s",test);
          }while(test_integer(test)==1);
        annee=atoi(test);
      }while((annee>date[2])||(annee<1));
    return annee;
}
int saisie_mois_auteur_m(int code_auteur_m,char nom_auteur_m[],char prenom_auteur_m[],int annee_m)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_auteur(code_auteur_m);
            gotoxy(54,4);
            printf("%s",nom_auteur_m);
            gotoxy(54,5);
            printf("%s",prenom_auteur_m);
            gotoxy(60,6);
            printf("%d",annee_m);
            gotoxy(57,6);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee_m)&&(date[1]<mois)));
    return mois;
}
int saisie_mois_livre_m(int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m,int annee_m)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_livre(code_livre_m);
            gotoxy(54,4);
            printf("%s",titre_livre_m);
            gotoxy(54,5);
            printf("%d",nbre_pages_m);
            gotoxy(54,6);
            printf("%f",prix_achat_m);
            gotoxy(60,7);
            printf("%d",annee_m);
            gotoxy(57,7);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee_m)&&(date[1]<mois)));
    return mois;
}
int saisie_mois_etudiant_m(int cin,char nom_etudiant_m[],char prenom_etudiant_m[],int annee_m)
{
    char test[50];
    int mois,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_etudiant(cin);
            gotoxy(55,4);
            printf("%s",nom_etudiant_m);
            gotoxy(55,5);
            printf("%s",prenom_etudiant_m);
            gotoxy(61,6);
            printf("%d",annee_m);
            gotoxy(58,6);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>2));
        mois=atoi(test);
      }while((mois<1)||(mois>12)||((date[2]==annee_m)&&(date[1]<mois)));
    return mois;
}
int saisie_jour_auteur_m(int code_auteur_m,char nom_auteur_m[],char prenom_auteur_m[],int annee_m,int mois_m)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_auteur(code_auteur_m);
            gotoxy(54,4);
            printf("%s",nom_auteur_m);
            gotoxy(54,5);
            printf("%s",prenom_auteur_m);
            gotoxy(60,6);
            printf("%d",annee_m);
            gotoxy(57,6);
            printf("%d",mois_m);
            gotoxy(54,6);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee_m,mois_m,jour)==0)||((date[2]==annee_m)&&(date[1]==mois_m)&(date[0]<jour)));
    return jour;
}
int saisie_jour_livre_m(int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m,int annee_m,int mois_m)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_livre(code_livre_m);
            gotoxy(54,4);
            printf("%s",titre_livre_m);
            gotoxy(54,5);
            printf("%d",nbre_pages_m);
            gotoxy(54,6);
            printf("%f",prix_achat_m);
            gotoxy(60,7);
            printf("%d",annee_m);
            gotoxy(57,7);
            printf("%d",mois_m);
            gotoxy(54,7);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee_m,mois_m,jour)==0)||((date[2]==annee_m)&&(date[1]==mois_m)&(date[0]<jour)));
    return jour;
}
int saisie_jour_etudiant_m(int cin,char nom_etudiant_m[],char prenom_etudiant_m[],int annee_m,int mois_m)
{
    char test[50];
    int jour,date[3];
    extract_date(date);
    do{
        do{
            interface_modification_etudiant(cin);
            gotoxy(55,4);
            printf("%s",nom_etudiant_m);
            gotoxy(55,5);
            printf("%s",prenom_etudiant_m);
            gotoxy(61,6);
            printf("%d",annee_m);
            gotoxy(58,6);
            printf("%d",mois_m);
            gotoxy(55,6);
            scanf("%s",test);
          }while(test_integer(test)==1);
        jour=atoi(test);
      }while((jour<1)||(verif_jour(annee_m,mois_m,jour)==0)||((date[2]==annee_m)&&(date[1]==mois_m)&(date[0]<jour)));
    return jour;
}
void saisie_date_naissance_m(int code_auteur_m,char nom_auteur_m[],char prenom_auteur_m[],int date_naissance_m[])
{
    date_naissance_m[2]=saisie_annee_auteur_m(code_auteur_m,nom_auteur_m,prenom_auteur_m);
    date_naissance_m[1]=saisie_mois_auteur_m(code_auteur_m,nom_auteur_m,prenom_auteur_m,date_naissance_m[2]);
    date_naissance_m[0]=saisie_jour_auteur_m(code_auteur_m,nom_auteur_m,prenom_auteur_m,date_naissance_m[2],date_naissance_m[1]);
}
void saisie_date_achat_m(int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m,int date_achat_m[])
{
    date_achat_m[2]=saisie_annee_livre_m(code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m);
    date_achat_m[1]=saisie_mois_livre_m(code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m,date_achat_m[2]);
    date_achat_m[0]=saisie_jour_livre_m(code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m,date_achat_m[2],date_achat_m[1]);
}
void saisie_date_naissance_e_m(int cin,char nom_etudiant_m[],char prenom_etudiant_m[],int date_naissance_e_m[])
{
    date_naissance_e_m[2]=saisie_annee_etudiant_m(cin,nom_etudiant_m,prenom_etudiant_m);
    date_naissance_e_m[1]=saisie_mois_etudiant_m(cin,nom_etudiant_m,prenom_etudiant_m,date_naissance_e_m[2]);
    date_naissance_e_m[0]=saisie_jour_etudiant_m(cin,nom_etudiant_m,prenom_etudiant_m,date_naissance_e_m[2],date_naissance_e_m[1]);
}
int saisie_code_auteur_l_m(int m,int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m,int date_achat_m[])
{
    char test[50];
    int code_auteur_m;
    do{
        do{
            interface_modification_livre(code_livre_m);
            gotoxy(54,4);
            printf("%s",titre_livre_m);
            gotoxy(54,5);
            printf("%d",nbre_pages_m);
            gotoxy(54,6);
            printf("%f",prix_achat_m);
            gotoxy(60,7);
            printf("%d",date_achat_m[2]);
            gotoxy(57,7);
            printf("%d",date_achat_m[1]);
            gotoxy(54,7);
            printf("%d",date_achat_m[0]);
            gotoxy(54,8);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>10));
        code_auteur_m=atoi(test);
      }while(verif_auteur(m,code_auteur_m)==-1);
      return code_auteur_m;
}
void saisie_nationalite_m(int code_auteur_m,char nom_auteur_m[],char prenom_auteur_m[],int date_naissance_m[],char test[])
{
    do{
        interface_modification_auteur(code_auteur_m);
        gotoxy(54,4);
        printf("%s",nom_auteur_m);
        gotoxy(54,5);
        printf("%s",prenom_auteur_m);
        gotoxy(60,6);
        printf("%d",date_naissance_m[2]);
        gotoxy(57,6);
        printf("%d",date_naissance_m[1]);
        gotoxy(54,6);
        printf("%d",date_naissance_m[0]);
        gotoxy(54,7);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
int saisie_code_classe_m(int cin,char nom_etudiant_m[],char prenom_etudiant_m[],int date_naissance_e_m[])
{
    char test[50];
    do{
        interface_modification_etudiant(cin);
        gotoxy(55,4);
        printf("%s",nom_etudiant_m);
        gotoxy(55,5);
        printf("%s",prenom_etudiant_m);
        gotoxy(61,6);
        printf("%d",date_naissance_e_m[2]);
        gotoxy(58,6);
        printf("%d",date_naissance_e_m[1]);
        gotoxy(55,6);
        printf("%d",date_naissance_e_m[0]);
        gotoxy(55,7);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
void saisie_maison_m(char test[],int code_livre_m,char titre_livre_m[],int nbre_pages_m,float prix_achat_m,int date_achat_m[],int code_auteur_m)
{
    do{
        interface_modification_livre(code_livre_m);
        gotoxy(54,4);
        printf("%s",titre_livre_m);
        gotoxy(54,5);
        printf("%d",nbre_pages_m);
        gotoxy(54,6);
        printf("%f",prix_achat_m);
        gotoxy(60,7);
        printf("%d",date_achat_m[2]);
        gotoxy(57,7);
        printf("%d",date_achat_m[1]);
        gotoxy(54,7);
        printf("%d",date_achat_m[0]);
        gotoxy(54,8);
        printf("%d",code_auteur_m);
        gotoxy(54,9);
        scanf("%s",test);
      }while((test_alpaha(test)==1)||(strlen(test)>10));
}
void modification_auteur(int m)
{
    FILE *Fauteur;
    int code_auteur_m,i,d,date_naissance_m[3];
    char nom_auteur_m[10],nationalite_m[10],b,c,prenom_auteur_m[10];
    do{
        d=0;
        code_auteur_m=saisie_code_auteur_m();
        i=verif_auteur(m,code_auteur_m);
        if (i!=-1)
        {
            saisie_nom_auteur_m(nom_auteur_m,code_auteur_m);
            saisie_prenom_auteur_m(prenom_auteur_m,code_auteur_m,nom_auteur_m);
            saisie_date_naissance_m(code_auteur_m,nom_auteur_m,prenom_auteur_m,date_naissance_m);
            saisie_nationalite_m(code_auteur_m,nom_auteur_m,prenom_auteur_m,date_naissance_m,nationalite_m);
            do{
                gotoxy(80,10);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            if (toupper(b)=='O')
            {
                strcpy(tauteur[i].nom_auteur,nom_auteur_m);
                strcpy(tauteur[i].prenom_auteur,prenom_auteur_m);
                tauteur[i].date_naissance[2]=date_naissance_m[2];
                tauteur[i].date_naissance[1]=date_naissance_m[1];
                tauteur[i].date_naissance[0]=date_naissance_m[0];
                strcpy(tauteur[i].nationalite,nationalite_m);
            }
        }
        else
        {
            do{
                interface_code_auteur_modifier();
                gotoxy(54,4);
                printf("%d",code_auteur_m);
                gotoxy(47,5);
                printf("\"code livre invalide\"");
                gotoxy(37,6);
                printf("voulez-vous modifier un livre O/N : |_|");
                gotoxy(74,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
              if (toupper(c)=='O')
                 d=1;
        }
      }while(d==1);
      Fauteur=fopen("Fauteur.txt","w");
      for(i=0;i<m;i++)
      fprintf(Fauteur,"%d %s %s %d %d %d %s \n",tauteur[i].code_auteur,tauteur[i].nom_auteur,tauteur[i].prenom_auteur,tauteur[i].date_naissance[0],tauteur[i].date_naissance[1],tauteur[i].date_naissance[2],tauteur[i].nationalite);
      fclose(Fauteur);
}
void modification_livre(int n,int m)
{
    FILE *Flivre;
    int code_livre_m,i,d,nbre_pages_m,date_achat_m[3],code_auteur_m;
    char titre_livre_m[10],maison_m[10],b,c;
    float prix_achat_m;
    do{
        d=0;
        code_livre_m=saisie_code_livre_m();
        i=verif_livre(n,code_livre_m);
        if (i!=-1)
        {
            saisie_titre_livre_m(titre_livre_m,code_livre_m);
            nbre_pages_m=saisie_nbre_pages_m(code_livre_m,titre_livre_m);
            prix_achat_m=saisie_prix_achat_m(code_livre_m,titre_livre_m,nbre_pages_m);
            saisie_date_achat_m(code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m,date_achat_m);
            code_auteur_m=saisie_code_auteur_l_m(m,code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m,date_achat_m);
            saisie_maison_m(maison_m,code_livre_m,titre_livre_m,nbre_pages_m,prix_achat_m,date_achat_m,code_auteur_m);
            do{
                gotoxy(80,12);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            if (toupper(b)=='O')
            {
                strcpy(tlivre[i].titre_livre,titre_livre_m);
                tlivre[i].nbre_pages=nbre_pages_m;
                tlivre[i].prix_achat=prix_achat_m;
                tlivre[i].date_achat[2]=date_achat_m[2];
                tlivre[i].date_achat[1]=date_achat_m[1];
                tlivre[i].date_achat[0]=date_achat_m[0];
                tlivre[i].code_auteur=code_auteur_m;
                strcpy(tlivre[i].maison,maison_m);
            }
        }
        else
        {
            do{
                interface_code_livre_modifier();
                gotoxy(54,4);
                printf("%d",code_livre_m);
                gotoxy(47,5);
                printf("\"code livre invalide\"");
                gotoxy(37,6);
                printf("voulez-vous modifier un livre O/N : |_|");
                gotoxy(76,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
              if (toupper(c)=='O')
                 d=1;
        }
      }while(d==1);
      Flivre=fopen("Flivre.txt","w");
      for(i=0;i<n;i++)
      fprintf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",tlivre[i].code_livre,tlivre[i].titre_livre,tlivre[i].nbre_pages,tlivre[i].prix_achat,tlivre[i].date_achat[0],tlivre[i].date_achat[1],tlivre[i].date_achat[2],tlivre[i].code_auteur,tlivre[i].maison,tlivre[i].disponible);
      fclose(Flivre);
}
void modification_etudiant(int p)
{
    FILE *Fetudiant;
    int cin_m,i,d,date_naissance_e_m[3],code_classe_m;
    char nom_etudiant_m[10],b,c,prenom_etudiant_m[10];
    do{
        d=0;
        cin_m=saisie_cin_m();
        i=verif_etudiant(p,cin_m);
        if (i!=-1)
        {
            saisie_nom_etudiant_m(nom_etudiant_m,cin_m);
            saisie_prenom_etudiant_m(prenom_etudiant_m,cin_m,nom_etudiant_m);
            saisie_date_naissance_e_m(cin_m,nom_etudiant_m,prenom_etudiant_m,date_naissance_e_m);
            code_classe_m=saisie_code_classe_m(cin_m,nom_etudiant_m,prenom_etudiant_m,date_naissance_e_m);
            do{
                gotoxy(80,10);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            if (toupper(b)=='O')
            {
                strcpy(tetudiant[i].nom_etudiant,nom_etudiant_m);
                strcpy(tetudiant[i].prenom_etudiant,prenom_etudiant_m);
                tetudiant[i].date_naissance_e[2]=date_naissance_e_m[2];
                tetudiant[i].date_naissance_e[1]=date_naissance_e_m[1];
                tetudiant[i].date_naissance_e[0]=date_naissance_e_m[0];
                tetudiant[i].code_classe=code_classe_m;
            }
        }
        else
        {
            do{
                interface_cin_modifier();
                gotoxy(54,4);
                printf("%d",cin_m);
                gotoxy(50,5);
                printf("\"CIN invalide\"");
                gotoxy(37,6);
                printf("voulez-vous modifier un etudiant O/N : |_|");
                gotoxy(77,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
              if (toupper(c)=='O')
                 d=1;
        }
      }while(d==1);
      Fetudiant=fopen("Fetudiant.txt","w");
      for(i=0;i<p;i++)
      fprintf(Fetudiant,"%d %s %s %d %d %d %d\n",tetudiant[i].cin,tetudiant[i].nom_etudiant,tetudiant[i].prenom_etudiant,tetudiant[i].date_naissance_e[0],tetudiant[i].date_naissance_e[1],tetudiant[i].date_naissance_e[2],tetudiant[i].code_classe);
      fclose(Fetudiant);
}
void interface_suppression_auteur()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*  Saisissez le code de l'auteur a supprimer   *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code Auteur   : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("*                la suppression                *");
    gotoxy(35,9);
    printf("************************************************");
}
void interface_suppression_livre()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*    Saisissez le code du livre a supprimer    *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code Livre    : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("*                la suppression                *");
    gotoxy(35,9);
    printf("************************************************");
}
void interface_suppression_etudiant()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*  Saisissez le CIN de l'etudiant a supprimer  *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("*        CIN    : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("*                la suppression                *");
    gotoxy(35,9);
    printf("************************************************");
}
int saisie_code_auteur_supp()
{
    char test[50];
    do{
        interface_suppression_auteur();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_code_livre_supp()
{
    char test[50];
    do{
        interface_suppression_livre();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int saisie_cin_supp()
{
    char test[50];
    do{
        interface_suppression_etudiant();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
int suppression_auteur(int m)
{
    FILE *Fauteur;
    int code_auteur_sup,i,j,d;
    char c;
    do{
        d=0;
        code_auteur_sup=saisie_code_auteur_supp();
        i=verif_auteur(m,code_auteur_sup);
        if (i!=-1)
        {
            for(j=i;j<(m-1);j++)
            {
                tauteur[j].code_auteur=tauteur[j+1].code_auteur;
                strcpy(tauteur[j].nom_auteur,tauteur[j+1].nom_auteur);
                strcpy(tauteur[j].prenom_auteur,tauteur[j+1].prenom_auteur);
                tauteur[j].date_naissance[2]=tauteur[j+1].date_naissance[2];
                tauteur[j].date_naissance[1]=tauteur[j+1].date_naissance[1];
                tauteur[j].date_naissance[0]=tauteur[j+1].date_naissance[0];
                strcpy(tauteur[j].nationalite,tauteur[j+1].nationalite);
            }
        }
        else
        {
            do{
                interface_suppression_auteur();
                gotoxy(54,4);
                printf("%d",code_auteur_sup);
                gotoxy(47,5);
                printf("\"code auteur invalide\"");
                gotoxy(37,6);
                printf("voulez-vous supprimer un auteur O/N : |_|");
                gotoxy(76,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
                if (toupper(c)=='O')
                    d=1;
        }
      }while (d==1);
      Fauteur=fopen("Fauteur.txt","w");
      for(i=0;i<m-1;i++)
      fprintf(Fauteur,"%d %s %s %d %d %d %s \n",tauteur[i].code_auteur,tauteur[i].nom_auteur,tauteur[i].prenom_auteur,tauteur[i].date_naissance[0],tauteur[i].date_naissance[1],tauteur[i].date_naissance[2],tauteur[i].nationalite);
      fclose(Fauteur);
      return (m-1);
}
int suppression_livre(int n)
{
   FILE *Flivre;
   int code_livre_sup,i,j,d;
    char c;
    do{
        d=0;
        code_livre_sup=saisie_code_livre_supp();
        i=verif_livre(n,code_livre_sup);
        if (i!=-1)
        {
            for(j=i;j<(n-1);j++)
            {
                tlivre[j].code_livre=tlivre[j+1].code_livre;
                strcpy(tlivre[j].titre_livre,tlivre[j+1].titre_livre);
                tlivre[j].nbre_pages=tlivre[j+1].nbre_pages;
                tlivre[j].prix_achat= tlivre[j+1].prix_achat;
                tlivre[j].date_achat[2]=tlivre[j+1].date_achat[2];
                tlivre[j].date_achat[1]=tlivre[j+1].date_achat[1];
                tlivre[j].date_achat[0]=tlivre[j+1].date_achat[0];
                tlivre[j].code_auteur=tlivre[j+1].code_auteur;
                strcpy(tlivre[j+1].maison,tlivre[j+1].maison);
                tlivre[j].disponible=tlivre[j+1].disponible;
            }
        }
        else
        {
            do{
                interface_suppression_livre();
                gotoxy(54,4);
                printf("%d",code_livre_sup);
                gotoxy(47,5);
                printf("\"code livre invalide\"");
                gotoxy(37,6);
                printf("voulez-vous supprimer un livre O/N : |_|");
                gotoxy(75,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
                if (toupper(c)=='O')
                    d=1;
        }
      }while (d==1);
      Flivre=fopen("Flivre.txt","w");
      for(i=0;i<n-1;i++)
      fprintf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",tlivre[i].code_livre,tlivre[i].titre_livre,tlivre[i].nbre_pages,tlivre[i].prix_achat,tlivre[i].date_achat[0],tlivre[i].date_achat[1],tlivre[i].date_achat[2],tlivre[i].code_auteur,tlivre[i].maison,tlivre[i].disponible);
      fclose(Flivre);
      return (n-1);
}
int suppression_etudiant(int p)
{
    FILE *Fetudiant;
    int cin,i,j,d;
    char c;
    do{
        d=0;
        cin=saisie_cin_supp();
        i=verif_etudiant(p,cin);
        if (i!=-1)
        {
            for(j=i;j<(p-1);j++)
            {
                tetudiant[j].cin=tetudiant[j+1].cin;
                strcpy(tetudiant[j].nom_etudiant,tetudiant[j+1].nom_etudiant);
                strcpy(tetudiant[j].prenom_etudiant,tetudiant[j+1].prenom_etudiant);
                tetudiant[j].date_naissance_e[2]=tetudiant[j+1].date_naissance_e[2];
                tetudiant[j].date_naissance_e[1]=tetudiant[j+1].date_naissance_e[1];
                tetudiant[j].date_naissance_e[0]=tetudiant[j+1].date_naissance_e[0];
                tetudiant[j].code_classe=tetudiant[j+1].code_classe;
            }
        }
        else
        {
            do{
                interface_suppression_etudiant();
                gotoxy(54,4);
                printf("%d",cin);
                gotoxy(47,5);
                printf("\"code auteur invalide\"");
                gotoxy(37,6);
                printf("voulez-vous supprimer un etudiant O/N : |_|");
                gotoxy(78,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
                if (toupper(c)=='O')
                    d=1;
        }
      }while (d==1);
      Fetudiant=fopen("Fetudiant.txt","w");
      for(i=0;i<p-1;i++)
      fprintf(Fetudiant,"%d %s %s %d %d %d %d\n",tetudiant[i].cin,tetudiant[i].nom_etudiant,tetudiant[i].prenom_etudiant,tetudiant[i].date_naissance_e[0],tetudiant[i].date_naissance_e[1],tetudiant[i].date_naissance_e[2],tetudiant[i].code_classe);
      fclose(Fetudiant);
      return (p-1);
}
int menu_gestion_auteur(int m)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*            Gestion des auteurs               *");
            gotoxy(35,3);
            printf("*                                              *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*        1-Ajout d'un nouvel auteur            *");
            gotoxy(35,6);
            printf("*        2-Modification d'un auteur existant   *");
            gotoxy(35,7);
            printf("*        3-Suppression d'un auteur existant    *");
            gotoxy(35,8);
            printf("*        4-Quitter                             *");
            gotoxy(35,9);
            printf("*                                              *");
            gotoxy(35,10);
            printf("*                                   Choix : |_|*");
            gotoxy(35,11);
            printf("************************************************");
            affichage_auteur(m);
            gotoxy(80,10);
            scanf("%d",&a);
          }while((a<1)||(a>4));
        switch(a)
        {
        case 1:
            m=creation_nouveau_auteur(m);
            break;
        case 2:
            modification_auteur(m);
            break;
        case 3:
            m=suppression_auteur(m);
            break;
        case 4:
            break;
        }
      }while (a!=4);
    return m;
}
int menu_gestion_livre(int n,int m)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*            Gestion des Livres                *");
            gotoxy(35,3);
            printf("*                                              *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*        1-Creation d un nouveau livre         *");
            gotoxy(35,6);
            printf("*        2-Modification d'un livre existant    *");
            gotoxy(35,7);
            printf("*        3-Suppression d'un livre existant     *");
            gotoxy(35,8);
            printf("*        4-Quitter                             *");
            gotoxy(35,9);
            printf("*                                              *");
            gotoxy(35,10);
            printf("*                                   Choix : |_|*");
            gotoxy(35,11);
            printf("************************************************");
            affichage_livre(n);
            gotoxy(80,10);
            scanf("%d",&a);
          }while((a<1)||(a>4));
        switch(a)
        {
        case 1:
            n=creation_nouveau_livre(n,m);
            break;
        case 2:
            modification_livre(n,m);
            break;
        case 3:
            n=suppression_livre(n);
            break;
        case 4:
            break;
        }
      }while (a!=4);
    return n;
}
int menu_gestion_etudiants(int p)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*            Gestion des etudiants             *");
            gotoxy(35,3);
            printf("*                                              *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*       1-Ajout d'un nouvel etudiant           *");
            gotoxy(35,6);
            printf("*       2-Modification d'un etudiant existant  *");
            gotoxy(35,7);
            printf("*       3-Suppression d'un etudiant  existant  *");
            gotoxy(35,8);
            printf("*       4-Quitter                              *");
            gotoxy(35,9);
            printf("*                                              *");
            gotoxy(35,10);
            printf("*                                   Choix : |_|*");
            gotoxy(35,11);
            printf("************************************************");
            affichage_etudiant(p);
            gotoxy(80,10);
            scanf("%d",&a);
          }while((a<1)||(a>4));
        switch(a)
        {
        case 1:
            p=ajout_nouvel_etudiant(p);
            break;
        case 2:
            modification_etudiant(p);
            break;
        case 3:
            p=suppression_etudiant(p);
            break;
        case 4:
            break;
        }
      }while (a!=4);
    return p;
}
void interface_emprunt_livre(int date[],int heure[])
{
    extract_date(date);
    extract_time(heure);
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*               Emprunt de Livre               *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    if (heure[0]<10)
    {
        gotoxy(35,4);
        printf("* Date Emprunt  : |0%d",heure[0]);
    }
    else
    {
        gotoxy(35,4);
        printf("* Date Emprunt  : |%d",heure[0]);
    }
    if (heure[1]<10)
    {
        gotoxy(56,4);
        printf(":0%d",heure[1]);
    }
    else
    {
        gotoxy(56,4);
        printf(":%d",heure[1]);
    }
    if (date[0]<10)
    {
        gotoxy(59,4);
        printf("| |0%d",date[0]);
    }
    else
    {
        gotoxy(59,4);
        printf("| |%d",date[0]);
    }
    if (date[1]<10)
    {
        gotoxy(64,4);
        printf("/0%d",date[1]);
    }
    else
    {
        gotoxy(64,4);
        printf("/%d",date[1]);
    }
    gotoxy(67,4);
    printf("/%d",date[2]);
    gotoxy(72,4);
    printf("|         *");
    gotoxy(35,5);
    printf("*     CIN       : |__________|                 *");
    gotoxy(35,6);
    printf("* Code Livre    : |__________|                 *");
    gotoxy(35,7);
    printf("*                                              *");
    gotoxy(35,8);
    printf("*                                              *");
    gotoxy(35,9);
    printf("*Voulez-vous emprunter un autre livre O/N : |_|*");
    gotoxy(35,10);
    printf("************************************************");
}
int saisie_cin_emprunt(int p)
{
    char test[50];
    int heure[2],date[3];
    int cin;
    do{
        do{
            interface_emprunt_livre(date,heure);
            gotoxy(54,5);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>8));
          cin=atoi(test);
      }while(verif_etudiant(p,cin)==-1);
    return cin;
}
int saisie_code_livre_emprunt(int n,int cin,int date[],int heure[])
{
    char test[50];
    int code_livre;
    do{
        do{
            interface_emprunt_livre(date,heure);
            gotoxy(54,5);
            printf("%d",cin);
            gotoxy(54,6);
            scanf("%s",test);
          }while((test_integer(test)==1)||(strlen(test)>8));
          code_livre=atoi(test);
      }while(verif_livre(n,code_livre)==-1);
    return code_livre;
}
int emprunt_livre(int q,int n,int p)
{
    FILE *Fempruntretour,*Flivre;
    char b='N';
    int cin,code_livre,i,date[3],heure[2];
    do{
        cin=saisie_cin_emprunt(p);
        code_livre=saisie_code_livre_emprunt(n,cin,date,heure);
        i=verif_livre(n,code_livre);
        if (tlivre[i].disponible=='O')
        {
            temprunt[q].dhe[0]=heure[0];
            temprunt[q].dhe[1]=heure[1];
            temprunt[q].dhe[2]=date[0];
            temprunt[q].dhe[3]=date[1];
            temprunt[q].dhe[4]=date[2];
            temprunt[q].cin_emprunt=cin;
            temprunt[q].code_livre_emprunt=code_livre;
            tlivre[i].disponible='N';
            do{
                interface_emprunt_livre(date,heure);
                gotoxy(54,5);
                printf("%d",cin);
                gotoxy(54,6);
                printf("%d",code_livre);
                gotoxy(80,9);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            Fempruntretour=fopen("Fempruntretour.txt","a");
            fprintf(Fempruntretour,"%d %d %d %d %d %d %d %d %d %d %d %d\n",temprunt[q].dhe[0],temprunt[q].dhe[1],temprunt[q].dhe[2],temprunt[q].dhe[3],temprunt[q].dhe[4],temprunt[q].cin_emprunt,temprunt[q].code_livre_emprunt,0,0,0,0,0);
            fclose(Fempruntretour);
            q+=1;
        }
        else
        {
            do{
                interface_emprunt_livre(date,heure);
                gotoxy(54,5);
                printf("%d",cin);
                gotoxy(54,6);
                printf("%d",code_livre);
                gotoxy(40,8);
                printf("\"ce livre n'est pas disponible\"");
                gotoxy(80,9);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
        }
        Flivre=fopen("Flivre.txt","w");
        for(i=0;i<n;i++)
        fprintf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",tlivre[i].code_livre,tlivre[i].titre_livre,tlivre[i].nbre_pages,tlivre[i].prix_achat,tlivre[i].date_achat[0],tlivre[i].date_achat[1],tlivre[i].date_achat[2],tlivre[i].code_auteur,tlivre[i].maison,tlivre[i].disponible);
        fclose(Flivre);
      }while(toupper(b)=='O');
      printf("%d",q);
      getch();
    return q;
}
void interface_retour_livre(int code_livre,int cin,int date_r[],int heure_r[],int i)
{
    extract_date(date_r);
    extract_time(heure_r);
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*               retour du Livre \"%d\"",code_livre);
    gotoxy(82,1);
    printf("*");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
   if (temprunt[i].dhe[0]<10)
    {
        gotoxy(35,4);
        printf("* Date Emprunt  : |0%d",temprunt[i].dhe[0]);
    }
    else
    {
        gotoxy(35,4);
        printf("* Date Emprunt  : |%d",temprunt[i].dhe[0]);
    }
    if (temprunt[i].dhe[1]<10)
    {
        gotoxy(56,4);
        printf(":0%d",temprunt[i].dhe[1]);
    }
    else
    {
        gotoxy(56,4);
        printf(":%d",temprunt[i].dhe[1]);
    }
    if (temprunt[i].dhe[2]<10)
    {
        gotoxy(59,4);
        printf("| |0%d",temprunt[i].dhe[2]);
    }
    else
    {
        gotoxy(59,4);
        printf("| |%d",temprunt[i].dhe[2]);
    }
    if (temprunt[i].dhe[3]<10)
    {
        gotoxy(64,4);
        printf("/0%d",temprunt[i].dhe[3]);
    }
    else
    {
        gotoxy(64,4);
        printf("/%d",temprunt[i].dhe[3]);
    }
    gotoxy(67,4);
    printf("/%d",temprunt[i].dhe[4]);
    gotoxy(72,4);
    printf("|         *");
    gotoxy(35,5);
    printf("*     CIN       : |________|                   *");
    gotoxy(54,5);
    printf("%d",cin);
    if (heure_r[0]<10)
    {
        gotoxy(35,6);
        printf("* Date Emprunt  : |0%d",heure_r[0]);
    }
    else
    {
        gotoxy(35,6);
        printf("* Date Emprunt  : |%d",heure_r[0]);
    }
    if (heure_r[1]<10)
    {
        gotoxy(56,6);
        printf(":0%d",heure_r[1]);
    }
    else
    {
        gotoxy(56,6);
        printf(":%d",heure_r[1]);
    }
    if (date_r[0]<10)
    {
        gotoxy(59,6);
        printf("| |0%d",date_r[0]);
    }
    else
    {
        gotoxy(59,6);
        printf("| |%d",date_r[0]);
    }
    if (date_r[1]<10)
    {
        gotoxy(64,6);
        printf("/0%d",date_r[1]);
    }
    else
    {
        gotoxy(64,6);
        printf("/%d",date_r[1]);
    }
    gotoxy(67,6);
    printf("/%d",date_r[2]);
    gotoxy(72,6);
    printf("|         *");
    gotoxy(35,7);
    printf("*                                              *");
    gotoxy(35,8);
    printf("*                                              *");
    gotoxy(35,9);
    printf("*Voulez-vous confirmer le retour livre O/N :|_|*");
    gotoxy(35,10);
    printf("************************************************");
}
void interface_code_retour_livre()
{
    system("cls");
    gotoxy(35,0);
    printf("************************************************");
    gotoxy(35,1);
    printf("*    Saisissez le code du livre a rtourner     *");
    gotoxy(35,2);
    printf("*                                              *");
    gotoxy(35,3);
    printf("*                                              *");
    gotoxy(35,4);
    printf("* Code Livre    : |__________|                 *");
    gotoxy(35,5);
    printf("*                                              *");
    gotoxy(35,6);
    printf("*                                              *");
    gotoxy(35,7);
    printf("*        Appuez sur Entree pour valider        *");
    gotoxy(35,8);
    printf("************************************************");
}
int saisie_code_livre_r()
{
    char test[50];
    do{
        interface_code_retour_livre();
        gotoxy(54,4);
        scanf("%s",test);
      }while((test_integer(test)==1)||(strlen(test)>10));
    return atoi(test);
}
void retour_livre(int n,int q)
{
    FILE *Flivre,*Fempruntretour;
    int code_livre,i,j,k,date_r[3],heure_r[2];
    char b,c;
    do{
        c='N';
        code_livre=saisie_code_livre_r();
        i=verif_livre(n,code_livre);
        j=verif_emprunt(q,code_livre);
        if ((i!=-1)&&(tlivre[i].disponible=='N'))
        {
            do{
                interface_retour_livre(code_livre,temprunt[j].cin_emprunt,date_r,heure_r,i);
                gotoxy(80,9);
                fflush(stdin);
                scanf("%c",&b);
              }while((toupper(b)!='O')&&(toupper(b)!='N'));
            if (toupper(b)=='O')
            {
                tlivre[i].disponible='O';
                temprunt[j].dhr[0]=heure_r[0];
                temprunt[j].dhr[1]=heure_r[1];
                temprunt[j].dhr[2]=date_r[0];
                temprunt[j].dhr[3]=date_r[1];
                temprunt[j].dhr[4]=date_r[2];
                Fempruntretour=fopen("Fempruntretour.txt","w");
                for(k=0;k<q;k++)
                fprintf(Fempruntretour,"%d %d %d %d %d %d %d %d %d %d %d %d\n",temprunt[k].dhe[0],temprunt[k].dhe[1],temprunt[k].dhe[2],temprunt[k].dhe[3],temprunt[k].dhe[4],temprunt[k].cin_emprunt,temprunt[k].code_livre_emprunt,temprunt[k].dhr[0],temprunt[k].dhr[1],temprunt[k].dhr[2],temprunt[k].dhr[3],temprunt[k].dhr[4]);
                fclose(Fempruntretour);
                Flivre=fopen("Flivre.txt","w");
                for(k=0;k<n;k++)
                fprintf(Flivre,"%d %s %d %f %d %d %d %d %s %c\n",tlivre[k].code_livre,tlivre[k].titre_livre,tlivre[k].nbre_pages,tlivre[k].prix_achat,tlivre[k].date_achat[0],tlivre[k].date_achat[1],tlivre[k].date_achat[2],tlivre[k].code_auteur,tlivre[k].maison,tlivre[k].disponible);
                fclose(Flivre);
            }
        }
        else
        {
            do{
                interface_code_retour_livre();
                gotoxy(54,4);
                printf("%d",code_livre);
                gotoxy(47,5);
                printf("\"code Livre invalide\"");
                gotoxy(38,6);
                printf("voulez-vous retourner un livre O/N : |_|");
                gotoxy(76,6);
                fflush(stdin);
                scanf("%c",&c);
              }while((toupper(c)!='O')&&(toupper(c)!='N'));
        }
      }while (toupper(c)=='O');
}
void livre_non_rtournes(int q)
{
    int i,j=0;
    system("cls");
    gotoxy(35,0);
    printf("**********Livre Non Retournes************");
    gotoxy(35,1);
    printf("_________________________________________");
    gotoxy(35,2);
    printf("|  Date Emprunt  |   CIN   | Code Livre |");
    gotoxy(35,3);
    printf("_________________________________________");
    for(i=0;i<q;i++)
    {
        if((temprunt[i].dhr[4]==0)&&(temprunt[i].dhr[3]==0)&&(temprunt[i].dhr[2]==0))
            {
                gotoxy(35,4+j);
                printf("| %d:%d %d/%d/%d",temprunt[i].dhe[0],temprunt[i].dhe[1],temprunt[i].dhe[2],temprunt[i].dhe[3],temprunt[i].dhe[4]);
                gotoxy(52,4+j);
                printf("| %d",temprunt[i].cin_emprunt);
                gotoxy(62,4+j);
                printf("| %d",temprunt[i].code_livre_emprunt);
                gotoxy(75,4+j);
                printf("|");
                j+=1;
            }
    }
    gotoxy(35,4+j);
    printf("_________________________________________");
    getch();
}
int menu_gestion_E_R(int q,int n,int p)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*         Emprunt/Retour des livre             *");
            gotoxy(35,3);
            printf("*                                              *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*        1-Emprunt des Livres                  *");
            gotoxy(35,6);
            printf("*        2-Retour des Livres                   *");
            gotoxy(35,7);
            printf("*        3-Livres non retournes                *");
            gotoxy(35,8);
            printf("*        4-Quitter                             *");
            gotoxy(35,9);
            printf("*                                              *");
            gotoxy(35,10);
            printf("*                                   Choix : |_|*");
            gotoxy(35,11);
            printf("************************************************");
            affichage_emprunt_retour(q);
            gotoxy(80,10);
            scanf("%d",&a);
          }while((a<1)||(a>4));
        switch(a)
        {
        case 1:
            q=emprunt_livre(q,n,p);
            break;
        case 2:
            retour_livre(n,q);
            break;
        case 3:
            livre_non_rtournes(q);
            break;
        }
      }while (a!=4);
    return n;
}
void trace_histogramme(int n,int T[],int TA[])
{
    int max,min,i,j,l=0;
    max=recherche_max(T,n);
    min=recherche_min(T,n);
    system("cls");
    gotoxy(50,max+16);
    printf("%c",192);
    for(i=0;i<n*6+2;i++)
    {
        gotoxy(51+i,max+16);
        printf("%c",196);
    }
    gotoxy(52+n*6,max+16);
    printf("%c",'>');
    for(i=15;i<max+16;i++)
    {
        gotoxy(50,i);
        printf("%c",179);
    }
    gotoxy(50,max-min+15);
    printf("%c",197);
    gotoxy(47,max-min+15);
    printf("%s","min");
    gotoxy(50,15);
    printf("%c",197);
    gotoxy(47,15);
    printf("%s","max");
    gotoxy(50,14);
    printf("%c",'^');
    for(i=0;i<n*6;i+=6)
       {
            gotoxy(55+i,max+16);
            printf("%c",197);
            gotoxy(55+i,max+17);
            printf("%d",TA[l]);
            for(j=0;j<T[l];j++)
               {
                  gotoxy(54+i,max-j+15);
                  printf("%c%c%c",219,219,219);
               }
            l+=1;
       }
    getch();
}
void histogramme_livre_plus_emprunt(int n,int q)
{
    int i,j,T[100],TA[100];
    for(i=0;i<n;i++)
        TA[i]=tlivre[i].code_livre;
    for(i=0;i<n;i++)
        T[i]=0;
    for(i=0;i<n;i++)
    for(j=0;j<q;j++)
    if(temprunt[j].code_livre_emprunt==TA[i])
    T[i]+=1;
    trace_histogramme(n,T,TA);
}
void histogramme_etudiant_motive(int p,int q)
{
    int i,j,T[100],TA[100];
    for(i=0;i<p;i++)
        TA[i]=tetudiant[i].cin;
    for(i=0;i<p;i++)
        T[i]=0;
    for(i=0;i<p;i++)
    for(j=0;j<q;j++)
    if(temprunt[j].cin_emprunt==TA[i])
    T[i]+=1;
    trace_histogramme(p,T,TA);
}
void histogramme_emprunt_classe(int p,int q)
{
    int i,j,l=0,b,T[100],TI[100],TA[100];
    for(i=0;i<p;i++)
    {
        b=0;
        for(j=0;j<i;j++)
        if(tetudiant[i].code_classe==tetudiant[j].code_classe)
        b=1;
        if (b==0)
        {
            TA[l]=tetudiant[i].code_classe;
            l+=1;
        }
    }
    for(i=0;i<l;i++)
        T[i]=0;
    for(i=0;i<l;i++)
        TI[i]=0;
    for(i=0;i<p;i++)
    for(j=0;j<q;j++)
    if(temprunt[j].cin_emprunt==tetudiant[i].cin)
    TI[i]+=1;
    for(i=0;i<l;i++)
    for(j=0;j<p;j++)
    if(tetudiant[j].code_classe==TA[i])
    T[i]+=TI[j];
    trace_histogramme(l,T,TA);
    getch();
}
void menu_statistiques(int n,int m,int p,int q)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*               Statistiques                   *");
            gotoxy(35,3);
            printf("*                                              *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*1-Histogramme des livre les plus empruntes    *");
            gotoxy(35,6);
            printf("*2-Histogramme des etudiants motives           *");
            gotoxy(35,7);
            printf("*3-Histogramme des emprunts par classe         *");
            gotoxy(35,8);
            printf("*4-Quitter                                     *");
            gotoxy(35,9);
            printf("*                                   Choix : |_|*");
            gotoxy(35,10);
            printf("************************************************");
            gotoxy(80,9);
            scanf("%d",&a);
          }while((a<1)||(a>4));
        switch(a)
        {
        case 1:
            histogramme_livre_plus_emprunt(n,q);
            break;
        case 2:
            histogramme_etudiant_motive(p,q);
            break;
        case 3:
            histogramme_emprunt_classe(p,q);
            break;
        }
      }while (a!=4);
}
void menu_principal(int n,int m,int p,int q)
{
    int a;
    do{
        do{
            system("cls");
            gotoxy(35,0);
            printf("************************************************");
            gotoxy(35,1);
            printf("*                                              *");
            gotoxy(35,2);
            printf("*     Application Gestion de bibliotheque      *");
            gotoxy(35,3);
            printf("*        d'un institut universitaire           *");
            gotoxy(35,4);
            printf("*                                              *");
            gotoxy(35,5);
            printf("*                                              *");
            gotoxy(35,6);
            printf("*        1-Gestion des auteurs                 *");
            gotoxy(35,7);
            printf("*        2-Gestion des livres                  *");
            gotoxy(35,8);
            printf("*        3-Gestion des Etudiants               *");
            gotoxy(35,9);
            printf("*        4-gestion des Emprunts/Retours        *");
            gotoxy(35,10);
            printf("*        5-Statistiques                        *");
            gotoxy(35,11);
            printf("*        6-Quitter                             *");
            gotoxy(35,12);
            printf("*                                              *");
            gotoxy(35,13);
            printf("*                                   Choix : |_|*");
            gotoxy(35,14);
            printf("************************************************");
            gotoxy(80,13);
            scanf("%d",&a);
          }while((a>6)||(a<1));
        switch(a)
        {
        case 1:
            m=menu_gestion_auteur(m);
            break;
        case 2:
            n=menu_gestion_livre(n,m);
            break;
        case 3:
            p=menu_gestion_etudiants(p);
            break;
        case 4:
            q=menu_gestion_E_R(q,n,p);
            break;
        case 5:
            menu_statistiques(n,m,p,q);
        }
      }while(a!=6);
}
int main()
{
    int n=0,m=0,p=0,q=0;
    n=extract_info_Flivre();
    m=extract_info_Fauteur();
    p=extract_info_Fetudiant();
    q=extract_info_Fempruntretour();
    menu_principal(n,m,p,q);
    return 0;
}
