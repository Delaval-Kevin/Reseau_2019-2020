# COLETTE Loic et DELAVAL Kevin

.SILENT:

LIBS = -lsocket -lnsl -Wall

all:	admin	LibSerCLDK.o


LibSerCLDK.o:	LibSerCLDK.c LibSerCLDK.h data.h
	echo "compilation de LibSerCLDK"
	gcc -c  LibSerCLDK.c $(LIBS)

admin: data.h admin.c LibSerCLDK.o
	echo "Compilation de admin"
	gcc -o admin admin.c LibSerCLDK.o $(LIBS)

