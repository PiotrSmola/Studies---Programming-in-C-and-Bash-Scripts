#include <stdio.h>
#include <stdlib.h>

int ilosc = 0;
int countk(char a[30])
{
    for (int i = 0; i < sizeof(a); i++)
{
    char sign[1] = {a[i]};
   if (a[i] == 'k')
{
    ilosc++;
}
}
return ilosc;
}

void main()
{
char a[30];

printf("Podaj ciąg znaków\n");
scanf("%[^\n]s", &a);
printf("Ilość liter k w łańcuchu: %i", countk(a));
}
