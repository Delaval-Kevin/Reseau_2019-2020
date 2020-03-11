#ifdef DATAH

#else


#define DATAH

struct SeanceHV { 
         int  Reference ;
	 char Film[40] ;
	 int  Places ;
         char Date[10] ;
	} ;

struct FactureHV
       {
         int NumeroFacturation ;
         char NomClient[40] ;
	 int DateFacturation ;
         int Places ;
	 int Reference ;
	} ;  	
#endif
