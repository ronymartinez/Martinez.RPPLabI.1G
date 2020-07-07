#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "bicicleta.h"
#include "trabajo.h"
#include "direccion.h"

#endif // INFORMES_H_INCLUDED

void informes(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void listarBicicleta(eBicicleta bicicleta, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void listarBicicletas(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void ordenarPorTipoYrodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
//void listarTrabajo(eTrabajo trabajo, eBicicleta bicicleta, int tam, eTipo tipo[], int tamTipo, eServicio servicio[], int tamSer);
//void listarTrabajos(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eTipo tipo[], int tamTipo, eServicio servicio[], int tamSer);

void listarTrabajo(eTrabajo trabajo, eBicicleta bicicleta, int tam, eServicio servicio[], int tamSer);
void listarTrabajos(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer);


void listarTipos(eTipo tipo[], int tamTipo);
void listarServicios(eServicio servicio[], int tamSer);
void listarColores(eColor color[], int tamColor);

void informePorColor(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informePorTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informePorMenorRodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informeTodosLosTipos(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informePorColorYTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informeColorMasElegido(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informeTrabajoPorBicicleta(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informeTrabajoImportes(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);
void informeServicioYFecha(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo);
void informeTrabajoPorFecha(eTrabajo trabajo[], int tamTrab, eBicicleta bicicleta[], int tam, eServicio servicio[], int tamSer, eColor color[], int tamColor, eTipo tipo[], int tamTipo);

int cargarDescripcionCliente(char nombreCliente[], int idCliente, eCliente cliente[], int tamCliente);
void listarClientes(eCliente cliente[], int tamCliente);

int cargarDescripcionLocalidad(char localidad[], int idCliente, eDireccion dire[], int tamCliente);
int listarLocalidades(eDireccion dire[], int tamDire);
int buscarPorlocalidad(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire);

