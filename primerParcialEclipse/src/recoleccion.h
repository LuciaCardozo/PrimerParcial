/*
 * recoleccion.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef RECOLECCION_H_
#define RECOLECCION_H_

#include "cliente.h"


typedef struct
{
    int isEmpty;
    int idRecoleccion;
    int idCliente;
    int estado;
    int tipo;
    float cantidadDeKilos;
}Recoleccion;

int generarIdRecoleccion(void);
int rec_initRecoleccion(Recoleccion* listRecoleccion, int lenRecoleccion);
int rec_findFreePlace(Recoleccion* listRecoleccion, int lenRecoleccion);
int rec_findRecoleccionById(Recoleccion* listRecoleccion, int lenRecoleccion,int id,int *posicion);
int rec_addRecoleccion(Recoleccion* listRecoleccion, int lenRecoleccion,int id,int idCliente,int estado,float kilos);
int rec_registerAnRecoleccion(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente);
int rec_printRecoleccion(Recoleccion *listRecoleccion,int lenRecoleccion);
int rec_printRecoleccionPendiente(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente);
int rec_procesarResiduos(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente);

#endif /* RECOLECCION_H_ */
