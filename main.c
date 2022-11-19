#include <stdio.h>
#include <string.h>
#include "liste_electorale.h"


int main () 
{
liste_electorale LE1={111,"gauche",12,07,2023,01,12,13,14},LE2={112,"droite",15,05,2023,02,15,16,17};

	int x=ajouter_listeElectorale("liste_electorale.txt",LE1);
if (x==1)
   printf("\n ajout de la liste electorale avec succés");
else 
    printf("\n echec ajout");

	 x=ajouter_listeElectorale("liste_electorale.txt",LE2);
if (x==1)
   printf("\n ajout de la liste electorale avec succés");
else 
    printf("\n echec ajout");

 x=modifier_listeElectorale("liste_electorale.txt",112,LE1);

if (x==1)
   printf("\nmodification de la liste electorale avec succés");
else 
    printf("\nechec modification");

 x=supprimer_listeElectorale("liste_electorale.txt",112);


if (x==1)
   printf("\nsuppression de la liste electorale avec succés");
else 
    printf("\nechec suppression");


LE1=chercher_listeElectorale("liste_electorale.txt",111);
if (LE1.id_liste==-1)
printf("introuvable");
else printf("\n liste electorale existe");

vote V1 ={01,1,-1,111,12,02,2024},V2={02,-1,0,-1,05,02,2024};

int y=ajouter_vote("vote.txt",V1);
if (y==1)
   printf("\n ajout de la vote avec succés");
else 
    printf("\n echec ajout");
 y=ajouter_vote("vote.txt",V2);
if (y==1)
   printf("\n ajout de la vote avec succés");
else 
    printf("\n echec ajout");


return 0;
}



