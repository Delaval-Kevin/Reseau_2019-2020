/*Auteur : COLETTE Loic et DELAVAL Kevin                   */
/*Groupe : 2203                                            */
/*Application : Dossier Réseaux                            */
/*Step : 1                                                 */
/*Date de la dernière mise à jour : 15/11/2019             */
/***********************************************************/

void AProposCLDK(char *Version, char *Nom1, char* Nom2)
{
	printf("Version : %s \n", Version);
	printf("Nom1 : %s \n", Nom1);
	printf("Nom2 : %s \n", Nom2);
}

void DelNewLine(char *Chaine)
{
	Chaine[strlen(Chaine)-1] = 0;
}

char ReadChar()
{
	char Tampon[80];
	fgets(Tampon, sizeof Tampon, stdin);
	return Tampon[0];
} 

void MonPrintf(char* tempo, int espace, int taille)
{
	int Count;
	printf("%s", tempo);
	Count = espace - taille;
 	while (Count > 0)
 	{
       printf(" ");
       Count--;
	}
}

void AfficheEnteteVoitureCLDK()
{
	char Tampon[80];
	sprintf(Tampon, "%s", "Ref" );
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%s", "Marque");
	MonPrintf(Tampon, 30, strlen(Tampon));
	
	sprintf(Tampon, "%s", "Modele");
	MonPrintf(Tampon, 30, strlen(Tampon));
	
	sprintf(Tampon, "%s", "Nombre");
	MonPrintf(Tampon, 8, strlen(Tampon));

	sprintf(Tampon, "%s", "CO2");
	MonPrintf(Tampon, 4, strlen(Tampon));	
	
	printf("\n----------------------------------------------------------------------------");
	
	printf("\n");
}

void AfficheVoitureCLDK(struct VoitureCLDK *UnRecord)
{
	char Tampon[80];
	sprintf(Tampon, "%d", UnRecord->Reference);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%s", UnRecord->Marque);
	MonPrintf(Tampon, 30, strlen(Tampon));
	
	sprintf(Tampon, "%s", UnRecord->Modele);
	MonPrintf(Tampon, 30, strlen(Tampon));
	
	sprintf(Tampon, "%d", UnRecord->Nombre);
	MonPrintf(Tampon, 8, strlen(Tampon));
	
	sprintf(Tampon, "%d", UnRecord->CO2);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	printf("\n");
}

void SaiSieVoitureCLDK(int Reference, struct VoitureCLDK *UnRecord )
{
	char Tampon[80];

	printf("Reference :%d \n", Reference);
	UnRecord->Reference = Reference;
	printf("Saisie Marque :");
	fgets(UnRecord->Marque, sizeof UnRecord->Marque,stdin);
	printf("Saisie Modele :");
	fgets(UnRecord->Modele, sizeof UnRecord->Modele,stdin);
	printf("Saisie CO2 :");
	fgets(Tampon, sizeof Tampon,stdin);
	UnRecord->CO2 = atoi(Tampon);
	printf("Saisie Nombre :");
	fgets(Tampon, sizeof Tampon,stdin);
	UnRecord->Nombre = atoi(Tampon);
 
	DelNewLine(UnRecord->Marque);
	DelNewLine(UnRecord->Modele);
	AfficheEnteteVoitureCLDK();
	AfficheVoitureCLDK(UnRecord);
	printf("-----------------------\n");
	return;
}

int NombreVoituresCLDK(char *NomFichier)
{
	FILE *sortie;
	sortie = fopen(NomFichier,"r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
	
	fseek(sortie, 0, SEEK_END );
	return (ftell(sortie) / sizeof(struct VoitureCLDK));
}

void CreationAjoutVoitureCLDK(char *NomFichier, struct VoitureCLDK *UnRecord)
{
	FILE *sortie;
	char Redo;
	int nbr;

	sortie = fopen(NomFichier, "a"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
		fprintf(stderr, "Echec Ouverture\n");
   	exit(0);
   }
	else
		fprintf(stderr, "Ouverture reussie \n");

 
	printf("Position actuelle dans le fichier %ld\n", ftell(sortie));
	nbr = fwrite(UnRecord, sizeof(struct VoitureCLDK ), 1, sortie);
	fflush(sortie);
	fclose(sortie);
}



void AfficheFacture(struct FactureCLDK *UneFacture)
{
	char Tampon[80] ;
	sprintf(Tampon, "%d", UneFacture->NumeroFacturation);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%s", UneFacture->NomClient);
	MonPrintf(Tampon, 60, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->Places);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->Reference);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->DateFacturation);
	MonPrintf(Tampon, 8, strlen(Tampon));
 
	printf("\n");
}

void ListingVoituresCLDK(char *NomFichier)
{
	struct VoitureCLDK  UnRecord;
	FILE *sortie;
	char Tampon[80];
	int  Numero;
	int  nbr;

	sortie = fopen(NomFichier, "r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
		fprintf(stderr, "Echec Ouverture\n");
		exit(0);
   }
	else
		fprintf(stderr, "Ouverture reussie \n");

	AfficheEnteteVoitureCLDK();
	nbr = fread(&UnRecord, sizeof(UnRecord), 1, sortie);
 
	while(!feof(sortie))
	{
//  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
	AfficheVoitureCLDK(&UnRecord);
	nbr = fread(&UnRecord,sizeof(UnRecord), 1, sortie);
	}
 	fclose(sortie);
}

void ListingFacturesCLDK(char *NomFichier)
{
	struct FactureCLDK UneFacture;
	FILE *sortie;
	char Tampon[80];
	int  Numero;
	int  nbr;

	sortie = fopen(NomFichier, "r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
	{
		fprintf(stderr, "Echec Ouverture\n");
		exit(0);
	}
	else
		fprintf(stderr, "Ouverture reussie \n");

 
	nbr = fread(&UneFacture, sizeof(struct FactureCLDK), 1, sortie);
 
	while(!feof(sortie))
	{
		fprintf(stderr, "Record lu %d et Position actuelle dans le fichier %ld\n", nbr, ftell(sortie));
		AfficheFacture(&UneFacture);
		nbr = fread(&UneFacture, sizeof(struct FactureCLDK ), 1, sortie);
	}
	fclose(sortie);
}	fprintf(stderr, "Pas de fichier\n");
	   return 0;
   }
	else
		fprintf(stderr, "Ouverture reussie \n");
	
	fseek(sortie, 0, SEEK_END );
	return (ftell(sortie) / sizeof(struct VoitureCLDK));
}

void CreationAjoutVoitureCLDK(char *NomFichier, struct VoitureCLDK *UnRecord)
{
	FILE *sortie;
	char Redo;
	int nbr;

	sortie = fopen(NomFichier, "a"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
		fprintf(stderr, "Echec Ouverture\n");
   	exit(0);
   }
	else
		fprintf(stderr, "Ouverture reussie \n");

 
	printf("Position actuelle dans le fichier %ld\n", ftell(sortie));
	nbr = fwrite(UnRecord, sizeof(struct VoitureCLDK ), 1, sortie);
	fflush(sortie);
	fclose(sortie);
}



void AfficheFacture(struct FactureCLDK *UneFacture)
{
	char Tampon[80] ;
	sprintf(Tampon, "%d", UneFacture->NumeroFacturation);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%s", UneFacture->NomClient);
	MonPrintf(Tampon, 60, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->Places);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->Reference);
	MonPrintf(Tampon, 4, strlen(Tampon));
	
	sprintf(Tampon, "%d", UneFacture->DateFacturation);
	MonPrintf(Tampon, 8, strlen(Tampon));
 
	printf("\n");
}

void ListingVoituresCLDK(char *NomFichier)
{
	struct VoitureCLDK  UnRecord;
	FILE *sortie;
	char Tampon[80];
	int  Numero;
	int  nbr;

	sortie = fopen(NomFichier, "r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
   {
		fprintf(stderr, "Echec Ouverture\n");
		exit(0);
   }
	else
		fprintf(stderr, "Ouverture reussie \n");

	AfficheEnteteVoitureCLDK();
	nbr = fread(&UnRecord, sizeof(UnRecord), 1, sortie);
 
	while(!feof(sortie))
	{
//  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
	AfficheVoitureCLDK(&UnRecord);
	nbr = fread(&UnRecord,sizeof(UnRecord), 1, sortie);
	}
 	fclose(sortie);
}

void ListingFacturesCLDK(char *NomFichier)
{
	struct FactureCLDK UneFacture;
	FILE *sortie;
	char Tampon[80];
	int  Numero;
	int  nbr;

	sortie = fopen(NomFichier, "r"); /* Si le fichier existe, on le cree sinon on ajoute */
	if(sortie == NULL)
	{
		fprintf(stderr, "Echec Ouverture\n");
		exit(0);
	}
	else
		fprintf(stderr, "Ouverture reussie \n");

 
	nbr = fread(&UneFacture, sizeof(struct FactureCLDK), 1, sortie);
 
	while(!feof(sortie))
	{
		fprintf(stderr, "Record lu %d et Position actuelle dans le fichier %ld\n", nbr, ftell(sortie));
		AfficheFacture(&UneFacture);
		nbr = fread(&UneFacture, sizeof(struct FactureCLDK ), 1, sortie);
	}
	fclose(sortie);
}
