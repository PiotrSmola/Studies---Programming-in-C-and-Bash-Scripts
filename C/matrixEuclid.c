#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** allocate_2d_array(int rows, int cols);
void free_2d_array(int rows, float** array);
void print_matrix(int rows, int cols, float** array);
float euclidDistance(float* tab1, float* tab2, int n);
float** distanceMatrix(int rows, int cols, float** array);

int main()
{
    int rows = 0;
    int cols = 0;
    int option = 0;
    float** array = NULL;

    do
    {
        printf("1. Wprowadz macierz\n");
        printf("2. Wyswietl macierz\n");
        printf("3. Macierz odleglosci\n");
        printf("4. Wyjscie\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Wprowadz liczbe wierszy: ");
                scanf("%d", &rows);
                printf("Wprowadz liczbe kolumn: ");
                scanf("%d", &cols);

                array = allocate_2d_array(rows, cols);

                for(int i = 0; i < rows; i++)
                {
                    for(int j = 0; j < cols; j++)
                    {
                        printf("tab[%d][%d] = ", i+1, j+1);
                        scanf("%f", &array[i][j]);
                    }
                }
                break;
            case 2:
                print_matrix(rows, cols, array);
                break;
            case 3:
                print_matrix(rows, rows, distanceMatrix(rows, cols, array));
                break;
            case 4:
                break;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    }
    while(option != 4);

    free_2d_array(rows, array);

    return 0;
}

float** allocate_2d_array(int rows, int cols)
{
    float** array = (float**)malloc(rows * sizeof(float*));
    for(int i = 0; i < rows; i++)
    {
        array[i] = (float*)malloc(cols * sizeof(float));
    }

    return array;
}

void free_2d_array(int rows, float** array)
{
    for(int i = 0; i < rows; i++)
    {
        free(array[i]);
    }
    free(array);
}

void print_matrix(int rows, int cols, float** array)
{
    for(int i = 0; i < rows; i++)
    {
        printf("|");
        for(int j = 0; j < cols; j++)
        {
            printf(" %.2f\t", array[i][j]);
        }
        printf("|\n");
    }
}

float euclidDistance(float* tab1, float* tab2, int n)
{
    float result = 0;

    for(int i = 0; i < n; i++)
    {
        result += pow(tab2[i] - tab1[i], 2);
    }

    return sqrt(result);
}

float** distanceMatrix(int rows, int cols, float** array)
{
    float** result = allocate_2d_array(rows, rows);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            result[i][j] = euclidDistance(array[i], array[j], cols);
        }
    }

    return result;
}