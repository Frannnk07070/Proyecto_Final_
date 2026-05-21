//############## examen.c ##############
#include <stdio.h>

#define MAX_OYENTES 100
#define CANCIONES 10

// Prototipos de funciones
void inciso1_leerVotos(int votos[][3], int *total_oyentes);

void inciso2_calcularCanciones(int votos[][3],
                               int total_oyentes,
                               int puntos_canciones[],
                               int *primera,
                               int *segunda);

void inciso3_calcularOyentes(int votos[][3],
                             int total_oyentes,
                             int primera,
                             int segunda);

int main()
{
    // Variables principales
    int votos[MAX_OYENTES][3];
    int total_oyentes = 0;

    int puntos_canciones[CANCIONES];

    int primera = -1;
    int segunda = -1;

    // Inciso 1
    printf("=====================================\n");
    printf("            INCISO 1\n");
    printf("=====================================\n");

    inciso1_leerVotos(votos, &total_oyentes);

    // Inciso 2
    printf("\n=====================================\n");
    printf("            INCISO 2\n");
    printf("=====================================\n");

    inciso2_calcularCanciones(votos,
                              total_oyentes,
                              puntos_canciones,
                              &primera,
                              &segunda);

    // Inciso 3
    printf("\n=====================================\n");
    printf("            INCISO 3\n");
    printf("=====================================\n");

    inciso3_calcularOyentes(votos,
                            total_oyentes,
                            primera,
                            segunda);

    return 0;
}

//---------------------------------------------------
// INCISO 1
// LEER Y ALMACENAR LOS VOTOS
//---------------------------------------------------
void inciso1_leerVotos(int votos[][3], int *total_oyentes)
{
    int c1, c2, c3;

    *total_oyentes = 0;

    printf("INSTRUCCIONES:\n");
    printf("- Existen 10 canciones numeradas del 0 al 9.\n");
    printf("- Debes ingresar 3 canciones por oyente.\n");
    printf("- El ORDEN importa:\n");
    printf("  Primer numero  -> 3 puntos\n");
    printf("  Segundo numero -> 2 puntos\n");
    printf("  Tercer numero  -> 1 punto\n");
    printf("- Para terminar escribe -1 en el primer numero.\n\n");

    while(*total_oyentes < MAX_OYENTES)
    {
        printf("Oyente %d\n", *total_oyentes);

        // Leer primera canción
        printf("Cancion favorita (3 puntos): ");
        scanf("%d", &c1);

        // Condición de salida
        if(c1 == -1)
        {
            break;
        }

        // Leer segunda canción
        printf("Segunda favorita (2 puntos): ");
        scanf("%d", &c2);

        // Leer tercera canción
        printf("Tercera favorita (1 punto): ");
        scanf("%d", &c3);

        // Validar rango
        if(c1 < 0 || c1 > 9 ||
           c2 < 0 || c2 > 9 ||
           c3 < 0 || c3 > 9)
        {
            printf("\nERROR: Las canciones deben estar entre 0 y 9.\n");
            printf("Intenta nuevamente.\n\n");

            continue;
        }

        // Guardar votos
        votos[*total_oyentes][0] = c1;
        votos[*total_oyentes][1] = c2;
        votos[*total_oyentes][2] = c3;

        printf("Voto guardado correctamente.\n\n");

        (*total_oyentes)++;
    }
}

//---------------------------------------------------
// INCISO 2
// CALCULAR VOTOS POR CANCIÓN
//---------------------------------------------------
void inciso2_calcularCanciones(int votos[][3],
                               int total_oyentes,
                               int puntos_canciones[],
                               int *primera,
                               int *segunda)
{
    int i;

    // Inicializar puntos
    for(i = 0; i < CANCIONES; i++)
    {
        puntos_canciones[i] = 0;
    }

    // Sumar puntos
    for(i = 0; i < total_oyentes; i++)
    {
        // Primera canción = 3 puntos
        puntos_canciones[votos[i][0]] += 3;

        // Segunda canción = 2 puntos
        puntos_canciones[votos[i][1]] += 2;

        // Tercera canción = 1 punto
        puntos_canciones[votos[i][2]] += 1;
    }

    // Mostrar resultados
    printf("\nRESULTADOS DE LAS CANCIONES:\n\n");

    for(i = 0; i < CANCIONES; i++)
    {
        printf("Cancion %d: %d votos\n",
               i,
               puntos_canciones[i]);
    }

    // Buscar canción más votada
    *primera = 0;

    for(i = 1; i < CANCIONES; i++)
    {
        if(puntos_canciones[i] >
           puntos_canciones[*primera])
        {
            *primera = i;
        }
    }

    // Buscar segunda más votada
    *segunda = -1;

    for(i = 0; i < CANCIONES; i++)
    {
        if(i != *primera)
        {
            if(*segunda == -1 ||
               puntos_canciones[i] >
               puntos_canciones[*segunda])
            {
                *segunda = i;
            }
        }
    }

    printf("\n1a cancion mas votada: %d\n", *primera);
    printf("2a cancion mas votada: %d\n", *segunda);
}

//---------------------------------------------------
// INCISO 3
// CALCULAR PUNTOS DE LOS OYENTES
//---------------------------------------------------
void inciso3_calcularOyentes(int votos[][3],
                             int total_oyentes,
                             int primera,
                             int segunda)
{
    int puntos_oyentes[MAX_OYENTES] = {0};

    int i, j;

    int max_puntos = -1;

    // Calcular puntos
    for(i = 0; i < total_oyentes; i++)
    {
        int tiene_primera = 0;
        int tiene_segunda = 0;

        // Revisar las 3 canciones
        for(j = 0; j < 3; j++)
        {
            if(votos[i][j] == primera)
            {
                tiene_primera = 1;
            }

            if(votos[i][j] == segunda)
            {
                tiene_segunda = 1;
            }
        }

        // 30 puntos si tiene la canción no.1
        if(tiene_primera)
        {
            puntos_oyentes[i] += 30;
        }

        // 20 puntos si tiene la canción no.2
        if(tiene_segunda)
        {
            puntos_oyentes[i] += 20;
        }

        // 10 extra si tiene ambas
        if(tiene_primera && tiene_segunda)
        {
            puntos_oyentes[i] += 10;
        }

        // Mostrar puntos
        printf("Oyente %d: %d puntos\n",
               i,
               puntos_oyentes[i]);

        // Buscar puntaje mayor
        if(puntos_oyentes[i] > max_puntos)
        {
            max_puntos = puntos_oyentes[i];
        }
    }

    // Contar ganadores
    int cantidad_ganadores = 0;

    for(i = 0; i < total_oyentes; i++)
    {
        if(puntos_oyentes[i] == max_puntos)
        {
            cantidad_ganadores++;
        }
    }

    // Mostrar ganador(es)
    printf("\n");

    if(cantidad_ganadores == 1)
    {
        for(i = 0; i < total_oyentes; i++)
        {
            if(puntos_oyentes[i] == max_puntos)
            {
                printf("Ganador: el oyente numero %d "
                       "con %d puntos\n",
                       i,
                       max_puntos);
            }
        }
    }
    else
    {
        printf("Ganadores con %d puntos: ",
               max_puntos);

        for(i = 0; i < total_oyentes; i++)
        {
            if(puntos_oyentes[i] == max_puntos)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }
}
