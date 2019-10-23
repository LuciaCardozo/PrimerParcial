#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#define OCUPADO 1
#define LIBRE 0

int cli_initCliente(Cliente* listCliente, int lenCliente)
{
    int ret = -1;
    int i;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            listCliente[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int cli_findFreePlace(Cliente* listCliente, int lenCliente)
{
    int ret = -1;
    int i;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int cli_findClienteById(Cliente* listCliente, int lenCliente,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listCliente!=NULL && lenCliente>0 && id>=0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].idCliente==id && listCliente[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}


int cli_addCliente(Cliente* listCliente, int lenCliente, int id, char *name,char *cuit,char *direccion,char *localidad)
{
    int ret = -1;
    int posLibre;

    posLibre= cli_findFreePlace(listCliente,lenCliente);
    if(listCliente!=NULL && lenCliente>0)
    {
        if(posLibre!=-1)
        {
            strncpy(listCliente[posLibre].nombre,name,51);
            strncpy(listCliente[posLibre].cuit,cuit,20);
            strncpy(listCliente[posLibre].direccion,direccion,51);
            strncpy(listCliente[posLibre].localidad,localidad,51);
            listCliente[posLibre].idCliente=id;
            listCliente[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addCliente'\n");
    }
    return ret;
}

int cli_registerAnCliente(Cliente *listCliente,int lenCliente)
{
    char auxName[51];
    char auxCuit[20];
    char auxDireccion[51];
    char auxLocalidad[51];
    int auxId;
    int ret = -1;
    if(listCliente!=NULL && lenCliente>0)
    {
        if(utn_getValidName(auxName)==0 &&
            utn_getValidStringNumerico("\nIngrese Cuit: ","\nError","\nError, excediste el maximo de caracteres",auxCuit,20,2)==0 &&
            utn_getValidString("\nIngrese direccion: ","\nError","\nError, excediste el maximo de caracteres",auxDireccion,51,2)==0 &&
            utn_getValidString("\nIngrese localidad: ","\nError","\nError, excediste el maximo de caracteres",auxLocalidad,51,2)==0)
            {
                auxId=generarIdCliente();
                cli_addCliente(listCliente,lenCliente,auxId,auxName,auxCuit,auxDireccion,auxLocalidad);
                printf("\n---------------------------\n");
                printf("\nID de cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                auxId,auxName,auxCuit,auxDireccion,auxLocalidad);
                ret=0;

            }
        }
    return ret;
}

int cli_modifyAnCliente(Cliente *listCliente,int lenCliente)
{
    int ret=-1;
    char auxDireccion[51];
    char auxLocalidad[51];
    int auxId;
    int auxPos;
    int opciones;
    if(listCliente!=NULL && lenCliente>0)
    {
        if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
        {

            if(cli_findClienteById(listCliente,lenCliente,auxId,&auxPos)==-1)
            {
                printf("\nError, no se encontro Id");
            }
            else
            {
                do
                {
                    if(utn_getValidInt("\n\nQue desea modificar?\n1-Direccion\n2-Localidad\n3-Salir\n\nIngrese opcion: ",
                                        "\nError",&opciones,1,3,2)==0)
                    {

                        switch(opciones)
                        {
                            case 1:
                                utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxDireccion,51,3);
                                strncpy(listCliente[auxPos].direccion,auxDireccion,51);
                                printf("\nNombre nuevo: %s",auxDireccion);
                                break;
                            case 2:
                                utn_getValidString("\nIngrese nuevo apellido: ","\nError","\nError, excediste el maximo de caracteres.",auxLocalidad,51,3);
                                strncpy(listCliente[auxPos].localidad,auxLocalidad,51);
                                printf("\nNombre: %s",auxLocalidad);
                                break;
                            case 3:
                                break;
                            default:
                                printf("\nError, No es una opcion");
                                break;
                        }
                        ret=0;
                    }
                }while(opciones!=3);
            }
        }
    }
    return ret;
}

int cli_removeCliente(Cliente* listCliente, int lenCliente,int id)
{
    int retorno=-1;
    int i;
    if(listCliente!=NULL && lenCliente>0 && id>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].idCliente==id)
            {
                listCliente[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int cli_printCliente(Cliente *listCliente,int lenCliente)
{
    int i;
    int ret = -1;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nId del cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                       listCliente[i].idCliente,listCliente[i].nombre,listCliente[i].cuit,listCliente[i].direccion,listCliente[i].localidad);
                ret = 0;
            }
        }
    }
    return ret;
}

int cli_printClienteById(Cliente *listCliente,int lenCliente,int id)
{
    int i;
    int ret = -1;
    if(listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listCliente[i].isEmpty==OCUPADO)
            {
                if(listCliente[i].idCliente==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del cliente: %d\nNombre: %s\nCuit: %s\nDireccion: %s\nLocalidad: %s\n",
                       listCliente[i].idCliente,listCliente[i].nombre,listCliente[i].cuit,listCliente[i].direccion,listCliente[i].localidad);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}

int generarIdCliente(void)
{
    static int idMax=1;
    return idMax++;
}
