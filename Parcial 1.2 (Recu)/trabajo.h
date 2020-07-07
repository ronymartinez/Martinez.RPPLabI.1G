#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bicicleta.h"


#endif // TRABAJO_H_INCLUDED


int altaTrabajo(eTrabajo trabajo[], int tamTrab, eServicio servicio[], int tamSer, eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
int menuServicio(eServicio servicio[], int tamSer);
int iniTrabajo(eTrabajo trabajo[], int tamTrab);
int buscarTrabajoLibre(eTrabajo trabajo[], int tamTrab);
int cargarDescripcionServicio(char nombreServicio[], int id, eServicio servicio[], int tamSer);
void hardCodearTrabajos(eTrabajo trabajo[]);
