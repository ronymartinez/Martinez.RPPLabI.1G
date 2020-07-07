#include "trabajo.h"
#include "bicicleta.h"
#include "utn.h"
#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>


int altaTrabajo(eTrabajo trabajo[], int tamTrab, eServicio servicio[], int tamSer, eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int todoOk = -1;
    int idBicicleta;
    eTrabajo auxTrabajo;
    int opcionServicio;
    int dia;
    int mes;
    int anio;
    int indice;
    int indiceInicial;


    indiceInicial = buscarTrabajoLibre(trabajo, tamTrab);
    indice = indiceInicial;

    if (indice == -1)
    {
        printf("\nNo hay disponibilidad para agregar trabajo");
    }
    else
    {
        system("clear");
        printf("*** ALTA TRABAJO ***\n");
        listarBicicletas(bicicleta, tam, color, tamColor, tipo,  tamTipo, cliente, tamCliente, dire, tamDire);
        printf("\n__________________________________________________________\n");
        utn_getNumero(&idBicicleta,"\n\nIndique el ID de la bicicleta para agregar trabajo: ","Error: no es ID valido", 101, 200, 3);
        auxTrabajo.idBicicleta = idBicicleta;

        opcionServicio = menuServicio(servicio, tamSer);
        auxTrabajo.idServicio = opcionServicio;

    if(opcionServicio == -1)
        {
            printf("\n\nNo se pudo cargar el trabajo.");
        }
        else
        {
            system("clear");
            printf("*** FECHA DE TRABAJO ***");
            utn_getNumero(&dia, "\n\nDia: ", "Error: no es un dato valido", 1, 31, 2);
            if (dia)
            {
            utn_getNumero(&mes, "\nMes: ", "Error: no es un dato valido", 1, 12, 2);
            }
            if (mes)
            {
            utn_getNumero(&anio, "\nAnio: ", "Error: no es un dato valido", 1990, 2030, 2);
            }
            if (anio)
            {

               auxTrabajo.fecha.dia = dia;
               auxTrabajo.fecha.mes = mes;
               auxTrabajo.fecha.anio = anio;

               indice++;
               auxTrabajo.id = indice;
               auxTrabajo.isEmpty = 0;

               trabajo[indiceInicial] = auxTrabajo;
               todoOk = 0;

               printf("\n\nSe ha cargado el trabajo.\n\n");

            }
            else
                {
                printf("\nLa fecha ingresada no es valida");
                printf("\n\nNo se pudo cargar el trabajo.\n\n");
                }

        }

    }

        return todoOk;


}

int menuServicio(eServicio servicio[], int tamSer)
{
    int opcion = -1;

    listarServicios(servicio, tamSer);

    printf("\n______________________________________\n");

    utn_getNumero(&opcion,"\nIngrese el ID del servicio a contratar: ", "\nError: dato no valido", 20001, 20004, 2);
    __fpurge(stdin);

    return opcion;
}

int iniTrabajo(eTrabajo trabajo[], int tamTrab)
{
 for(int i = 0; i < tamTrab; i++)
    {
        trabajo[i].isEmpty = 1;
    }

    return 0;
}



int buscarTrabajoLibre(eTrabajo trabajo[], int tamTrab)
{
    int indice = -1;

    for (int i = 0; i < tamTrab; i++)
    {
        if (trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void hardCodearTrabajos(eTrabajo trabajo[])
{

    eTrabajo aux1 = {1, 108, 20001, { 5, 3,2001}, 0};
    eTrabajo aux2 = {2, 104, 20002, {15, 7,2015}, 0};
    eTrabajo aux3 = {3, 103, 20003, { 8,10,2019}, 0};
    eTrabajo aux4 = {4, 102, 20004, { 5, 3,2001}, 0};
    eTrabajo aux5 = {5, 105, 20002, { 5, 5,2000}, 0};
    eTrabajo aux6 = {6, 110, 20004, { 8,11,2020}, 0};
    eTrabajo aux7 = {7, 107, 20002, { 5, 3,1998}, 0};
    eTrabajo aux8 = {8, 101, 20001, {25, 7,2021}, 0};
    eTrabajo aux9 = {9, 109, 20003, { 4, 1,1999}, 0};
    eTrabajo aux10= {10,106, 20003, { 8,12,2009}, 0};

    trabajo[0]= aux1;
    trabajo[1]= aux2;
    trabajo[2]= aux3;
    trabajo[3]= aux4;
    trabajo[4]= aux5;
    trabajo[5]= aux6;
    trabajo[6]= aux7;
    trabajo[7]= aux8;
    trabajo[8]= aux9;
    trabajo[9]= aux10;
}
