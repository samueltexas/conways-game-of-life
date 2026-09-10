// Projekt Domowe - Data oddania: 15.01.2021 r.

  
#include <stdio.h>
#include <math.h>
#include "winbgi2.h"
#include <stdlib.h>
#include <time.h>

void main()

{
  
int T[100][50];
for(int i=0;i<100;i++){ //czyszczenie tablicy T
for(int j=0;j<50;j++) T[i][j]=0;
  
}
  
printf("Gra w zycie\n\nPlansza jest rozmiaru 100 x 50 kratek.\n ");
int f;
printf("jaka czestotliwosc krokow [Hz] (liczby calkowite): ");
scanf("%d",&f);
srand(time(NULL));
printf("losowanie polozen zywych komorek\n");
  
for(int i=10;i<90;i++)
  
{
for(int j=5;j<45;j++)
  
{
T[i][j]=rand()%2;
  
}
  
}
int licznik=0;
graphics(1000,500);
  
for(int i=0;i<=500;i=i+10) //siatka
{
  
line(i,0,i,500);
line(i+500,0,i+500,500);
line(0,i,1000,i);
  
}
for(int i=0;i<100;i++)
{
for(int j=0;j<50;j++)
{
if(T[i][j]==1)
{
floodfill(10*i+5,10*j+5,WHITE);
}
}
}
system("pause");
printf("stan populacji:\n");
// Wyswietlanie
int x=0;
int s[100][50];
while(x<1000)
{
licznik=0;
for(int i=0;i<=500;i=i+10) //siatka
{
line(i,0,i,500);
line(i+500,0,i+500,500);
line(0,i,1000,i);
}
for(int i=0;i<100;i++)
{
for(int j=0;j<50;j++)
{
if(T[i][j]==1)
{
floodfill(10*i+5,10*j+5,WHITE);
licznik++;
}
}
}
printf("%d\n",licznik);
animate(f);
for(int i=0;i<100;i++)
{ //zerowanie tablicy s
for(int j=0;j<50;j++) s[i][j]=0;
}
for(int i=0;i<100;i++)
{
for(int j=0;j<50;j++)
{
  
// Sumowanie liczby sasiadow
  
s[i][j]=s[i][j]+T[i-1][j-1];
s[i][j]=s[i][j]+T[i][j-1];
s[i][j]=s[i][j]+T[i+1][j-1];
s[i][j]=s[i][j]+T[i-1][j];
s[i][j]=s[i][j]+T[i+1][j];
s[i][j]=s[i][j]+T[i-1][j+1];
s[i][j]=s[i][j]+T[i][j+1];
s[i][j]=s[i][j]+T[i+1][j+1];
}
}
for(int i=0;i<100;i++)
{
for(int j=0;j<50;j++)
{
if(T[i][j]==0 && s[i][j]==3) T[i][j]=1;
//Przypisywanie nowych wartosci
else if(T[i][j]==1 && (s[i][j]==2 || s[i][j]==3)) T[i][j]=1;
else T[i][j]=0;
}
}
cleardevice();
x++;
}
wait();
}
