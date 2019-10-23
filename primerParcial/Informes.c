#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "recoleccion.h"
#include "subMenu.h"
#define PENDIENTE 1
#define COMPLETADO 0
#define LIBRE 0
#define OCUPADO 1

int clienteConMasPedidosCompleto(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int i;
    int auxPos;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==COMPLETADO && listCliente[i].isEmpty==OCUPADO)
            {
                cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos);
                cli_printClienteById(listCliente,lenCliente,listCliente[auxPos].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarCantidadPorEstado(listPedido,lenPedido,listPedido[i].idCliente,COMPLETADO);
                break;
            }
        }
    }
    return 0;
}

int clienteConMasPedidosPendiente(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int i;
    int auxPos;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==PENDIENTE && listCliente[i].isEmpty==OCUPADO)
            {
                cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos);
                cli_printClienteById(listCliente,lenCliente,listCliente[auxPos].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarCantidadPorEstado(listPedido,lenPedido,listPedido[i].idCliente,PENDIENTE);
                break;
            }
        }
    }
    return 0;
}

int clienteConMenosKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i,j;
    int ret=-1;
    int recicladoMinimo=0;
    float total=0;
    int idAux;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0;i<lenPedido;i++)
        {
            for(j=0;j<lenCliente;j++)
            {
                if(listPedido[i].idCliente==listCliente[j].idCliente)
                {
                    if(listPedido[i].isEmpty==OCUPADO && listPedido[i].estado==COMPLETADO)
                    {
                        recicladoMinimo=listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                    }
                    if(recicladoMinimo>total)
                    {
                        total=recicladoMinimo;
                        idAux=listCliente[i].idCliente;
                    }
                }
            }
        }
        if(total!=0)
        {
            cli_printClienteById(listCliente,lenCliente,idAux);
        }
    }
    return ret;
}

int mostrarPorLugar(Pedido *listPedido,int lenPedido,Cliente * listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    char auxLocalidad[50];
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente)
    {
        if(utn_getValidString("\nIngrese localidad: ","\nError","\nError, excediste el maximo de caracteres",auxLocalidad,51,2)==0)
        {
            for(i=0;i<lenCliente;i++)
            {
                if(strncmp(listCliente[i].localidad,auxLocalidad,50)==0)
                {
                    mostrarCantidadPorEstado(listPedido,lenPedido,listCliente[i].idCliente,PENDIENTE);
                    ret=0;
                }

            }
        }
    }
    return ret;
}


/*int clienteConMasPedidosPendiente(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int i;
    int ret=-1;
    if(listCliente!=NULL && lenCliente>0 && listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<;i++)
    }
    return ret;
}*/
