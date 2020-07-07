#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id; // 1000
    char descripcion[20];

} eTipo;

typedef struct
{
    int id; // 5000
    char nombreColor[20];
} eColor;

typedef struct
{
    int id; // 0
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
    int idCliente;
} eBicicleta;

typedef struct
{
    int id; // 20001
    char descripcion[25];
    float precio;
} eServicio;

typedef struct
{
    int id; // Autoincremental
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
} eCliente;

typedef struct
{
    int CP;
    char localidad[20];
    int idCliente;
} eDireccion;


#endif // BICICLETA_H_INCLUDED


char menuPrincipal();
void hardCodearBici(eBicicleta bicicleta[], int tam);
char menuPrincipal();
int altaBicicleta (eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
int iniBicicletas(eBicicleta bicicleta[], int tam);
char menuModificar();
void modificarBicicleta(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void modificarRodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void modificarTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamColor);
int cargarDescripcionTipo(char nombreTipo[], int id, eTipo tipo[], int tamTipo);
int buscarBicicleta(int id, eBicicleta bicicleta[], int tam);
void bajaBicicleta(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
int buscarLibre(eBicicleta bicicleta[], int tam);

void hardCodearBici(eBicicleta bicicleta[], int tam);
void hardcodearCliente(eCliente cliente[], int tamCliente);
int menuInformes();

void hardcodearDireccion(eDireccion dire[], int tamDire);


