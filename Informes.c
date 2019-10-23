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

int buscarClienteConMasPedidos(Pedido *listPedido,int lenPedido,int idCliente)
{
    int i;
    int contador=0;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].isEmpty==OCUPADO && listPedido[i].idCliente==idCliente && listPedido[i].estado==COMPLETADO && listPedido[i].estado==PENDIENTE)
            {
                contador++;
            }
        }
    }
    return 0;
}

int clienteConMasPedidos(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int i;
    int auxPos;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listCliente[i].isEmpty==OCUPADO)
            {
                cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos);
                buscarClienteConMasPedidos(listPedido,lenPedido,listPedido[i].idCliente);
                cli_printClienteById(listCliente,lenCliente,listCliente[auxPos].idCliente);
                break;
            }
        }
    }
    return 0;
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
                if(stricmp(listCliente[i].localidad,auxLocalidad)==0)
                {
                    mostrarCantidadPorEstado(listPedido,lenPedido,listCliente[i].idCliente,PENDIENTE);
                    ret=0;
                }
            }
        }
    }
    return ret;
}

int clienteConMasKilosPrueba(Pedido *listPedido,int lenPedido,Cliente *listCliente, int lenCliente)
{
    int i;
    int auxPos;
    int auxId;
    int numMax=0;
    int kgTotal=0;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==COMPLETADO && listPedido[i].isEmpty==OCUPADO)
            {
                auxId=cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos);
                if(listPedido[i].idCliente==auxId)
                {
                    kgTotal=listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                }

                if(i==0 && numMax>kgTotal)
                {
                    numMax=kgTotal;
                    auxId=listCliente[i].idCliente;
                }
            }
        }
        if(numMax!=0)
        {
            cli_printClienteById(listCliente,lenCliente,auxId);
        }
    }
    return 0;
}

int cantidadYPromedioDeKilosPp(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int i;
    int ret=-1;
    float sumaPp=0;
    float promedio;
    float cantidadCliente=0;
    if(listCliente!=NULL && lenCliente>0 && listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {
            if(listPedido[i].estado==COMPLETADO && listPedido[i].isEmpty==OCUPADO)
            {
                sumaPp=sumaPp+listPedido[i].cantidadPp;
            }
            if(listCliente[i].isEmpty==OCUPADO && listPedido[i].estado==COMPLETADO)
            {
                cantidadCliente++;
            }
        }
        printf("\nCantidad kilos: %.2f y cantidad cliente %.2f\n",sumaPp,cantidadCliente);
        promedio=sumaPp/cantidadCliente;
        printf("\nPromedio es: %.2f\n",promedio);

    }
    return ret;
}

int clienteConMasKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadTotal=0;
    float numMax;
    int auxId;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {

            cantidadTotal=0;
            if(listPedido[i].isEmpty==OCUPADO  && listPedido[i].estado==COMPLETADO)
            {
                cantidadTotal=cantidadTotal+listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
            }
            if(i==0)
            {
                numMax=cantidadTotal;
            }
            if(numMax>cantidadTotal)
            {
                numMax=cantidadTotal;
                auxId=listCliente[i].idCliente;
            }
        }
        cli_printClienteById(listCliente,lenCliente,auxId);
    }
    return ret;
}

int clienteConMenosKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadTotal=0;
    float numMin;
    int auxId;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {

            cantidadTotal=0;
            if(listPedido[i].isEmpty==OCUPADO  && listPedido[i].estado==COMPLETADO)
            {
                cantidadTotal=cantidadTotal+listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
            }
            if(i==0)
            {
                numMin=cantidadTotal;
            }
            if(numMin<cantidadTotal)
            {
                numMin=cantidadTotal;
                auxId=listCliente[i].idCliente;
            }
        }
        cli_printClienteById(listCliente,lenCliente,auxId);
    }
    return ret;
}

int clienteConMax1000Kg(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadTotal=0;
    int contador=0;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {

            cantidadTotal=0;
            if(listPedido[i].isEmpty==OCUPADO  && listPedido[i].estado==COMPLETADO)
            {
                cantidadTotal=cantidadTotal+listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                if(cantidadTotal>1000)
                {
                    contador++;
                }
            }
        }
         printf("Cantidad: %d",contador);

    }
    return ret;
}

int clienteConMenos100Kg(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadTotal=0;
    int cantidad=0;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {

            cantidadTotal=0;
            if(listPedido[i].isEmpty==OCUPADO  && listPedido[i].estado==COMPLETADO)
            {
                cantidadTotal=cantidadTotal+listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                if(cantidadTotal<100)
                {
                    cantidad++;
                }
            }
        }
         printf("Cantidad: %d",cantidad);

    }
    return ret;
}

int calcularPorcentajePlasticoRecicladoPorIdCliente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadKilos=0;
    float cantidadTotal=0;
    float porcentaje;
    int auxPos;
    int auxId;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0;i<lenPedido;i++)
        {
            if(listPedido[i].estado==COMPLETADO && listPedido[i].isEmpty==OCUPADO)
            {
                if(cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos)==0)
                {
                    if(listPedido[i].idCliente==listPedido[auxPos].idCliente)
                    {
                        cantidadKilos+=listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                        cantidadTotal+=listPedido[i].cantidadDeKilos;
                        auxId=listCliente[auxPos].idCliente;
                        printf("\nId pedido %d",listPedido[i].idPedido);
                    }
                }
            }
        }
        porcentaje=cantidadKilos*100/cantidadTotal;
        printf("\nCuit %s\nPorcentaje %.2f\n",listCliente[auxId-1].cuit,porcentaje);
    }
    return ret;
}

int mostrarPorcentajePlasticoReciclado(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=-1;
    float cantidadKilos=0;
    float cantidadTotal=0;
    int auxPos;
    float porcentaje;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        calcularPorcentajePlasticoRecicladoPorIdCliente(listPedido,lenPedido,listCliente,lenCliente);
        for(i=0;i<lenPedido;i++)
        {
            if(listPedido[i].estado==COMPLETADO && listPedido[i].isEmpty==OCUPADO)
            {
                if(cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos)==0)
                {
                    if(listPedido[i].idCliente!=listPedido[auxPos].idCliente)
                    {
                        cantidadKilos=listPedido[i].cantidadHdpe+listPedido[i].cantidadLdpe+listPedido[i].cantidadPp;
                        cantidadTotal=listPedido[i].cantidadDeKilos;
                        porcentaje=cantidadKilos*100/cantidadTotal;
                        printf("\nId Pedido %d\nCuit %s\nPorcentaje %.2f\n",listPedido[i].idPedido,listCliente[auxPos].cuit,porcentaje);
                    }
                }
            }
        }
    }
    return ret;
}


