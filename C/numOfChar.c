#include <stdio.h>
#include <stdlib.h>

int ilosc = 0;
int countk(char a[30])
{
    for (int i = 0; i < sizeof(a); i++)
{
    char sign[1] = {a[i]};
   if (a[i] == 'k') //change to the letter you are looking for
{
    ilosc++;
}
}
return ilosc;
}

void main()
{
char a[30];

printf("Enter a string\n");
scanf("%[^\n]s", &a);
printf("The number of k letters in the string: %i", countk(a));
}
