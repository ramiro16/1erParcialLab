typedef struct
{
    int idCliente;
    int dni;
    char nombre[50];
    char apellido[50];
    int estado;

}eCliente;

typedef struct
{
    int cliente;
    int idAlquiler;
    char equipo[20];
    char estado[20];
    char operador[20];
    int tiempoEstimado;
    int tiempoReal;

}eAlquiler;

void cargaCliente(eCliente[], int);
void cargaAlquiler(eAlquiler[],int);
void informarAlquileresxCliente(eCliente[],int, eAlquiler[],int);
void inicializarCliente(eCliente[], int);
void inicializarAlquiler(eAlquiler[], int);
void altaCliente(eCliente[],int);
