#include <stdio.h>

int main()
{
    int numeros[20];
    int i = 0, x;

    printf("Introduce numeros enteros (0 para terminar):\n");

    // Lectura de datos
    while (i < 20)
    {
        scanf("%d", &x);

        if (x == 0)
        {
            break;
        }

        numeros[i] = x;
        i++;
    }

    // Mostrar en orden inverso
    printf("\nNumeros en orden inverso:\n");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", numeros[j]);
    }

    return 0;
}
