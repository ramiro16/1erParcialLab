#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define TAMC 10
#define TAMA 15

int main()
{
    eCliente cliente[TAMC];
    eAlquiler alquiler[TAMA];

    inicializarCliente(cliente,TAMC);
    cargaCliente(cliente,TAMC);


    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Alta\n");
        printf("2- Modificar\n");
        printf("3- Baja\n");
        printf("4- Nuevo Alquiler\n");
        printf("5- Fin de Alquiler\n");
        printf("6- Informar\n\n");

        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaCliente(cliente,TAMC);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cargaAlquiler(alquiler,TAMA);
                break;
            case 5:
                break;
            case 6:
                informarAlquileresxCliente(cliente,TAMC,alquiler,TAMA);
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

