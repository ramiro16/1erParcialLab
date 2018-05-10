#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TamU 6
#define TamA 13

#define OCUPADO 1
#define LIBRE 0

#define ALPHA_ROMEO 5
#define FERRARI 6
#define AUDI 7
#define OTRO 8


typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char tarjeta[20];
    char direccion[20];

    int estado;

}eUsuario;

typedef struct
{
    char patente[30];
    int marca;
    int idAuto;
    int id;

    int estado;

}eAuto;

void mostrarUsuarios(eUsuario[],int);
void mostrarAutos(eAuto[],int);

void hardcodearUsuarios(eUsuario[],int);
void hardcodearAutos(eAuto[],int);

int inicializarUsuarios(eUsuario[],int);
void inicializarAutos(eAuto[],int);

int eUsuario_alta(eUsuario[],int);
int eUsuario_modificacion(eUsuario[],int);
int eUsuario_baja(eUsuario[],int);

int eAuto_alta(eAuto[],int,eUsuario[],int);

int eUsuario_buscarLugarLibre(eUsuario[],int);
int eUsuario_siguienteId(eUsuario[],int);

int eAuto_buscarLugarLibre(eAuto[],int);
int eAuto_siguienteId(eAuto[],int);



int finalizarAuto(eUsuario[],int,eAuto[],int);

int main()
{
    eUsuario usuario[TamU];
    eAuto automovil[TamA];

    char seguir='s';
    int opcion=0;
    int aux;

    inicializarUsuarios(usuario,TamU);
    inicializarAutos(automovil,TamA);

    while(seguir=='s')
    {
        printf("1- Alta de usuario\n");
        printf("2- Modificar datos de usuario\n");
        printf("3- Baja de usuario\n");
        printf("4- Ingreso de automovil\n");
        printf("5- Egreso de automovil\n\n");


        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                hardcodearUsuarios(usuario,4);
                aux = eUsuario_alta(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                eUsuario_modificacion(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                eUsuario_baja(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                hardcodearAutos(automovil,10);
                eAuto_alta(automovil,TamA,usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                finalizarAuto(usuario,TamU,automovil,TamA);
                system("pause");
                system("cls");
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void hardcodearUsuarios(eUsuario usuario[], int tam)
{
    int i;

    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char apellido[][20]= {"Perez","Diaz","Franco","Aguirre"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    for(i=0;i<tam;i++)
    {
        strcpy(usuario[i].nombre,nombre[i]);
        strcpy(usuario[i].tarjeta,tarjeta[i]);
        strcpy(usuario[i].direccion,direccion[i]);
        strcpy(usuario[i].apellido,apellido[i]);
        usuario[i].id=id[i];

        usuario[i].estado = OCUPADO;
    }
}

////////////////////////////////////////////

int eUsuario_alta(eUsuario listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;


    indice = eUsuario_buscarLugarLibre(listado,limite);

        if(indice >= 0)
        {
            retorno = 0;
            id = eUsuario_siguienteId(listado,limite);

            printf("Ingrese nombre:");
            fflush(stdin);
            gets(listado[indice].nombre);

            printf("Ingrese tarjeta de credito (Ej. XXX-XXX):");
            fflush(stdin);
            gets(listado[indice].tarjeta);

            printf("Ingrese direccion/calle de domicilio:");
            fflush(stdin);
            gets(listado[indice].direccion);

            listado[indice].id = id;
            listado[indice].estado = OCUPADO;
        }

    return retorno;
}

////////////////////////

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////


int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }
            }
        }
    }

    return retorno+1;
}

///////////////////////////////////////

int inicializarUsuarios(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;

    for(i=0; i<limite; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].id= 0;
        retorno = 0;
    }
    return retorno;
}

int eUsuario_modificacion(eUsuario listado[] ,int limite)
{
    int retorno = -1;
    int aux;
    int i;

    char auxRta;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //Devuelve -2 si lograr pedir un ID a modificar pero no puede modificar nada

        //mostrarUsuarios(listado, limite);

        mostrarUsuarios(listado,limite);

        printf("\nIngrese su ID para poder realizar modificaciones:");
        scanf("%d",&aux);

        for(i=0;i<limite;i++)
        {
            if(listado[i].id == aux)
            {
               printf("Seguro desea modificar datos de la tarj. de credito? S/N");
               fflush(stdin);
               auxRta = getch();

               if(auxRta == 's' || auxRta == 'S')
               {
                   printf("\n\nIngrese nuevo numero de tarj. de credito(Ej. XXX-XXX):");
                   fflush(stdin);
                   gets(listado[i].tarjeta);

                   printf("Cambio realizado con exito!!");
                   break;
               }
            }
        }
    }

    return retorno;
}

int eUsuario_baja(eUsuario listado[],int limite)
{
    int aux;
    int i;
    int retorno = -1;
    int flag = -1;

    mostrarUsuarios(listado,limite);

    printf("\nIngrese su ID para realizar la baja:");
    scanf("%d",&aux);

    for(i=0;i<limite;i++)
    {
        if(listado[i].id == aux)
        {
            listado[i].estado = LIBRE;
            retorno = 0;
            flag = 0;
            printf("Baja realizada con exito!\n\n");
            break;
        }
    }

    if(flag != 0)
    {
        printf("No se ha podido realizar la baja!");
    }

    return retorno;
}

void mostrarUsuarios(eUsuario listado[],int limite)
{
    int i;

    printf("ID USUARIO\tNOMBRE\t\tDIRECCION\t\tNro. TARJETA\n\n");

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("%d%21s%16s%24s\n",listado[i].id,listado[i].nombre,listado[i].direccion,listado[i].tarjeta);
        }
    }
}


void inicializarAutos(eAuto listado[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].idAuto = 0;
    }

}

void hardcodearAutos(eAuto listado[], int limite)
{
    int i;

    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    for(i=0;i<limite;i++)
    {
        listado[i].idAuto = id[i];
        listado[i].id = propietario[i];
        strcpy(listado[i].patente,patente[i]);
        listado[i].marca = marca[i];

        listado[i].estado = OCUPADO;
    }
}

int eAuto_alta(eAuto listadoA[],int limiteA,eUsuario listadoU[],int limiteU)
{
    int retorno = -1;
    int i;

    int id;
    int indice;
    int aux;

    mostrarUsuarios(listadoU,limiteU);

    printf("\nIngrese ID del usuario que realizara ingreso de auto:");
    scanf("%d",&aux);

    system("cls");

    for(i=0;i<limiteU;i++)
    {
        if(listadoU[i].id == aux)
        {
            indice = eAuto_buscarLugarLibre(listadoA,limiteA);

            if(indice >= 0)
            {
                retorno = 0;
                id = eAuto_siguienteId(listadoA,limiteA);

                printf("Ingrese patente:");
                fflush(stdin);
                gets(listadoA[indice].patente);

                printf("Ingrese marca del automovil\n\n1-Alpha Romeo\n2-Ferrari\n3-Audi\n4-Otro\n\n");
                scanf("%d",&listadoA[indice].marca);

                listadoA[indice].idAuto = id;
                listadoA[indice].estado = OCUPADO;

                printf("Alta de automovil realizada!\n\n");
            }
        }
    }

    return retorno;

}

int eAuto_buscarLugarLibre(eAuto listado[],int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int eAuto_siguienteId(eAuto listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idAuto>retorno)
                    {
                         retorno=listado[i].idAuto;
                    }
            }
        }
    }

    return retorno+1;
}



int finalizarAuto(eUsuario listadoU[],int limiteU,eAuto listadoA[],int limiteA)
{
    int i;
    int aux;

    mostrarAutos(listadoA,limiteA);

    printf("Ingrese ID de auto que desea dar de baja:");
    scanf("%d",&aux);

    for(i=0;i<limiteA;i++)
    {
        if(listadoA[i].idAuto == aux)
        {

        }

    }

}



void mostrarAutos(eAuto listado[], int limite)
{
    int i;

    printf("ID AUTO\t\tNOMBRE\t\tPATENTE\n\n");

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("%d\t\t%d%18s\n",listado[i].idAuto,listado[i].marca,listado[i].patente);
        }
    }
}









int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
