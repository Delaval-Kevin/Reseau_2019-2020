
#include<stdlib.h>
#include<stdio.h>

void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}

main()
{
system("clear"); //clears the screen
gotoxy(24,50); //reposition cursor
printf("hello world"); //display text
//gotoxy(12,50); reposition cursor
} 


