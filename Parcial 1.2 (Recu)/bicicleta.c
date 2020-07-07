#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include <ctype.h>
#include "bicicleta.h"
#include "informes.h"
#include "trabajo.h"
#include "direccion.h"

char menuPrincipal()
{
    char opcion;

    system("clear");
    printf("****** BICICLETERIA *****\n\n");
    printf("A. ALTA BICIBLETA\n");
    printf("B. MODIFICAR BICLETA\n");
    printf("C. BAJA BICICLETA\n");
    printf("D. LISTAR BICICLETAS\n");
    printf("E. LISTAR TIPOS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. INFORMES (2da Parte)\n");
    printf("K. LISTAR POR LOCADLIAD (Recu)\n");
    printf("L. BUSCAR POR DIRECCION (Recu)\n");
    printf("M.  (Recu)\n");

    printf("X. SALIR\n\n");
    printf("Ingrese opcion: ");
    scanf("%c", &opcion);
    __fpurge(stdin);

    return opcion;
}

int altaBicicleta (eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int todoOk = -1;
    int idInicial;
    char marca[7];
    int idTipo;
    int idColor;
    int rodado;
    int idCliente;

    idInicial = buscarLibre(bicicleta, tam);
    eBicicleta auxBicicleta;


    if( idInicial == -1)
    {
        printf("Sistema Completo\n\n");
    }
    else
    {
        system("clear");
        printf("*** ALTA BICICLETA - MARCA ***\n");
        utn_getNombre(marca, 7,"\n\n-Trek\n-Merida\n-Scott\n-Giant\n-Cube\n\n\nIndique la marca: ", "Error. No es una marca valida.", 2);
        strcpy(auxBicicleta.marca, marca);
        strlwrLinux(auxBicicleta.marca);
        auxBicicleta.marca[0] = toupper(auxBicicleta.marca[0]);

        system("clear");
        printf("*** ALTA BICICLETA  - TIPO***\n");
        utn_getNumero(&idTipo,"\n\n-ID 1001: Ruteran\n-ID 1002: Carrera\n-ID 1003: Mountain\n-ID 1004: BMX\n\n\nIndique el ID del tipo: ","Error: no es un ID valido", 1001, 1004, 2);
        auxBicicleta.idTipo = idTipo;

        system("clear");
        printf("*** ALTA BICICLETA - COLOR ***\n");
        utn_getNumero(&idColor,"\n\n-ID 5001: Gris\n-ID 5002: Negro\n-ID 5003: Blanco\n-ID 5004: Azul\n-ID 5005: Rojo\n\n\nIndique el ID del Color: ","Error: no es Id valido", 5001, 5005, 2);
        auxBicicleta.idColor = idColor;

        system("clear");
        printf("*** ALTA BICICLETA - RODADO ***\n");
        utn_getNumero(&rodado,"\n\n-ID 1: Rodado Nº 20\n-ID 2: Rodado Nº 26\n-ID 3: Rodado Nº 27.5\n-ID 4: Rodado Nº 29\n\n\nIndique el ID del  Rodado: ","Error: no es Id valido", 1, 4, 2);
            switch(rodado)
            {
                case 1:
                    auxBicicleta.rodado = 20;
                    break;
                case 2:
                    auxBicicleta.rodado = 26;
                    break;
                case 3:
                    auxBicicleta.rodado = 27.5;
                    break;
                case 4:
                    auxBicicleta.rodado = 29;
                    break;
            }

        system("clear");
        printf("*** ALTA BICICLETA - CLIENTE ***\n");
        listarClientes(cliente, tamCliente);
        utn_getNumero(&idCliente,"\n\nIndique el ID del Cliente: ","Error: no es ID valido", 101, 110, 2);
        auxBicicleta.idCliente = idCliente;

        auxBicicleta.isEmpty = 0;
        auxBicicleta.id = idInicial + 101;

        bicicleta[idInicial] = auxBicicleta;
        todoOk = 0;

        printf("\n\nSe ha incluido una bicicleta correctamente.");
    }

    return todoOk;
}

int iniBicicletas(eBicicleta bicicleta[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        bicicleta[i].isEmpty = 1;
    }

    return 0;
}

char menuModificar()
{
    char opcion;

    system("clear");
    printf("****** MODIFICAR BICICLETA *****\n\n");
    printf("A. Modificar Tipo\n");
    printf("B. Modificar Rodado\n");
    printf("C. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%c", &opcion);
    __fpurge(stdin);

    return opcion;
}

void modificarBicicleta(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    char seguir = 's';

    do
    {
        switch(menuModificar())
        {
         case 'A':
         case 'a':
            modificarTipo(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
            getchar();
            break;
        case 'B':
        case 'b':
            modificarRodado(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
            getchar();
            break;
        case 'C':
        case 'c':
            printf("\nHa finalizado la modificacion.\n");
            seguir = 'n';
            break;
        }
    }while(seguir == 's');

}

void modificarRodado(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int indice;
    int id;
    int opcion;


    system("clear");
    printf("***** MODIFICAR RODADO *****\n\n");
    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
    utn_getNumero(&id, "\n\nIngrese el ID de la bicicleta a modificar: ", "Error: dato no valido", 0, 1000, 3);

    indice = buscarBicicleta(id, bicicleta, tam);

      if (indice == -1)
      {
        printf("\n\nNo hay registro de bicicleta con el ID indicado.\n\n");
        getchar();

      }
      else
      {
        system("clear");
        printf("***** MODIFICAR RODADO *****\n\n");
        printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
        listarBicicleta(bicicleta[indice], color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);

        printf("\n1. Rodado Nº 20\n");
        printf("2. Rodado Nº 26\n");
        printf("3. Rodado Nº 27.50\n");
        printf("4. Rodado Nº 29\n");
        printf("5. Cancelar\n\n");
        utn_getNumero(&opcion, "\n\nIngrese la opcion correspondiente al nuevo rodado (1 al 5): ", "Error: dato no valido", 1, 5, 3);


            switch (opcion)
            {
                case 1:
                        bicicleta[indice].rodado = 20;
                        printf("\nSe ha modificado correctamente el rodado.\n");
                        break;
                case 2:
                        bicicleta[indice].rodado = 26;
                        printf("\nSe ha modificado correctamente el rodado.\n");
                        break;
                case 3:
                        bicicleta[indice].rodado = 27.50;
                        printf("\nSe ha modificado correctamente el rodado.\n");

                        break;
                case 4:
                        bicicleta[indice].rodado = 29;
                        printf("\nSe ha modificado correctamente el rodado.\n");
                        break;
                case 5:
                        printf("\nHa cancelado la modificacion.\n");
                        break;
            }
    }
}

void modificarTipo(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int indice;
    int id;
    int opcion;


    system("clear");
    printf("***** MODIFICAR TIPO *****\n\n");
    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
    utn_getNumero(&id, "\n\nIngrese el ID de la bicicleta a modificar: ", "Error: dato no valido", 0, 1000, 3);

    indice = buscarBicicleta(id, bicicleta, tam);

      if (indice == -1)
      {
        printf("\n\nNo hay registro de bicicleta con el ID indicado.\n\n");
        getchar();

      }
      else
      {
        system("clear");
        printf("***** MODIFICAR TIPO *****\n\n");
        printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
        listarBicicleta(bicicleta[indice], color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);

        printf("\n1. Rutera\n");
        printf("2. Carrera\n");
        printf("3. Mountain\n");
        printf("4. BMX\n");
        printf("5. Cancelar\n\n");
        utn_getNumero(&opcion, "\n\nIngrese la opcion correspondiente al nuevo tipo (1 al 5): ", "Error: dato no valido", 1, 5, 3);


    switch (opcion)
    {
        case 1:
                bicicleta[indice].idTipo = 1001;
                printf("\nSe ha modificado correctamente el tipo.\n");
                break;
        case 2:
                bicicleta[indice].idTipo = 1002;
                printf("\nSe ha modificado correctamente el tipo.\n");
                break;
        case 3:
                bicicleta[indice].idTipo = 1003;
                printf("\nSe ha modificado correctamente el tipo.\n");

                break;
        case 4:
                bicicleta[indice].idTipo = 1004;
                printf("\nSe ha modificado correctamente el tipo.\n");
                break;
        case 5:
                printf("\nHa cancelado la modificacion.\n");
                break;
    }
    }

}



int cargarDescripcionColor(char descripcion[], int id, eColor color[], int tamColor)
{
    int todoOk = 0;

    for(int i = 0; i < tamColor; i++)
    {
        if(color[i].id == id)
        {
            strcpy(descripcion, color[i].nombreColor);
        }
    }
    return todoOk;
}

int cargarDescripcionTipo(char nombreTipo[], int id, eTipo tipo[], int tamTipo)
{
    int todoOk = 0;

    for(int i = 0; i < tamTipo; i++)
    {
        if(tipo[i].id == id)
        {
            strcpy(nombreTipo, tipo[i].descripcion);
        }
    }
    return todoOk;
}

int buscarBicicleta(int id, eBicicleta bicicleta[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (bicicleta[i].id == id && bicicleta[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void bajaBicicleta(eBicicleta bicicleta[], int tam, eColor color[], int tamColor, eTipo tipo[], int tamTipo, eCliente cliente[], int tamCliente, eDireccion dire[], int tamDire)
{
    int id;
    int indice;
    char confirma;

    system("clear");
    printf("*** BAJA BICICLETA***\n\n");
    listarBicicletas(bicicleta, tam, color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);
    utn_getNumero(&id,"\n\nIngrese el ID de la bicicleta a dar de baja: ", "Error: dato no valido.", 0, 1000, 3);

    indice = buscarBicicleta(id, bicicleta, tam);

    if(indice == -1)
    {
        printf("\n\nNo hay registro de bicicleta con el ID %d\n\n", id);
    }
    else
    {

        system("clear");
        printf("*** BAJA BICICLETA***\n\n");
        printf("\n ID       MARCA       TIPO     COLOR    RODADO    CLIENTE\n\n");
        listarBicicleta(bicicleta[indice], color, tamColor, tipo, tamTipo, cliente, tamCliente, dire, tamDire);

        printf("\n\nIngrese 's' para confirmar baja: ");
        __fpurge(stdin);
        scanf("%c", &confirma);

        if(confirma == 's' || confirma == 'S')
        {
            bicicleta[indice].isEmpty = 1;
            printf("\n\nSe ha realizado la baja.\n\n");
        }
        else
        {
            printf("\n\nSe ha cancelado la operación.\n\n");
        }
    }
    getchar();
}

int buscarLibre(eBicicleta bicicleta[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (bicicleta[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void hardCodearBici(eBicicleta bicicleta[], int tam)
{
    eBicicleta aux1 = {101,   "Trek", 1001, 5001, 20.0, 0, 101};
    eBicicleta aux2 = {102, "Merida", 1002, 5002, 26.0, 0, 102};
    eBicicleta aux3 = {103,  "Scott", 1003, 5003, 27.5, 0, 103};
    eBicicleta aux4 = {104,  "Giant", 1004, 5004, 29.0, 0, 104};
    eBicicleta aux5 = {105,   "Cube", 1001, 5005, 26.0, 0, 105};
    eBicicleta aux6 = {106,  "Scott", 1002, 5003, 27.5, 0, 106};
    eBicicleta aux7 = {107,  " Cube", 1004, 5002, 29.0, 0, 107};
    eBicicleta aux8 = {108,   "Trek", 1004, 5002, 20.0, 0, 108};
    eBicicleta aux9 = {109,  "Giant", 1003, 5001, 26.0, 0, 109};
    eBicicleta aux10= {110,  "Scott", 1004, 5004, 27.5, 0, 110};

    bicicleta[0]= aux1;
    bicicleta[1]= aux2;
    bicicleta[2]= aux3;
    bicicleta[3]= aux4;
    bicicleta[4]= aux5;
    bicicleta[5]= aux6;
    bicicleta[6]= aux7;
    bicicleta[7]= aux8;
    bicicleta[8]= aux9;
    bicicleta[9]= aux10;

}

void hardcodearCliente(eCliente cliente[], int tamCliente)
{
    eCliente aux1  = {101, "Carla", 'f'};
    eCliente aux2  = {102, "Pedro", 'm'};
    eCliente aux3  = {103, "Julian", 'm'};
    eCliente aux4  = {104, "Sandra", 'f'};
    eCliente aux5  = {105, "Facundo", 'm'};
    eCliente aux6  = {106, "Noelia", 'f'};
    eCliente aux7  = {107, "Martin", 'm'};
    eCliente aux8  = {108, "Cristian", 'm'};
    eCliente aux9  = {109, "Joselin", 'f'};
    eCliente aux10 = {110, "Susana", 'f'};

    cliente[0]= aux1;
    cliente[1]= aux2;
    cliente[2]= aux3;
    cliente[3]= aux4;
    cliente[4]= aux5;
    cliente[5]= aux6;
    cliente[6]= aux7;
    cliente[7]= aux8;
    cliente[8]= aux9;
    cliente[9]= aux10;
}

int menuInformes()
{
    int opcion;

    system("clear");
    printf("****** MENU INFORMES *****\n\n");
    printf("1. INFORME POR COLOR\n");
    printf("2. INFORME POR TIPO\n");
    printf("3. INFORME MENOR RODADO\n");
    printf("4. INFORME TODOS LOS TIPOS.\n");
    printf("5. INFORME DE TIPO Y COLOR.\n");
    printf("6. INFORME COLOR MAS ELEGIDO.\n");
    printf("7. INFORME TRABAJO POR ID BICI\n");
    printf("8. INFORME TOTAL SERVICIOS.\n");
    printf("9. INFORME SERVICIO Y FECHA.\n");
    printf("10.INFORME TRABAJO POR FECHA\n");
    printf("11. SALIR\n\n");

    utn_getNumero(&opcion, "\n\n-Ingrese la opcion elegida: ","Error, ingreso una opcion invalida.", 1, 11, 2);
    __fpurge(stdin);

    return opcion;
}


void hardcodearDireccion(eDireccion dire[], int tamDire)
{
    eDireccion aux1  = {1450, "Lanus", 101};
    eDireccion aux2  = {1744, "Olivos", 102};
    eDireccion aux3  = {2203, "Lanus", 103};
    eDireccion aux4  = {3873, "Quilmes", 104};
    eDireccion aux5  = {4482, "Gerli", 105};
    eDireccion aux6  = {5909, "Salta", 106};
    eDireccion aux7  = {1373, "Martinez", 107};
    eDireccion aux8  = {2221, "Tigre", 108};
    eDireccion aux9  = {5199, "Olivos", 109};
    eDireccion aux10 = {2585, "Lanus", 110};

    dire[0]= aux1;
    dire[1]= aux2;
    dire[2]= aux3;
    dire[3]= aux4;
    dire[4]= aux5;
    dire[5]= aux6;
    dire[6]= aux7;
    dire[7]= aux8;
    dire[8]= aux9;
    dire[9]= aux10;
}





