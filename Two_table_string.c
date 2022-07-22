#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define Taille 10
#define NB_ALEA_MAX 15
#define TAILLE_LETTRE 100
void initialTableau(int tableau[],int nbElements);
void afficherTableau(int tableau[], int nbElements);
int chercherElementCommuns(int T1[], int T2[], int Communs[],int tailleTable);
int ElementsDifferent(int T1[], int T2[], int T3[], int taille);
int CompterNombreConsonnes(char chaine[]);
int CompterNombreVoyelles(char chaine[]);
int strlen(char *);
int main(){
    int T1[Taille] ;
    int T2[Taille] ;
    int Communs[Taille];
    int Different[Taille];
    srand(time(NULL));
    initialTableau(T1,Taille);
    initialTableau(T2,Taille);
    printf("Tableau 1 : \n" );
    afficherTableau(T1,Taille);
    printf("Tableau 2: \n");
    afficherTableau(T2,Taille);
    int nb = chercherElementCommuns( T1, T2,Communs, Taille);
    if(nb > 0){
        printf("Elements communs :");
        afficherTableau(Communs,nb);
    }else {
        printf("Aucun element communs \n");

    }
    int nbDiff = ElementsDifferent(T1,T2,Different,Taille);
    if(nbDiff > 0){
        printf("Le nombre different :");
        afficherTableau(Different,nbDiff);
    }else{
        printf("Aucun element different \n");
    }
    char chaine[TAILLE_LETTRE];
    printf("Entrez une phrase :");
    fgets(chaine,sizeof(chaine),stdin);
    puts(chaine);
    int nbv = CompterNombreVoyelles (chaine);
    int nbc = CompterNombreConsonnes(chaine);
    if(nbv > 0){
        printf("Le nombre  de voyelles  %d\n", nbv);
    }
    if(nbc > 0){
        printf("Le nombre  de consonnes %d\n", nbc);

    }
    return 0;
}
void initialTableau(int tableau[],int nbElements){
    int nbAlea;
    for(int i=0;i<nbElements;i++){
        nbAlea = rand() % NB_ALEA_MAX;
        tableau[i] = nbAlea;
    }
}

void afficherTableau(int tableau[], int nbElements){
    printf("[");
    for(int i=0;i<nbElements;i++){
        printf("%d",tableau[i]);
        if(i != nbElements-1){
            printf(", ");
        }
    }
    printf("]\n");
}
int chercherElementCommuns(int T1[], int T2[], int Communs[],int tailleTable){
    int nbElements =0;
    for(int i=0;i< Taille;i++){
        for(int j=0;j<Taille; j++){
            if(T1[i]== T2[j]){
                int estLas = 1;
                for(int k=0;k<nbElements;k++){
                    if(Communs[k] == T1[i])
                    {
                        estLas = 0;
                        break;
                    }
                }
                if(estLas)
                {
                    Communs[nbElements] = T1[i];
                    nbElements++;
                }
            }
        }
    }
    return nbElements;
}

int is_in(int *tab, int val, int taille)
{
    for(int i=0; i < taille; i++)
    {
        if(tab[i] == val)
            return 1;
    }
    return 0;
}


int ElementsDifferent(int T1[], int T2[], int T3[], int taille){
    int nbElements =0;
    int i;
    for(i=0;i< taille;i++){
        if(is_in(T2, T1[i], taille)  )
        {
            continue;
        }
        if(!is_in(T3, T1[i], nbElements)){
             T3[nbElements] = T1[i];
             nbElements++;
        }
    }
    for(i=0;i< taille;i++){
        if(is_in(T1, T2[i], taille))
        {
            continue;
        }
        if(!is_in(T3, T2[i], nbElements) ){
            T3[nbElements] = T2[i];
            nbElements++;
        }
    }
    return nbElements;
}
int CompterNombreVoyelles(char chaine[]){
    char voyelles[] = {'a','e','i','o','y'};
    int taille = strlen(chaine);
    int nbVoyelles =0;
    for(int i=0;i<taille;i++){
        for(int j=0; j < strlen(chaine); j++) {
                if(tolower(chaine[i]) == voyelles[j]){
                  nbVoyelles ++;
                }
            }
        }
    return nbVoyelles;
}
int CompterNombreConsonnes(char chaine[]){
    char consonnes[] = {'b','c','d','f','g,','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    int taille = strlen(chaine);
    int nbConsonnes = 0;
    for(int i=0;i<taille;i++){
        for(int j=0;j<strlen(chaine);j++){
            if(tolower(chaine[i]) == consonnes[j]){
                nbConsonnes++;
            }
        }
    }
    return nbConsonnes;
}

