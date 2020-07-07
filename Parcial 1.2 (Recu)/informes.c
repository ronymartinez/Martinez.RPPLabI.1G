#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "informes.h"


#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTIPO 4
#define TAM 100
#define TAMTRAB 100
#define TAMCLIENTE 10
#define TAMDIRE 10

void informes(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    char seguir = 's';
    eBicicleta lista[TAM];
    iniBicicletas(lista, TAM);
    iniTrabajo(trabajo, TAMTRAB);
    hardCodearBici(lista, TAM);
    hardCodearTrabajos(trabajo);
    hardcodearCliente(cliente, TAMCLIENTE);
    hardcodearDireccion(dire, TAMDIRE);

    do
    {
        switch(menuInformes())
        {
        case 1:

            informePorColor(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 2:
            informePorTipo(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 3:
            informePorMenorRodado(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;
        case 4:
            informeTodosLosTipos(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 5:
            informePorColorYTipo(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 6:
            informeColorMasElegido(lista, TAM, color, TAMCOLOR,tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 7:
            informeTrabajoPorBicicleta(trabajo, TAMTRAB, lista, TAM, servicio, TAMSERVICIO, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 8:
            informeTrabajoImportes(trabajo, TAMTRAB, lista, TAM, servicio, TAMSERVICIO, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;

        case 9:
            informeServicioYFecha(trabajo, TAMTRAB, lista, TAM, servicio, TAMSERVICIO, color, TAMCOLOR, tipo, TAMTIPO);
            break;
        case 10:
            informeTrabajoPorFecha(trabajo, TAMTRAB, lista, TAM, servicio, TAMSERVICIO, color, TAMCOLOR, tipo, TAMTIPO);
            break;

        case 11:
            seguir = 'n';
            break;
        }
    }while(seguir == 's');
}

void listarBicicleta(eBicicleta bicicleta, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    char descripcion[20];
    char nombreTipo[20];
    char nombreCliente[20];
    char localidad[20];



    cargarDescripcionColor(descripcion, bicicleta.idColor, color, tamColor);
    cargarDescripcionTipo(nombreTipo, bicicleta.idTipo, tipo, tamTipo);
    cargarDescripcionCliente(nombreCliente, bicicleta.idCliente, cliente, tamCliente);
    cargarDescripcionLocalidad(localidad, bicicleta.idCliente, dire, tamDire);


    printf("%2d    %8s   %8s    %6s     %5.2f   %8s   %8s\n", bicicleta.id, bicicleta.marca, nombreTipo, descripcion, bicicleta.rodado, nombreCliente, localidad);
}

void listarBicicletas(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int flag = 0;
    system("clear");
    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE    LOCALIDAD\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(bicicleta[i].isEmpty == 0)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay bicicletas para listar.\n\n");
        getchar();
    }
}

void ordenarPorTipoYrodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    eBicicleta auxBicicleta;
    char descripcion1[20];
    char descripcion2[20];

    printf("\n____________________________________\n");

    for (int i = 0; i < tam - 1; i++)
    {

        for (int j = i + 1;  j < tam;  j++)
        {
            cargarDescripcionTipo(descripcion1, bicicleta[i].idTipo, tipo, tamTipo);
            cargarDescripcionTipo(descripcion2, bicicleta[j].idTipo, tipo, tamTipo);

            if (strcmp(descripcion1, descripcion2) > 0 )
            {
                auxBicicleta = bicicleta[i];
                bicicleta[i] = bicicleta[j];
                bicicleta[j] = auxBicicleta;
            }
            else if ((strcmp(descripcion1, descripcion2) == 0) && (bicicleta[i].rodado > bicicleta[j].rodado))
            {
                auxBicicleta = bicicleta[i];
                bicicleta[i] = bicicleta[j];
                bicicleta[j] = auxBicicleta;
            }
        }
    }

    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
}

void listarTrabajo(eTrabajo trabajo, eBicicleta bicicleta, int tam, eServicio servicio[], int tamSer)
{
    char nombreServicio[20];
    char marca[20];
    int biciID;

    biciID = bicicleta.id;

        switch(biciID)
        {
            case 101:
            case 105:
            case 108:
            case 110:
            strcpy(marca,"Rutera");
            //bicicleta.idTipo=biciID
            break;

            case 102:
            case 107:
            strcpy(marca, "Carrera");
            break;

            case 103:
            case 109:
            strcpy(marca, "Mountain");
            break;

            case 104:
            case 106:
            strcpy(marca, "BMX");
            break;
        }

    cargarDescripcionServicio(nombreServicio, trabajo.idServicio, servicio, tamSer);

    printf("\n  Nº %2d         %3d      %8s      %8s    %02d/%02d/%4d", trabajo.id, trabajo.idBicicleta, marca,
    nombreServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

void listarTrabajos(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer)
{
    int flag = 0;
    system("clear");
    printf("           *** LISTADO DE TRABAJOS CARGADOS ***\n\n");
    printf("\nTRABAJO     ID BICI         MARCA      SERVICIO         FECHA\n");
    for(int i = 0; i < tamTrab; i++)
    {
        if(trabajo[i].isEmpty  == 0)
        {
            listarTrabajo(trabajo[i], bicicleta[i], tam, servicio, tamSer);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\n\nNo hay trabajos cargados.\n\n");
    }

}

int cargarDescripcionServicio(char nombreServicio[], int id, eServicio servicio[], int tamSer)
{
    int todoOk = 0;

    for(int i = 0; i < tamSer; i++)
    {
        if(servicio[i].id == id)
        {
            strcpy(nombreServicio, servicio[i].descripcion);
        }
    }
    return todoOk;
}

void listarTipos(eTipo tipo[], int tamTipo)
{
    system("clear");
    printf("***   LISTADO DE TIPOS  ***\n\n");
    printf("   ID      DESCRIPCION\n\n");

    for(int i = 0; i < tamTipo; i++)
    {
        printf(" %d       %10s\n",tipo[i].id, tipo[i].descripcion);
    }

}

void listarServicios(eServicio servicio[], int tamSer)
{
    system("clear");
    printf("***   LISTADO DE SERVICIOS  ***\n\n");
    printf("    ID      DESCRIPCION    PRECIO\n\n");

    for(int i = 0; i < tamSer; i++)
    {
        printf(" %d       %10s    %5.2f\n",servicio[i].id, servicio[i].descripcion, servicio[i].precio);
    }

}

void listarColores(eColor color[], int tamColor)
{
    system("clear");
    printf("***   LISTADO DE COLORES  ***\n\n");
    printf("   ID     DESCRIPCION\n\n");

    for(int i = 0; i < tamColor; i++)
    {
        printf(" %d      %10s\n",color[i].id, color[i].nombreColor);
    }

}

void informePorColor(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idColor;
    int flag = 0;

    system("clear");
    printf("***   INFORME POR COLOR   ***\n\n");
    printf("   ID      COLOR\n\n");

    for(int i = 0; i < tamColor; i++)
    {
        printf(" %d      %10s\n",color[i].id, color[i].nombreColor);
    }

    utn_getNumero(&idColor,"\n\nIngrese el ID del color a informar: ", "\nError, no ingreso un ID valido.", 5001, 5005,2);

    printf("\n\n\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(bicicleta[i].idColor == idColor && bicicleta[i].isEmpty == 0)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
            flag++;
        }
    }

    if(flag == 0)
    {
        printf("\nNo se encontraron bicicletas con el ID informado.\n\n");
    }
    getchar();
}

void informePorTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idTipo;
    int flag = 0;

    system("clear");
    printf("***   LISTADO DE TIPOS  ***\n\n");
    printf("   ID      DESCRIPCION\n\n");

    for(int i = 0; i < tamTipo; i++)
    {
        printf(" %d       %10s\n",tipo[i].id, tipo[i].descripcion);
    }

    utn_getNumero(&idTipo,"\n\nIngrese el ID del tipo a informar: ", "\nError, no ingreso un ID valido.", 1001, 1004,2);

    printf("\n\n\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
    for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == idTipo && bicicleta[i].isEmpty == 0)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
            flag++;
        }
    }

    if(flag == 0)
    {
            printf("\nNo se encontraron bicicletas con el ID informado.\n\n");
    }
    getchar();
}

void informePorMenorRodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    float menorRodado;

    system("clear");
    printf("***   LISTADO DE MENOR RODADO  ***");

    for(int i = 0; i < tam; i++)
    {
        if((bicicleta[i].rodado < menorRodado && bicicleta[i].isEmpty == 0) || i == 0)
        {
            menorRodado = bicicleta[i].rodado;
        }
    }
    printf("\n\n-El menor rodado es %2.f\n\n", menorRodado);

    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(bicicleta[i].rodado == menorRodado && bicicleta[i].isEmpty == 0)
        {
        listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
        }
    }
    getchar();
}

void informeTodosLosTipos(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idRutera = 1001;
    int IdCarrera = 1002;
    int idMountain = 1003;
    int idBMX = 1004;

    system("clear");
    printf(  "********* LISTADO POR TIPO - RUTERA **********\n");
    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
    for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == idRutera)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
        }
    }

    printf("\n\n********* LISTADO POR TIPO - CARRERA *********\n");
    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
    for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == IdCarrera)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
        }
    }

    printf("\n\n******** LISTADO POR TIPO - MOUNTAIN *********\n");
    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
    for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == idMountain)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
        }
    }

    printf("\n\n********** LISTADO POR TIPO - BMX ************\n");
    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
    for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == idBMX)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
        }
    }

    getchar();
}

void informePorColorYTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idTipo;
    int idColor;
    int contador = 0;

    system("clear");
    printf("***   CONTADOR DE TIPO Y COLOR  ***\n\n");
    printf("   ID           TIPO\n\n");
    for(int i = 0; i < tamTipo; i++)
    {
    printf("  %d    %10s\n",tipo[i].id, tipo[i].descripcion);
    }

    utn_getNumero(&idTipo,"\n\nIngrese el ID del TIPO a informar: ", "\nError, no ingreso un ID valido.", 1001, 1004,2);

    printf("________________________________________");
    printf("\n\n   ID          COLOR\n\n");
    for(int i = 0; i < tamColor; i++)
    {
        printf(" %d    %10s\n",color[i].id, color[i].nombreColor);
    }

    utn_getNumero(&idColor,"\n\nIngrese el ID del COLOR a informar: ", "\nError, no ingreso un ID valido.", 5001, 5005,2);
    printf("________________________________________\n");

    system("clear");

    printf("\n\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
     for(int i = 0; i < tam; i++)
    {

        if(bicicleta[i].idTipo == idTipo && bicicleta[i].idColor == idColor)
        {
            listarBicicleta(bicicleta[i], color , tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n\n**** No hay bicicletas con el color y tipo seleccionado. ****\n\n");
    }
    else{
        printf("\n\n**** Hay %d bicicleta/s con el color y tipo seleccionado. ****\n\n", contador);
        }

    getchar();
}

void informeColorMasElegido(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int maximoColor;
    char descripcion[20];
    int acumulador = 0;
    int IDMaximoColor;
    int contadorGris = 0; // 5001
    int contadorNegro = 0; //= 5002;
    int contadorBlanco = 0; //= 5003;
    int contadorAzul = 0; //= 5004;
    int contadorRojo = 0; //= 5005;

    system("clear");
    for (int i = 0; i < tam; i++)
    {
        if (bicicleta[i].idColor == 5001)
        {
            contadorGris++;
            acumulador = contadorGris;
        }
        if (bicicleta[i].idColor == 5002)
        {
            contadorNegro++;
            acumulador = contadorNegro;
        }
        if (bicicleta[i].idColor == 5003)
        {
            contadorBlanco++;
            acumulador = contadorBlanco;
        }
        if (bicicleta[i].idColor == 5004)
        {
            contadorAzul++;
            acumulador = contadorAzul;
        }
        if (bicicleta[i].idColor == 5005)
        {
            contadorRojo++;
            acumulador = contadorRojo;
        }

        if(i == 0 || maximoColor < acumulador)
        {
            maximoColor = acumulador;
            IDMaximoColor = bicicleta[i].idColor;
        }
    }

     for(int i = 0; i < tamColor; i++)
    {
        if(color[i].id == IDMaximoColor)
        {
            strcpy(descripcion, color[i].nombreColor);
        }
    }


    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);

    printf("\n\n           *** COLOR MAS ELEGIDO ***");
    printf("\n\n-El color mas elegido es el %s y fue elegido %d veces.",descripcion, maximoColor);

    getchar();

}

void informeTrabajoPorBicicleta(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idBici;
    int flag = 0;

    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);
    printf("\n\n");

    utn_getNumero(&idBici, "\nIngrese el ID de la bicicleta para ver trabajos cargados: ", "\nError, no ingreso un ID valido.", 101, 200, 2);

    system("clear");
    printf(" ******  TRABAJOS CARGADOS PARA LA BICICLETA ELEGIDA  *******");
    printf("\n\nTRABAJO     ID BICI         MARCA      SERVICIO         FECHA\n");
    for(int i = 0; i < tamTrab; i++)
    {
        if(idBici == trabajo[i].idBicicleta && trabajo[i].isEmpty == 0)
        {
        listarTrabajo(trabajo[i], bicicleta[i], tam, servicio, tamSer);
        flag++;
        }
    }

    if(flag == 0)
    {
        printf("\n\n-No hay trabajos cargados para el ID seleccionado.");
    }
    getchar();
}

void informeTrabajoImportes(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int idBici;
    float acumulador = 0;
    int IDServicioCargado;
    int flag = 0;

    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, cliente, tamDire);

    utn_getNumero(&idBici, "\nIngrese el ID de la bicicleta para ver el precio de los servicios cargados: ", "\nError, no ingreso un ID valido.", 101, 200, 2);

    system("clear");
    printf("                *****   LISTADO DE PRECIOS  *****\n\n");
    printf("                  ID      DESCRIPCION    PRECIO\n\n");

    for(int i = 0; i < tamSer; i++)
    {
        printf("                %d       %10s    %5.2f\n",servicio[i].id, servicio[i].descripcion, servicio[i].precio);
    }

    printf("\n______________________________________________________________");

    printf("\n\n**** TRABAJOS CARGADOS PARA LA BICICLETA ELEGIDA - ID %d ****", idBici);
    printf("\n\nTRABAJO     ID BICI         MARCA      SERVICIO         FECHA\n");

    for(int i = 0; i < tamTrab; i++)
    {
        if(trabajo[i].idBicicleta == idBici)
        {
            IDServicioCargado = trabajo[i].idServicio;
                for( int e = 0; e < tamSer; e++)
                {
                    if(servicio[e].id == IDServicioCargado)
                    {
                        acumulador = servicio[e].precio + acumulador;
                        listarTrabajo(trabajo[i], bicicleta[i], tam, servicio, tamSer);
                        flag++;
                    }
                }
        }
    }
    printf("\n\n______________________________________________________________");

    if(flag == 0)
    {
    printf("\n\n          -No hay trabajos cargados para el ID seleccionado.");
    }

    printf("\n\n\n        -El PRECIO TOTAL de los servicios cargados es de %.2f", acumulador);

    getchar();
}

void informeServicioYFecha(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int idServicio;
    int flag = 0;

    listarServicios(servicio, tamSer);

    utn_getNumero(&idServicio, "\n\nIngrese el ID del servicio para mostrar las bicicletas cargadas: ",
                    "\nError, no ingreso un ID valido.",20001, 20004, 2);

    system("clear");
    printf("\n\n** LISTADO DE TRABAJOS CARGADOS PARA EL SERVICIO Nº %d **\n\n", idServicio);
    printf("\nTRABAJO     ID BICI         MARCA      SERVICIO         FECHA\n");

    for(int i = 0; i < tamTrab; i++)
    {
        if(trabajo[i].idServicio == idServicio)
        {
        listarTrabajo(trabajo[i], bicicleta[i], tam, servicio, tamSer);
        flag++;
        }
    }

    if(flag == 0)
    {
    printf("\n\n          -No hay servicios cargados para el ID seleccionado.");
    }

    getchar();
}

void informeTrabajoPorFecha(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo)
{
    int dia;
    int mes;
    int anio;
    int flag = 0;

    system("clear");
    printf("** LISTADO DE TRABAJOS CARGADOS EN UNA FECHA ***\n\n");

    if (utn_getNumero(&dia, "\n\nIngrese el DIA del servicio a mostrar: ", "Error: no es un dato valido", 1, 31, 2) == 0)
    {
        if(utn_getNumero(&mes, "\nIngrese el MES del servicio a mostrar: ", "Error: no es un dato valido", 1, 12, 2) == 0)
        {
            if(utn_getNumero(&anio, "\nIngrese el ANIO del servicio a mostrar: ", "Error: no es un dato valido", 1990, 2030, 2) == 0)
            {
            system("clear");
            printf("*** LISTADO DE TRABAJOS CARGADOS EN LA FECHA %02d/%02d/%4d ***\n\n", dia, mes, anio);
            printf("\nTRABAJO     ID BICI         MARCA      SERVICIO         FECHA\n");

                for (int i = 0; i < tamTrab; i++)
                {
                  if(dia == trabajo[i].fecha.dia && mes == trabajo[i].fecha.mes && anio == trabajo[i].fecha.anio)
                  {
                    listarTrabajo(trabajo[i], bicicleta[i], tam, servicio, tamSer);
                    flag++;
                  }
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\n\nNo hay servicios cargados para la fecha indicada.\n");
    }

    getchar();
}

int cargarDescripcionCliente(char nombreCliente[], int idCliente, eCliente cliente[], int tamCliente)
{
    int todoOk = 0;

    for(int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].id == idCliente)
        {
            strcpy(nombreCliente, cliente[i].nombre);
        }
    }
    return todoOk;
}

void listarClientes(eCliente cliente[], int tamCliente)
{

    system("clear");
    printf("***   LISTADO DE CLIENTES  ***\n\n");
    printf("  ID         NOMBRE\n\n");

    for(int i = 0; i < tamCliente; i++)
    {
    printf(" %d     %10s\n",cliente[i].id, cliente[i].nombre);
    }

}

int cargarDescripcionLocalidad(char localidad[], int idCliente, eDireccion dire[], int tamCliente)
{
    int todoOk = 0;

    for(int i = 0; i < tamCliente; i++)
    {
        if(dire[i].idCliente == idCliente)
        {
            strcpy(localidad, dire[i].localidad);
        }
    }
    return todoOk;
}

int listarLocalidades(eDireccion dire[], int tamDire)
{
    system("clear");
    printf("***   LISTADO DE DIRECCIONES  ***\n\n");
    printf("  ID          LOCALIDAD      CODIGO POSTAL\n\n");

    for(int i = 0; i < tamDire; i++)
    {
    printf(" %4d     %10s         %5d\n",dire[i].idCliente, dire[i].localidad, dire[i].CP);
    }

}

int buscarPorlocalidad(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int opcion;
    listarLocalidades(dire, tamDire);

    printf("\nBUSCAR POR DIRECCION\n\n");

    utn_getNumero(&opcion, "\n\nIngrese el ID de la direccion elegida: ","\nError, ingreso un  CP invalido.", 100, 9999, 2);

    printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE   LOCALIDAD\n\n");

    for(int i = 0; i < tam; i ++)
    {
        if(opcion == dire[i].idCliente)
        {
        listarBicicleta(bicicleta[i], color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
        }
    }
    printf("\n\n");

}





