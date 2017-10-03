#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


void cargaCliente(eCliente cliente[], int tam)
{
    system("cls");

    int i;

    char nombre[][30]={"Miguel","Luis","Carlos","Martha","Dora"};
    char apellido[][30]={"Abuelo","Lopez","Garcia","Gomez","Perez"};
    int dni[]={11111111,22222222,33333333,44444444,55555555};
    int estado[] = {1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        cliente[i].dni = dni[i];
        cliente[i].idCliente = 100 + i;
        cliente[i].estado = estado[i];
    }

    system("cls");
}

void cargaAlquiler(eAlquiler alquiler[],int tam)
{
    system("cls");

    int i;

    int cliente[]={103,104,101,102,100};
    char equipo[][30]={"Amoladora","Taladro","Amoladora","Mezcladora","Mezcladora"};
    int tiempoEstimado[5]={12,8,16,7,10};
    char operador[][30]={"Miguel","Luis","Alberto","Matias","Fabricio"};

    for(i=0;i<tam;i++)
    {
        alquiler[i].cliente = cliente[i];
        strcpy(alquiler[i].equipo,equipo[i]);
        alquiler[i].tiempoEstimado = tiempoEstimado[i];
        strcpy(alquiler[i].operador, operador[i]);
        strcpy(alquiler[i].estado,"ALQUILADO");
    }

    system("cls");

}

void informarAlquileresxCliente(eCliente cliente[], int tamC, eAlquiler alquiler[],int tamA)
{
    system("cls");

    int i;

    printf("NOMBRE\t\tAPELLIDO\t\tID Cliente\t\tALQUILER\n\n");

    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado == 1)
        {
            printf("%s\t\t%s\t\t\t%d\t\t\t%s\n",cliente[i].nombre,cliente[i].apellido,cliente[i].idCliente,alquiler[i].equipo);
        }
        else
        {
            printf("No hay clientes para mostrar!!\n\n");
        }
    }

    printf("\n"); //PRINTF PARA MANTENER ORDENADA LA LISTA


    system("pause");
    system("cls");
}



void inicializarCliente(eCliente cliente[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        cliente[i].estado = 0;
    }

}


void altaCliente(eCliente cliente[],int tam)
{
    system("cls");

    int i;
    int aux;

    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado == 0)
        {
            printf("Ingrese nombre de cliente:");
            fflush(stdin);
            gets(cliente[i].nombre);

            printf("Ingrese apellido de cliente:");
            fflush(stdin);
            gets(cliente[i].apellido);

            printf("Ingrese DNI de cliente:");
            scanf("%d",&aux);

            cliente[i].dni = aux;

            cliente[i].estado = 1;

            break;
        }
    }

    system("pause");
    system("cls");
}
