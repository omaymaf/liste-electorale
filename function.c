#include "liste_electorale.h"


int ajouter_listeElectorale (char * filename,liste_electorale LE)
{

FILE * f=fopen("liste_electorale.txt","a");
if (f!=NULL)
   {   
   fprintf(f,"%i %s %i %i %i %i %i %i %i \n",LE.id_liste,LE.orientation,LE.date_c.jour,LE.date_c.mois,LE.date_c.annee,LE.id_election,LE.id_electeur1,LE.id_electeur2,LE.id_electeur3);
   fclose(f);
return 1;
   }
else return 0;
}
////////////////////////////////////////////////

int modifier_listeElectorale(char*filename,int id_liste, liste_electorale nouv )
{
int tr=0;
liste_electorale LE ;
FILE * f=fopen ("liste_electorale.txt","r");
FILE * f2=fopen("nouv.txt","w");
if (f!=NULL && f2!=NULL)
{	
   while (fscanf(f,"%i %s %i %i %i %i %i %i %i  \n",&LE.id_liste,LE.orientation,&LE.date_c.jour,&LE.date_c.mois,&LE.date_c.annee,&LE.id_election,&LE.id_electeur1,&LE.id_electeur2,&LE.id_electeur3)!=EOF);
      {
          if(LE.id_liste==id_liste)

             {
                fprintf(f2,"%d %s %d %d %d %d %d %d %d\n",nouv.id_liste,nouv.orientation,nouv.date_c.jour,nouv.date_c.mois,nouv.date_c.annee,nouv.id_election,nouv.id_electeur1,nouv.id_electeur2,nouv.id_electeur3);
                   tr=1;
             }
           else
                fprintf(f2,"%d %s %d %d %d %d %d %d %d\n",LE.id_liste,LE.orientation,LE.date_c.jour,LE.date_c.mois,LE.date_c.annee,LE.id_election,LE.id_electeur1,LE.id_electeur2,LE.id_electeur3);
       }
}

fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return tr;
}

//////////////////////////////


int supprimer_listeElectorale (char* filename,int id_liste)
{
  int tr=0;
  liste_electorale LE ;
  FILE * f=fopen ("liste_electorale.txt" ,"r");
  FILE * f2=fopen("nouv.txt","w");
  if (f!=NULL && f2!=NULL )
   {
  while (fscanf(f,"%d %s %d %d %d %d %d %d %d \n",&LE.id_liste,LE.orientation,&LE.date_c.jour,&LE.date_c.mois,&LE.date_c.annee,&LE.id_election,&LE.id_electeur1,&LE.id_electeur2,&LE.id_electeur3)!=EOF);
      { 
    if (LE.id_liste==id_liste) 
            tr=1;
           else
                fprintf(f2,"%d %s %d %d %d %d %d %d %d\n",LE.id_liste,LE.orientation,LE.date_c.jour,LE.date_c.mois,LE.date_c.annee,LE.id_election,LE.id_electeur1,LE.id_electeur2,LE.id_electeur3);
       }
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return tr;
}
////////////////////////////////

liste_electorale chercher_listeElectorale(char * filename,int id_liste)
{
liste_electorale LE ;
int tr=0;
FILE * f=fopen (filename ,"r");
 if (f!=NULL )
   {



  while ( tr==0 && fscanf(f,"%d %s %d %d %d %d %d %d %d\n",&LE.id_liste,LE.orientation,&LE.date_c.jour,&LE.date_c.mois,&LE.date_c.annee,&LE.id_election,&LE.id_electeur1,&LE.id_electeur2,&LE.id_electeur3)!=EOF);
      { 
    if (LE.id_liste==id_liste) 

            tr=1;
       }
}

fclose(f);
if (tr==0)
   LE.id_liste=-1;
return LE;
}
///////////////////////////


int ajouter_vote (char * filename,vote V)
{

FILE * f=fopen("vote.txt","a");
if (f!=NULL)
   {   
   fprintf(f,"%d %d %d %d %d %d %d\n",V.id_election,V.id_vote,V.vote_blanc,V.id_liste,V.date_v.jour,V.date_v.mois,V.date_v.annee);
   fclose(f);
return 1;
   }
else return 0;
}
/////////////////////////////

int nbv (char* filename , int id_liste){
int nb_votes=0;
vote V;
FILE* f=fopen("vote.txt","r");
if (f!=NULL)
	{
	while (fscanf(f,"%d %d %d %d %d %d %d\n ",&V.id_election,&V.id_vote,&V.id_liste,&V.vote_blanc,&V.date_v.jour,&V.date_v.mois,&V.date_v.annee)!=EOF);
	  {
	if( (V.id_liste==id_liste) && (V.id_vote==1) ) {
	
	nb_votes=nb_votes+1;
	  }
	}
	}
fclose(f);
return nb_votes;
}
//////////////////////


int L_ordre(char* fichierListeElectorale, int t[],char* fichierusers){
int n=0,i=0,j=0,tmp,max;
int nv=0,nl=0;
vote V;
FILE* f=fopen("vote.txt","r");
FILE* f2=fopen("nouv.txt","w");
if (f!=NULL && f2!=NULL)
{
while (fscanf(f,"%d %d %d %d %d %d %d\n ",&V.id_election,&V.id_vote,&V.vote_blanc,&V.id_liste,&V.date_v.jour,&V.date_v.mois,&V.date_v.annee)!=EOF);
if(V.id_vote==1)
{t[i]=id_liste;i++;n++;}
for (i=0;i<n-1;i++)
{
  for(j=i+1;j<n;j++)
   {
     if(t[i]==t[j])
        {nv=nv+1;
         }
         i++;
         nl=nl+1;
    }
}
 
for (i=0;i<nl-1;i++)
{
max=i;
  for(j=i+1;j<nl;j++)
{
if(t[j]>t[max])
max=j;
}
tmp=t[i];
t[i]=t[max];
t[max]=tmp;
}
for(i=0;i<n;i++)
{
 nv=t[id_liste];
 fprintf(f2,"%i %i %i %i %i %i %i \n",&V.id_election,&V.id_vote,&V.vote_blanc,&V.id_liste,&V.date_v.jour,&V.date_v.mois,&V.date_v.annee)!=EOF);
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);

return nl;
}




