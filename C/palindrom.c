#include <stdio.h>
#include <stdbool.h>

bool palindrome(char tab[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        if (tab[i] == '\0')
        {
            i++;
            continue;
        }
        if (tab[j] == '\0')
        {
            j--;
            continue;
        }
        if (tab[i] != tab[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void print_palindrome(char *array, int size)
{
    FILE *f = fopen("file1.txt", "a+");
    if (f == NULL)
    {
        printf("error\n");
    }
    int i;
    printf("[");
    fprintf(f, "[");
    for (i = 0; i < size; i++)
    {
        if (array[i] == '\0')
        {
            continue;
        }
        printf("'%c'", array[i]);
        fprintf(f, "'%c'", array[i]);
        if (i < size - 1)
        {
            if (array[i] == '\0')
            {
                continue;
            }
            printf(", ");
            fprintf(f, ", ");
        }
    }
    printf("] ");
    fprintf(f, "] ");
    if (palindrome(array, size))
    {
        printf("true\n");
        fprintf(f, "true\n");
    }
    else
    {
        printf("false\n");
        fprintf(f, "false\n");
    }
    fclose(f);
}

int main()
{
    char array1[] = {'k', 'a', 'j', 'm', 'a', 'k'};
    print_palindrome(array1, sizeof(array1));

    char array2[] = {'1', '2', '3', '3', '2', '1'};
    print_palindrome(array2, sizeof(array2));

    char array3[] = {'k', '1', 'u'};
    print_palindrome(array3, sizeof(array3));

    char array4[] = {'k', '1', '1', '\0', 'k'};
    print_palindrome(array4, sizeof(array4));

    char array5[] = {'k', 'a', '\0', 'j', '\0', 'a', 'k'};
    print_palindrome(array5, sizeof(array5));

    // more test cases
    return 0;
}
