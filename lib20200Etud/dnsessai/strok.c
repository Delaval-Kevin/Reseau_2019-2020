#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
int main () 
{
  char str[] ="111.112.113.114";
  /* La chaine de depart est altérée suite à la recherche */
  char * pch;
  static  char * Tab[10] ;
  int i = 0 ;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,"."); 
  while (pch != NULL) 
  { 
    printf ("%s\n",pch);
    Tab[i] = (char *) malloc ( strlen(pch) + 1 ) ;
    strcpy(Tab[i],pch) ;
    i++ ;
    pch = strtok (NULL, ".");
  }
  i = 0 ;
  printf("-----------------------------\n") ;
  while ( Tab[i]!= NULL )
  {
   printf(" %s \n",Tab[i] ) ;
   i++ ;
  }
  printf("La chaine est:%s\n",str) ;
  return 0; 
}

