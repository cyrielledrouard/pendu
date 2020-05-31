#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    char caractere;
    int nombreCoupsRestants = 10;
    int booleen;
    int gagne;
    int perdu;
    int tailleMotSecret;
    char motSecret[30] = {0};
    char *motSecretVisible = NULL;

    choixMotSecret(motSecret);

    tailleMotSecret = strlen(motSecret);

    motSecretVisible = malloc((tailleMotSecret + 1) * sizeof(char));
    if (motSecretVisible == NULL)
        exit(0);

    for (int i = 0 ; i < tailleMotSecret ; i++)
    {
        motSecretVisible[i] = '*';
    }
    motSecretVisible[tailleMotSecret] = '\0';

    printf("Bienvenue dans le Pendu ! \n\n");

    do {
        printf("Il vous reste %d coups a jouer \n", nombreCoupsRestants);
        printf("Quel est le mot secret ? %s \n", motSecretVisible);
        printf("Proposez une lettre : ");
        caractere = lireCaractere();
        printf("\n");

        booleen = trouverCaractere(caractere, motSecret, motSecretVisible);
        nombreCoupsRestants = compterNombreCoupsRestants(booleen, nombreCoupsRestants);

        gagne = verifierGagne(motSecret, motSecretVisible);
        if (gagne == 0)
        {
           perdu = verifierPerdu(nombreCoupsRestants, motSecret);
        }

    } while (perdu == 0 && gagne == 0);

    free(motSecretVisible);

    return 0;
}
