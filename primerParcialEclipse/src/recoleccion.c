/*
 * recoleccion.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "recoleccion.h"
#include "cliente.h"
#define OCUPADO 1
#define LIBRE 0
#define PENDIENTE 1
#define COMPLETADO 0

int rec_initRecoleccion(Recoleccion* listRecoleccion, int lenRecoleccion)
{
    int ret = -1;
    int i;
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        for(i=0; i<lenRecoleccion; i++)
        {
            listRecoleccion[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int rec_findFreePlace(Recoleccion* listRecoleccion, int lenRecoleccion)
{
    int ret = -1;
    int i;
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        for(i=0; i<lenRecoleccion; i++)
        {
            if(listRecoleccion[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int rec_findRecoleccionById(Recoleccion* listRecoleccion, int lenRecoleccion,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listRecoleccion!=NULL && lenRecoleccion>0 && id>=0)
    {
        for(i=0; i<lenRecoleccion; i++)
        {
            if(listRecoleccion[i].idRecoleccion==id && listRecoleccion[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int rec_addRecoleccion(Recoleccion* listRecoleccion, int lenRecoleccion,int id,int idCliente,int estado,float kilos)
{
    int ret = -1;
    int posLibre;

    posLibre= rec_findFreePlace(listRecoleccion,lenRecoleccion);
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        if(posLibre!=-1)
        {
            listRecoleccion[posLibre].estado=estado;
            listRecoleccion[posLibre].cantidadDeKilos=kilos;
            listRecoleccion[posLibre].idCliente=idCliente;
            listRecoleccion[posLibre].idRecoleccion=id;
            listRecoleccion[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addRecoleccion'\n");
    }
    return ret;
}

int rec_registerAnRecoleccion(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente)
{
    int auxId;
    int auxIdCliente;
    float auxKilos;
    int auxEstado;
    int auxPos;
    int ret = -1;
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        if(utn_getValidInt("\nIngrese el id Cliente: ","\nError, no se encontro Id",&auxIdCliente,1,99999,2)==0)
            {
                if(cli_findClienteById(listCliente,lenCliente,auxIdCliente,&auxPos)==-1)
                {
                    printf("\nError, no se encontro Id");
                }
                else
                {
                    if(utn_getValidFloat("\nIngrese cantidad de kilos: ","\nError.",&auxKilos,1,99999,2)==0)
                     {
                            auxId=generarIdRecoleccion();
                            auxEstado=PENDIENTE;
                            rec_addRecoleccion(listRecoleccion,lenRecoleccion,auxId,auxIdCliente,auxEstado,auxKilos);
                            printf("\n---------------------------\n");
                            printf("\nID de recoleccion: %d\nId de Cliente %d\nCantidad de kilos: %.2f\n",
                            auxId,auxIdCliente,auxKilos);
                            if(auxEstado==1)
                            {
                                printf("Estado: PENDIENTE\n");
                            }
                     }
                }
                ret=0;

            }
        }
    return ret;
}

int rec_printRecoleccion(Recoleccion *listRecoleccion,int lenRecoleccion)
{
    int i;
    int ret = -1;
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        for(i=0; i<lenRecoleccion; i++)
        {
                if(listRecoleccion[i].isEmpty==OCUPADO && listRecoleccion[i].estado==PENDIENTE)
                {
                    printf("\n---------------------------\n");
                    printf("\nID de recoleccion: %d\nId de Cliente %d\nCantidad de kilos: %.2f\n",
                            listRecoleccion[i].idRecoleccion,listRecoleccion[i].idCliente,listRecoleccion[i].cantidadDeKilos);
                }
        }
        ret = 0;
    }
    return ret;
}

int rec_printRecoleccionPendiente(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret = -1;
    if(listRecoleccion!=NULL && lenRecoleccion>0)
    {
        for(i=0; i<lenRecoleccion; i++)
        {
            if(listRecoleccion[i].isEmpty==OCUPADO && listCliente[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nCuit cliente: %s\nDireccion: %s\nCantidad de kilos: %.2f\n",
                            listCliente[i].cuit,listCliente[i].direccion,listRecoleccion[i].cantidadDeKilos);
            }
        }
        ret = 0;
    }
    return ret;
}

int rec_procesarResiduos(Recoleccion *listRecoleccion,int lenRecoleccion,Cliente *listCliente,int lenCliente)
{
    int ret=-1;
    int auxTipo;
    int auxId;
    int auxPos;
    float auxKilos;
    if(listRecoleccion!=NULL && lenRecoleccion>0 && listCliente!=NULL && lenCliente>0)
    {
        rec_printRecoleccion(listRecoleccion,lenRecoleccion);
        if(utn_getValidInt("\nIngrese el id Recoleccion: ","\nError, no se encontro Id",&auxId,1,99999,2)==0)
            {
                if(rec_findRecoleccionById(listRecoleccion,lenRecoleccion,auxId,&auxPos)==-1)
                {
                    printf("\nError, no se encontro Id");
                }
                else
                {
                    if(utn_getValidInt("\nTipo de plasticos\n1-HDPE\n2-LDPE\n3-PP","\nError.",&auxTipo,1,3,2)==0)
                    {
                        if(utn_getValidFloat("\nIngrese kilos de plasticos: ","\nError.",&auxKilos,1,99999,2)==0)
                        {
                            if(auxKilos>=listRecoleccion[auxPos].cantidadDeKilos)
                            {
                                printf("Error");
                            }
                            else
                            {
                                listRecoleccion[auxPos].estado=COMPLETADO;
                                listRecoleccion[auxPos].cantidadDeKilos=auxKilos;
                                listRecoleccion[auxPos].tipo=auxTipo;
                                listRecoleccion[auxPos].idRecoleccion=auxPos;
                                listRecoleccion[auxPos].isEmpty=OCUPADO;
                                printf("\n---------------------------\n");
                                printf("\nId recoleccion: %d\nCantidad de kilo total: %.2f\nCantidad de kilos de plastico: %.2f\n",
                                listRecoleccion[auxPos].idRecoleccion,listRecoleccion[auxPos].cantidadDeKilos,auxKilos);
                                if(listRecoleccion[auxPos].estado==0)
                                {
                                    printf("Estado: Completado\n");
                                }
                                ret = 0;
                            }
                        }
                    }
                }
            }
    }
    return ret;
}

int generarIdRecoleccion(void)
{
    static int idMax=1;
    return idMax++;
}


