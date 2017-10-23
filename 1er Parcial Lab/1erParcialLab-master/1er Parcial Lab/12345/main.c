#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMC 5
#define TAMA 10

#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

typedef struct
{
    int idCliente;
    int dni;
    char nombre[20];
    char apellido[20];

    int estado;

}eCliente;

typedef struct
{
    int idCliente;
    char equipo[20];
    int estado;
    char operador[20];
    int tiempoEstimado;
    int tiempoReal;

}eAlquiler;

void inicializarTodo(eCliente[], eAlquiler[],int,int);
void altaCliente(eCliente[], int);
void nuevoAlquiler(eAlquiler[],int);
void informarAlquilerxCliente(eAlquiler[],int, eCliente[],int);

int buscarCliente(eCliente[],int, int);

int main()
{
    eCliente cliente[TAMC];
    eAlquiler alquiler[TAMA];

    char seguir='s';
    int opcion=0;

    inicializarCliente(cliente,TAMC); // VACIA TODO LOGICAMENTE

    while(seguir=='s')
    {
        printf("1- Alta Cliente\n");
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
                system("cls");
                altaCliente(cliente, TAMC);
                system("pause");
                system("cls");
                break;

            case 2:
                break;
            case 3:
                break;

            case 4:
                system("cls");
                nuevoAlquiler(alquiler,TAMA);
                system("pause");
                system("cls");
                break;

            case 5:
                break;
            case 6:
                system("cls");
                informarAlquilerxCliente(alquiler,TAMA,cliente,TAMC);
                system("pause");
                system("cls");
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


void altaCliente(eCliente cliente[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado == 0)
        {
            printf("Ingrese nombre de cliente: ");
            fflush(stdin);
            gets(cliente[i].nombre);

            printf("Ingrese apellido de cliente: ");
            fflush(stdin);
            gets(cliente[i].apellido);

            printf("Ingrese DNI de cliente: ");
            scanf("%d",cliente[i].dni);

            cliente[i].idCliente = 100+i;

            printf("ID otorgado: %d\n",cliente[i].idCliente);

            cliente[i].estado = 1;
            break;
        }

    }
}

void nuevoAlquiler(eAlquiler alquiler[],int tam)
{
    int i,aux, posicion;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese ID de Cliente: ");
        scanf("%d",&aux);

        posicion = buscarCliente(cliente, aux, TAMC)

        if(posicion != -1)
        {

        }

        alquiler[i].idCliente = aux;

        printf("\nEquipo a alquilar\n\n1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO");
        scanf("%d",alquiler[i].equipo);

        printf("\n\nTiempo estimado de alquiler(en Hrs):");
        scanf("%d",alquiler[i].tiempoEstimado);

        printf("\nAtendido por el operador:");
        fflush(stdin);
        gets(alquiler[i].operador);

        strcpy(alquiler[i].estado,"ALQUILADO");

        break;

    }
}

void inicializarTodo(eCliente cliente[], eAlquiler alquiler[], int tamC, int tamA)
{
    int i;

    for(i=0;i<tamC;i++)
    {
        cliente[i].estado = 0;
    }

    for(i=0;i<tamA;i++)
    {
        alquiler[i].estado = 0;
    }

}

void informarAlquilerxCliente(eAlquiler alquiler[],int tamA, eCliente cliente[],int tamC)
{
    int i, j;

    for(i=0;i<tamC;i++)
    {
        if(cliente[i].estado == 0)
        {
            printf("Nombre y Apellido: %s\n",cliente[i].nombre,cliente[i].apellido);

                for(j=0;j<tamA;j++)
                {
                    if(cliente[i].idCliente == alquiler[j].idCliente)
                    {
                        printf("Equipo/s alquilado/s: %s\n",alquiler[j].equipo);
                    }
                }
        }
    }
}


int buscarCliente(eCliente cliente[],int id, int tam)
{
    int i;

    int posicion = -1;

    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado == 1 && cliente[i].idCliente == id)
        {
            poisicion = i;
            break;
        }
    }

    return posicion;
}
