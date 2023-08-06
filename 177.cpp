#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct etudiant
{
    char nom[50];
    char prenom[50];
    char classe[50];
    int numerotel;
    int CIN;
};

struct etudiant etud;
int i;

int rech(int CiN)
{
    FILE *f;
    f = fopen("etudiant.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    while (fscanf(f, "|%s\t|%s\t|%d\t|%s\t|%d\t|\n", etud.nom, etud.prenom, &etud.CIN, etud.classe, &etud.numerotel) == 5)
    {
        if (etud.CIN == CiN)
        {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void ajetudiant()
{
    FILE *f;
    int CIN;
    f = fopen("etudiant.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter the CIN of the new student: ");
    scanf("%d", &CIN);
    fflush(stdin);

    // Check if the student already exists
    if (rech(CIN))
    {
        printf("\nThe student with this CIN already exists.\n");
        fclose(f);
        return;
    }

    etud.CIN = CIN;
    printf("Enter the name: ");
    fflush(stdin);
    gets(etud.nom);
    printf("Enter the surname: ");
    fflush(stdin);
    gets(etud.prenom);
    printf("Enter the class: ");
    fflush(stdin);
    gets(etud.classe);
    printf("Enter the phone number: ");
    scanf("%d", &etud.numerotel);

    fprintf(f, "|%s\t|%s\t|%d\t|%s\t|%d\t|\n", etud.nom, etud.prenom, etud.CIN, etud.classe, etud.numerotel);
    fclose(f);
}

void recherche()
{
    int CINre;
    char a;
    system("cls");
    printf("Enter the CIN of the student to search: ");
    scanf("%d", &CINre);
    FILE *f;
    f = fopen("etudiant.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(f, "|%s\t|%s\t|%d\t|%s\t|%d\t|\n", etud.nom, etud.prenom, &etud.CIN, etud.classe, &etud.numerotel) == 5)
    {
        if (CINre == etud.CIN)
        {
            printf(" ***** The student exists! *****\n");
            printf("NOM: %s\n", etud.nom);
            printf("PRENOM: %s\n", etud.prenom);
            printf("Classe: %s\n", etud.classe);
            printf("Phone Number: %d\n", etud.numerotel);
            system("pause");
            fclose(f);
            return;
        }
    }

    printf("The student does not exist.\n");
    printf("Do you want to add a new student? (y/n): ");
    scanf(" %c", &a);
    if (a == 'y' || a == 'Y')
    {
        ajetudiant();
    }
    else
    {
        system("pause");
        system("cls");
    }
    fclose(f);
}

// The rest of the functions (suppetudiant, afficher, reche, ajlivre, rechercheliv, afficherliv) are not defined in this code snippet.

int main()
{
    int choix;
    char rep;

    printf("\n\t\t\t\t\t-------------\n");
    printf("\t\t\t\t\t-- WELCOME --");
    printf("\n\t\t\t\t\t-------------\n\n");

    do
    {
        system("cls");
        printf("\t\t\t\t\t//////////////////\n");
        printf("\t\t\t\t\t////// MENU //////\n");
        printf("\t\t\t\t\t//////////////////\n\n");
        printf("[1] Add a student\n");
        printf("[2] Search for a student\n");
        // Add other menu options here

        do
        {
            printf("\nEnter your choice: ");
            scanf("%d", &choix);
        } while (choix < 1 || choix > 8);

        switch (choix)
        {
        case 1:
            ajetudiant();
            break;
        case 2:
            recherche();
            break;
        // Add other cases for other menu options
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &rep);
    } while (rep == 'y' || rep == 'Y');

    return 0;
}

