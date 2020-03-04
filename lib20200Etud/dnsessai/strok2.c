#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

void EnleveBlanc(char *text)
// la fonction modifie la chaine d'origine 
{
  char *blank ;
  int c,d ;
  c = 0 ;
  d = 0 ;

  blank = malloc(strlen(text)+1) ;  
  while (text[c] != '\0') 
  {
      if (text[c] == ' ') 
         ;       
      else
         { 
           blank[d] = text[c] ;
           d++ ;  
         }
      c++;
   }
 
   blank[d] = '\0';
  strcpy(text,blank) ;
}


int main () 
{
  char str[] ="       zone \"world.cosmos\" in {";
  /* La chaine de depart est altérée suite à la recherche */
  char * pch;
  static  char * Tab[10] ;
  int i = 0 ;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," "); 
  while (pch != NULL) 
  { 
    printf ("%s\n",pch);
    Tab[i] = (char *) malloc ( strlen(pch) + 1 ) ;
    strcpy(Tab[i],pch) ;
    EnleveBlanc( Tab[i] ) ;
    i++ ;
    pch = strtok (NULL, " ");
  }
  i = 0 ;
  printf("-----------------------------\n") ;
  while ( Tab[i]!= NULL )
  {
   printf("%s\n",Tab[i] ) ;
   i++ ;
  }
  printf("-----------------------------\n") ;
  printf("La chaine est:%s\n",str) ;
  return 0; 
}

