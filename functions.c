#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"

// Choix du mot secret dans le dictionnaire
void choixMotSecret(char *motSecret)
{
    FILE* fichier = NULL;
    int nombreMots = 0;
    int compteur = 0;
    int numMotChoisi;
    int caractereActuel;

    fichier = fopen("dictionnaire.txt", "r");

    if (fichier == NULL)
    {
        printf("Le fichier n'a pas pu etre ouvert \n");
        return 0;
    }

    else
    {
        do
        {
            caractereActuel = fgetc(fichier);
            if (caractereActuel == '\n')
            {
                nombreMots ++;
            }
        } while (caractereActuel != EOF);

        srand(time(NULL));
        numMotChoisi = rand()%(nombreMots);

        rewind(fichier);

        while (compteur != numMotChoisi)
        {
            caractereActuel = fgetc(fichier);
            if (caractereActuel == '\n')
            {
               compteur ++;
            }
        }

        fgets(motSecret, 30, fichier);
        motSecret[strlen(motSecret) - 1] = '\0';

        fclose(fichier);
    }
}


// Fonction qui lit le caractère entré par le joueur
char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n') ;

    return caractere;
}


// Fonction qui cherche si le caractère entré par le joueur est dans le mot secret
int trouverCaractere(char caractere, char motSecret[], char motSecretVisible[])
{
    int booleen = 0;

    for (int i = 0 ; i < strlen(motSecret) ; i++)
    {
        if (caractere == motSecret [i])
        {
            motSecretVisible [i] = caractere;
            booleen = 1;
        }
    }

    return booleen;
}


// Fonction qui compte le nombre de coups restants au joueur pour trouver le mot secret
int compterNombreCoupsRestants(int booleen, int nombreCoupsRestants)
{
    if (booleen == 0)
    {
        nombreCoupsRestants --;
    }

    return nombreCoupsRestants;
}


// Fonction qui vérifie si le joueur a trouvé le mot secret
int verifierGagne(char motSecret[], char motSecretVisible[])
{
    int gagne = 0;

    if (strcmp(motSecret, motSecretVisible) == 0)
    {
        gagne = 1;
        printf("Gagne ! Le mot mystere etait : %s \n", motSecret);
    }

    return gagne;
}


// Fonction qui vérifie si le joueur a perdu
int verifierPerdu(int nombreCoupsRestants, char motSecret[])
{
    int perdu = 0;

    if(nombreCoupsRestants == 0)
    {
        perdu = 1;
        printf("Perdu ! Le mot secret etait : %s \n", motSecret);
    }

    return perdu;
}





