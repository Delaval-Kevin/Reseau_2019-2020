/***********************************************************/
/*Auteur : COLETTE Loic et DELAVAL Kevin                   */
/*Groupe : 2203                                            */
/*Application : Dossier Réseaux                            */
/*Step : 1                                                 */
/*Date de la dernière mise à jour : 15/11/2019             */
/***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "LibSerCLDK.h"


int main()
{
	char Choix;
	char Tampon[80];
	int res, ref, Numero;
	struct VoitureCLDK UnRecord;

	while(1)
	{
		printf("----------------------\n");
		printf("1) Ajout              \n");
		printf("2) Voitures           \n");  
		printf("3) Recherche          \n");   
		printf("4) Achat              \n");  
		printf("5) Factures           \n");
		printf("6) A propos           \n");
		printf("7) exit               \n"); 
		printf("----------------------\n"); 
		Choix = ReadChar();
		switch(Choix)
		{
			case '1': 
         {
            char Redo;
		
            Redo = 'y';
 	    		while(Redo == 'Y' || Redo == 'y')
 	    		{ 
            	int Nombre;
             	Nombre= NombreVoituresCLDK("VoituresCLDK");
  	     			SaiSieVoitureCLDK(Nombre+1, &UnRecord );
  	     			CreationAjoutVoitureCLDK("VoituresCLDK", &UnRecord); 
  	     			printf("Encoder une autre (Y/N) ?)");
  	     			Redo = ReadChar();
 	   		}
 				break ;	
			}
			
		   case '2':
		   {
		   	ListingVoituresCLDK("VoituresCLDK");
            break;
         }
         
   		case '3':
   		{ 	
   			printf("Entrer la reference : ");
   			fgets(Tampon, sizeof Tampon,stdin);
				ref = atoi(Tampon);
   			res = RechercheVoitureCLDK("VoituresCLDK", ref, &UnRecord);
   			if(res == 1)
   			{
		  			AfficheEnteteVoitureCLDK();
					AfficheVoitureCLDK(&UnRecord); 			
   			}
				else
				{
					printf("Reference non trouvee\n");
				}
         	break;
         }
         
   		case '4':
   		{ 	
         	break;
         }
         
   		case '5':
   		{
   			ListingFacturesCLDK("FactureCLDK");
	     		break;
	     	}
	     	
   		case '6':
   		{
   			AProposCLDK("V 1","Colette Loic","Delaval Kevin");
            break;
         }
   		
   		case '7':
   		{
   			exit(0);
   		} 
		}
	}
}
