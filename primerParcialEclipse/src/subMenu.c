/*
 * subMenu.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "recoleccion.h"
#include "utn.h"
#include "subMenu.h"
int menuDeOpciones(Cliente *listCliente,int lenCliente,Recoleccion *listRecoleccion,int lenRecoleccion)
{
    cli_initCliente(listCliente,lenCliente);
    rec_initRecoleccion(listRecoleccion,lenRecoleccion);
    int opciones;
    int ret=-1;
    int flag=0;
    int auxId;
    int auxPos;
    do
    {
        if(utn_getValidInt("\n1-Alta de cliente\n2-Modificar datos de cliente\n3-Baja de cliente\n4-Crear pedido\n5-Procesar pedido\n6-Imprimir cliente\n7-Imprimir pedidos pendientes\n8-Imprimir pedidos procesados\n9-Salir\nIngrese opcion: ",
        "\nError, no es una opcion",&opciones,1,9,2)==0)
        {
            switch(opciones)
            {
                case 1:
                if(cli_registerAnCliente(listCliente,lenCliente)==0)
                {
                    printf("\nAlta exitosa");
                    flag=1;
                }
                else
                {
                    printf("\nError.");
                }
                break;
                case 2:
                if(flag)
                {
                    cli_printCliente(listCliente,lenCliente);
                    if(cli_modifyAnCliente(listCliente,lenCliente)==0)
                    {
                        printf("\nModificaciones exitosa");
                    }
                    else
                    {
                        printf("\nError en modificacion.");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos");
                }
                break;
                case 3:
                if(flag)
                {
                    cli_printCliente(listCliente,lenCliente);
                    if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
                    {
                        if(cli_findClienteById(listCliente,lenCliente,auxId,&auxPos)==-1)
                        {
                            printf("\nError, no se encontro Id");
                        }
                        else
                        {
                            cli_removeCliente(listCliente,lenCliente,auxPos);
                        }
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos\n");
                }
                break;
                case 4:
                if(flag)
                {
                    cli_printCliente(listCliente,lenCliente);
                    if(rec_registerAnRecoleccion(listRecoleccion,lenRecoleccion,listCliente,lenCliente)==0)
                    {
                        printf("\nPedido Pendiente\n");
                    }
                    else
                    {
                        printf("\nError, en pedido");
                    }
                }
                else
                {
                    printf("\nNo se cargaron datos\n");
                }
                break;
                case 5:
                if(flag)
                {
                    if(rec_procesarResiduos(listRecoleccion,lenRecoleccion,listCliente,lenCliente)==0)
                    {
                        printf("\nProceso de residuos exitosa");
                    }
                }
                break;
                case 6:
                break;
                case 7:
                if(flag)
                {
                    rec_printRecoleccionPendiente(listRecoleccion,lenRecoleccion,listCliente,lenCliente);
                }
                break;
                case 8:
                break;
                case 9:
                break;
                default:
                printf("\nError, no es una opcion\n");
                break;
            }
        }
    }while(opciones!=9);
    return ret;
}


