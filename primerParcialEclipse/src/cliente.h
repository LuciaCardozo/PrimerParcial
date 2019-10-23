/*
 * cliente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
    int isEmpty;
    int idCliente;
    char nombre[51];
    char cuit[20];
    char direccion[51];
    char localidad[51];
}Cliente;

int cli_initCliente(Cliente* list, int lenCliente);
int cli_findFreePlace(Cliente* list, int lenCliente);
int cli_findClienteById(Cliente* list, int lenCliente,int id,int *posicion);
int cli_addCliente(Cliente* list, int lenCliente, int id, char *name,char *dni,char *direccion,char *localidad);
int cli_registerAnCliente(Cliente *list,int lenCliente);
int cli_modifyAnCliente(Cliente *list,int lenCliente);
int cli_removeCliente(Cliente* list, int lenCliente,int id);
int cli_printCliente(Cliente *list,int lenCliente);
int cli_printClienteById(Cliente *list,int lenCliente,int id);
int generarIdCliente(void);

#endif /* CLIENTE_H_ */
