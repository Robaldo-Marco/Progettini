#include <stdio.h>
#include <stdlib.h>

// In questo esempio faremo vedere come funziona l'uso dei puntatori

int main()
{
    int a;
    printf("\nInserisci un numero intero: ");
    scanf("%d", &a);

    int *p = &a; // Questa riga si chiama dereferenziazione, e permette di accedere al valore di a tramite il puntatore p

    // Stampa del valore di a tramite a
    printf("\nIl valore di a e': %d\n", a);

    // Stampa del valore di a tramite il puntatore p
    printf("\nIl valore di a tramite il suo puntatore e': %d\n", *p);
    printf("\nIndirizzo di a: %p\n", &a);
    
    return 0;
}
