/*---------------------------------------------------------------
   Vanstapel Herman
   Ex07\cli.c

 Le client dit bonjour et
 le serveur fait de même
------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>  /* ces deux include pour le getpid */
#include <string.h>
#include <errno.h>
#include "../udplib/udplib.h"
#include "structure.h"


int NbrAlarmes=0 ;

static void signal_handler(int sig)
{
   
}

void die(char *s)
{
    perror(s);
    exit(1);
}


int main(int argc, char *argv[])
{
 int rc ;
 int Desc ;
 int tm ; 
 int Port, Ip ;
 char Tampon[80] ;
 unsigned int time_interval  ; 
 int ret ;
 int Compteur = 0 ;
 struct sigaction act;
 
 struct sockaddr_in sthis ; /* this ce programme */
 struct sockaddr_in sos ; /* s = serveur */
 struct sockaddr_in sor ; /* r = remote */
 
 u_long  IpSocket , IpServer;
 u_short PortSocket, PortServer ; 
 
 struct Requete UneRequeteE ;
 struct Requete UneRequeteR ;

  memset(&sthis,0,sizeof(struct sockaddr_in)) ;
 memset(&sos,0,sizeof(struct sockaddr_in)) ; 
 memset(&sor,0,sizeof(struct sockaddr_in)) ; 
 
 if (argc!=5)
  
{
    printf("cli client portc serveur ports\n") ;
    exit(1) ;
 }
 
 
 /* Récupération IP & port   */
 IpSocket= inet_addr(argv[1]);
 PortSocket = atoi(argv[2]);
 
 IpServer = inet_addr(argv[3]) ;
 PortServer = atoi(argv[4]);
 
 // Desc = CreateSockets(&psoo,&psos,,atoi(argv[2]),argv[3],atoi(argv[4])) ;
 Desc=creer_socket(SOCK_DGRAM,&IpSocket,PortSocket,&sthis);
 
 if ( Desc == -1 )
    die("CreateSockets:") ;
 else
    fprintf(stderr,"CreateSockets %d\n",Desc) ;
 
 sos.sin_family = AF_INET ;
  sos.sin_addr.s_addr= IpServer ;
  sos.sin_port = htons(PortServer) ;
 
 Compteur = 0 ;
 while(1)
 {
   struct sigaction act; 

  act.sa_handler = signal_handler; 
  act.sa_flags = 0 ; 
  sigemptyset (&act.sa_mask); 

  rc = sigaction (SIGALRM, &act, NULL);  

  
   UneRequeteE.Compteur = Compteur ;
   UneRequeteE.Type = Question ; 
   strncpy(UneRequeteE.Message , "Hello Multiclient" , sizeof(UneRequeteE.Message)) ;
   redo:
   time_interval = 9 ;
   ret = alarm(time_interval); 
   rc = SendDatagram(Desc,&UneRequeteE,sizeof(struct Requete) ,&sos ) ;

   if ( rc == -1 )
      die("SendDatagram") ;
   else
      fprintf(stderr,"Envoi du message %d avec %d bytes\n",UneRequeteE.Compteur, rc ) ;
 
   while(1) /* on boucle tant que l'on ne reçoit pas le bon message */
   {
     memset(&UneRequeteR,0,sizeof(struct Requete)) ;
     tm = sizeof(struct Requete) ;
     rc = ReceiveDatagram( Desc, &UneRequeteR,tm, &sor ) ;
     if ( rc<=0)
        {
         perror("error sur receive:") ;
         fprintf(stderr,"rc %d errno:%d \n",rc,errno) ;
         goto redo ;
        } 
     if ( UneRequeteR.Compteur != Compteur ) 
        printf("doublon !!!!!\n") ;
     else
        break ;
   }
   /* fin de l'alarme */ 
   ret = alarm(0);
   fprintf(stderr,"bytes:%d:Compteur %d:%s\n",rc,UneRequeteR.Compteur,UneRequeteR.Message ) ;
 
   Compteur++ ;
   sleep(5) ;
 }

 close(Desc) ;
}
