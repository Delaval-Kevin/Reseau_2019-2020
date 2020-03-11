/***********************************************************/
/*Auteur : COLETTE Loic et DELAVAL Kevin                   */
/*Groupe : 2203                                            */
/*Application : Dossier Réseaux                            */
/*Step : 1                                                 */
/*Date de la dernière mise à jour : 15/11/2019             */
/***********************************************************/

#ifndef LIBERCLDK_H
#define LIBERCLDK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"

void AProposServeurCLDK(char *Version, char *Nom1, char* Nom2);

int RechercheVoitureCLDK(char* NomFichier, int Reference, struct VoitureCLDK *UnRecord);

#endif//LIBERCLDK_H
