#ifndef LISTE_ELECTORALE_H_INCLUDED
#define LISTE_ELECTORALE_H_INCLUDED
#include <stdio.h>

typedef struct Date{
int jour;
int  mois;
int annee;
}Date;

typedef struct liste_electorale{
int id_liste ;
char orientation [20];
Date date_c;
int id_election;
int id_electeur1;
int id_electeur2;
int id_electeur3;
}liste_electorale ;

typedef struct vote{
int id_election;
int  id_vote;
int vote_blanc ;
int id_liste ;
Date date_v ;
}vote;


int ajouter_listeElectorale (char* filename,liste_electorale LE);
int modifier_listeElectorale(char*filename,int id_liste, liste_electorale nouv );
int supprimer_listeElectorale (char* filename,int id_liste );
liste_electorale chercher_listeElectorale(char * filename,int id_liste );
int ajouter_vote(char* filename,vote V);
int nbv (char* filename , int id_liste);
int L_ordre(char* fichierListeElectorale ,int list_t[],char* fichierusers);


#endif 
