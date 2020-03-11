/***********************************************************/
/*Auteur : COLETTE Loic et DELAVAL Kevin                   */
/*Groupe : 2203                                            */
/*Application : Dossier Réseaux                            */
/*Step : 1                                                 */
/*Date de la dernière mise à jour : 15/11/2019             */
/***********************************************************/

#ifndef DATA_H
#define DATA_H


struct VoitureCLDK
{ 
	int	Reference;
	char	Marque[40];
	char	Modele[40];
	int	CO2;
	int	Nombre;
};

struct FactureCLDK
{
	int	NumeroFacturation;
	char	NomClient[40];
	int	DateFacturation;
	int	Places;
	int	Reference;
};  	
#endif //DATA_H
