#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// In questo codice si generano numeri casuali e si stampano a video e si inseriscono dentro un array.
void randomnumber(int SIZE, int RANGE, int A[]);

int main()
{
    int length, range;
    do
    {
        printf("\nInserire la dimensione dell'array: ");
        scanf("%d", &length);
        if (length <= 0)
        {
            printf("\nDimensione non valida");
        }

    } while (length <= 0);

    int A[length];

    do
    {
        printf("\nScegliere il range della generazione casuale: ");
        scanf("%d", &range);
        if (range <= 0)
        {
            printf("\nDimensione non valida!");
        }

    } while (range <= 0);
    randomnumber(length, range, A);

    return 0;
}

void randomnumber(int SIZE, int RANGE, int A[])
{
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        A[i] = rand() % RANGE;
        printf(" %d", A[i]);
    }
}
