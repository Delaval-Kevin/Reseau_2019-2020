/***********************************************************/
/*Auteur : COLETTE Loic et DELAVAL Kevin                   */
/*Groupe : 2203                                            */
/*Application : Dossier Réseaux                            */
/*Step : 1                                                 */
/*Date de la dernière mise à jour : 15/11/2019             */
/***********************************************************/

#include "LibSerCLDK.h"

void AProposServeurCLDK(char *Version, char *Nom1, char* Nom2)
{
	printf("Version : %s \n", Version);
	printf("Nom1 : %s \n", Nom1);
	printf("Nom2 : %s \n", Nom2);
}

int RechercheVoitureCLDK(char* NomFichier, int Reference, struct VoitureCLDK *UnRecord)
{
	FILE *sortie;
	int  Numero;
	int  nbr;

	sortie = fopen(NomFichier, "r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
		fprintf(stderr, "Echec Ouverture VoituresCLDK\n");
		exit(0);
   }
	else
		fprintf(stderr, "Ouverture reussie VoituresCLDK\n");

printf("1");
	nbr = fread(UnRecord, sizeof(UnRecord), 1, sortie);
printf("2");
	while(!feof(sortie) || UnRecord->Reference != Reference)
	{
		fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;

		nbr = fread(UnRecord, sizeof(UnRecord), 1, sortie);
	}
 	fclose(sortie);
	
	if(UnRecord->Reference == Reference)
		return 1;
	else
		return 0;
}


