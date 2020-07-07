#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "informes.h"
#include "direccion.h"

#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTIPO 4
#define TAM 100
#define TAMTRAB 100
#define TAMCLIENTE 10
#define TAMDIRE 10

int main()
{

    char seguir = 's';
    char confirma;
    int triggerAlta = 1; // EMPIEZA HARDODEADO - HABILITO TODAS LAS OPCIONES
    int triggerTrabajo = 1;  // EMPIEZA HARDODEADO - HABILITO TODAS LAS OPCIONES

    eTipo tipo[TAMTIPO] = {{1001, "Rutera"}, {1002, "Carrera"}, {1003, "Mountain"}, {1004, "BMX"}};
    eColor color[TAMCOLOR]= {{5001, "Gris"}, {5002, "Negro"}, {5003, "Blanco"}, {5004, "Azul"}, {5005, "Rojo"}};
    eServicio servicio[TAMSERVICIO] = {{20001, "Limpieza", 250}, {20002, "Centrado", 400}, {20003,"Parche", 300}, {20004,"Cadena", 350}};
    eTrabajo trabajo[TAMTRAB];
    eCliente cliente[TAMCLIENTE];
    eBicicleta lista[TAM];
    eDireccion dire[TAMDIRE];
    iniBicicletas(lista, TAM);
    iniTrabajo(trabajo, TAMTRAB);
    hardCodearBici(lista, TAM);
    hardCodearTrabajos(trabajo);
    hardcodearCliente(cliente, TAMCLIENTE);
    hardcodearDireccion(dire, TAMDIRE);

    do
    {
        switch(menuPrincipal())
        {
        case 'A':
        case 'a':
            if(altaBicicleta(lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE) == 0)
                {
                   triggerAlta = 1;
                }
            break;

        case 'B':
        case 'b':
            if(triggerAlta == 1)
              {
              modificarBicicleta(lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
              }
              else
                {
                    printf("\n\nNo puede modificar si no ingreso una bicicleta.");
                }
            break;

        case 'C':
        case 'c':
            if(triggerAlta == 1)
            {
            bajaBicicleta(lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            }
            else
                {
                    printf("\n\nNo puede dar de baja si no ingreso una bicicleta.");
                }
            break;

        case 'D':
        case 'd':
            if(triggerAlta == 1)
            {
            ordenarPorTipoYrodado(lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            }
            else
                {
                    printf("\n\nNo puede listar si no ingreso una bicicleta.");
                }
            break;
        case 'E':
        case 'e':
            listarTipos(tipo, TAMTIPO);
            break;

        case 'F':
        case 'f':
            listarColores(color, TAMCOLOR);
            break;

        case 'G':
        case 'g':
            listarServicios(servicio, TAMSERVICIO);
            break;

        case 'H':
        case 'h':
            if((altaTrabajo(trabajo, TAMTRAB, servicio, TAMSERVICIO, lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE)) == 0);
            {
                triggerTrabajo = 1;
            }
            break;

        case 'I':
        case 'i':
            if(triggerTrabajo == 1)
            {
            listarTrabajos(trabajo, TAMTRAB, lista, TAM, servicio, TAMSERVICIO);
            }
            else{
                printf("\n\nNo se puede listar trabajos si no dio de alta uno.\n");
                }
            break;

        case 'J':
        case 'j':
            informes(trabajo, TAMTIPO, lista, TAM, servicio, TAMSERVICIO,color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);

        case 'K':
        case 'k':
            listarLocalidades(dire, TAMDIRE);
            break;

        case 'L':
        case 'l':
            buscarPorlocalidad(lista, TAM, color, TAMCOLOR, tipo, TAMTIPO, cliente, TAMCLIENTE, dire, TAMDIRE);
            break;
        case 'X':
        case 'x':
            printf("Ingrese 's' para confirmar salida: ");
            scanf("%c", &confirma);
            __fpurge(stdin);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        getchar();
    }
    while(seguir == 's');

    return 0;
}











