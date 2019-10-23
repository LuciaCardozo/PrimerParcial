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

int ped_initPedido(Pedido* listPedido, int lenPedido)
{
    int ret = -1;
    int i;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            listPedido[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int ped_findFreePlace(Pedido* listPedido, int lenPedido)
{
    int ret = -1;
    int i;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int ped_findPedidoById(Pedido* listPedido, int lenPedido,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(listPedido!=NULL && lenPedido>0 && id>=0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].idPedido==id && listPedido[i].isEmpty==OCUPADO)
            {
                *posicion=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int ped_addPedido(Pedido* listPedido, int lenPedido,int id,int idCliente,int estado,float kilos)
{
    int ret = -1;
    int posLibre;

    posLibre= ped_findFreePlace(listPedido,lenPedido);
    if(listPedido!=NULL && lenPedido>0)
    {
        if(posLibre!=-1)
        {
            listPedido[posLibre].estado=estado;
            listPedido[posLibre].cantidadDeKilos=kilos;
            listPedido[posLibre].idCliente=idCliente;
            listPedido[posLibre].idPedido=id;
            listPedido[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPedido'\n");
    }
    return ret;
}

int ped_addPedidoKilos(Pedido* listPedido, int lenPedido,int id,int idCliente,int estado,float kilos,float hdpe,float ldpe,float pp)
{
    int ret = -1;
    int posLibre;

    posLibre= ped_findFreePlace(listPedido,lenPedido);
    if(listPedido!=NULL && lenPedido>0)
    {
        if(posLibre!=-1)
        {
            listPedido[posLibre].estado=estado;
            listPedido[posLibre].cantidadDeKilos=kilos;
            listPedido[posLibre].cantidadHdpe=hdpe;
            listPedido[posLibre].cantidadLdpe=ldpe;
            listPedido[posLibre].cantidadPp=pp;
            listPedido[posLibre].idCliente=idCliente;
            listPedido[posLibre].idPedido=id;
            listPedido[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPedido'\n");
    }
    return ret;
}

int ped_registerAnPedido(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int auxId;
    int auxIdCliente;
    float auxKilos;
    int auxEstado;
    int auxPos;
    int ret = -1;
    if(listPedido!=NULL && lenPedido>0)
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
                    auxId=generarIdPedido();
                    auxEstado=PENDIENTE;
                    ped_addPedido(listPedido,lenPedido,auxId,auxIdCliente,auxEstado,auxKilos);
                    printf("\n---------------------------\n");
                    printf("\nID de pedoleccion: %d\nId de Cliente %d\nCantidad de kilos: %.2f\n",
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

int ped_procesarResiduos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int ret=-1;
    float auxCantTotal=0;
    int auxId;
    int auxPos;
    float auxKilosHdpe;
    float auxKilosLdpe;
    float auxKilosPp;
    float sumaTipo=0;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {

        if(utn_getValidInt("\nIngrese el id Pedido: ","\nError, no se encontro Id",&auxId,1,99999,2)==0)
        {
            if(ped_findPedidoById(listPedido,lenPedido,auxId,&auxPos)==-1)
            {
                printf("\nError, no se encontro Id");
            }
            else
            {
                auxCantTotal=listPedido[auxPos].cantidadDeKilos;
                if(utn_getValidFloat("\nIngrese kilos de plasticos HDPE: ","\nError.",&auxKilosHdpe,1,99999,2)==0)
                {
                    if(auxKilosHdpe>auxCantTotal)
                    {
                        printf("\nexcediste el maximo de cantidad total");
                    }
                    else if(auxKilosHdpe==auxCantTotal)
                    {
                        printf("\nNo hay mas espacio.");
                    }
                    else
                    {
                        auxCantTotal=auxCantTotal-auxKilosHdpe;
                        if(utn_getValidFloat("\nIngrese kilos de plasticos LDPE: ","\nError.",&auxKilosLdpe,1,99999,2)==0)
                        {
                            if(auxKilosLdpe>auxCantTotal)
                            {
                                printf("\nexcediste el maximo de cantidad total");
                            }
                            else if(auxKilosLdpe==auxCantTotal)
                            {
                                printf("\nNo hay mas espacio.");
                            }
                            else
                            {
                                auxCantTotal=auxCantTotal-auxKilosLdpe;
                                if(utn_getValidFloat("\nIngrese kilos de plasticos PP: ","\nError.",&auxKilosPp,1,99999,2)==0)
                                {
                                    if(auxKilosPp>auxCantTotal)
                                    {
                                        printf("\nExcediste el maximo de cantidad total");
                                    }
                                    else if(auxKilosPp==auxCantTotal)
                                    {
                                        printf("\nNo hay mas espacio.");
                                    }
                                    else
                                    {
                                        auxCantTotal=auxCantTotal-auxKilosPp;
                                    }
                                }
                            }
                        }
                    }
                }
                ped_addPedidoKilos(listPedido,lenPedido,auxId,listPedido[auxPos].idCliente,COMPLETADO,auxCantTotal,auxKilosHdpe,auxKilosLdpe,auxKilosPp);
                listPedido[auxPos].estado=COMPLETADO;
                sumaTipo=sumaTipo+auxKilosHdpe+auxKilosLdpe+auxKilosPp;
                printf("\n---------------------------\n");
                printf("\nId pedoleccion: %d\nCantidad plastico HDPE: %.2f\nCantidad plastico LDPE: %.2f\nCantidad plastico PP: %.2f\nCantidad de kilo total: %.2f\nCantidad de kilos de plastico: %.2f",
                       listPedido[auxPos].idPedido,auxKilosHdpe,auxKilosLdpe,auxKilosPp,listPedido[auxPos].cantidadDeKilos,sumaTipo);
                if(listPedido[auxId].estado==COMPLETADO)
                {
                    printf("\nEstado: Completado\n");
                }
                ret = 0;
            }
        }
    }
    return ret;
}
/*7*/
int ped_mostrarPedidoPendiente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente,int estado)
{
    int i,j;
    int ret=-1;
    if(listCliente!=NULL && lenCliente>0 && listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenCliente;i++)
        {
            for(j=0;j<lenPedido;j++)
            {
                if(listCliente[i].idCliente==listPedido[j].idCliente)
                {
                    if(listPedido[j].estado==PENDIENTE && listCliente[i].isEmpty==OCUPADO)
                    {
                        printf("\nId de Pedido: %d\nId de Cliente: %d\nCantidad de kilos: %.2f\nCuit cliente: %s\nDireccion: %s\n",
                               listPedido[j].idPedido,listPedido[j].idCliente,listPedido[j].cantidadDeKilos,listCliente[i].cuit,listCliente[i].direccion);
                    }
                }
            }
        }

    }
    return ret;
}
/*8*/
int ped_mostrarPedidoCompleto(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    int ret=0;
    int auxPos;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0;i<lenPedido;i++)
        {
            cli_findClienteById(listCliente,lenCliente,listPedido[i].idCliente,&auxPos);
            if(listPedido[i].isEmpty==OCUPADO && listPedido[i].estado==COMPLETADO)
            {
                printf("\nId de Pedido: %d\nId de Cliente: %d\nCuit cliente: %s\nDireccion: %s\nCantidad de kilos: %.2f\nPlastico HDPE: %.2f\nPlastico LPDE: %.2f\nPlastico PP: %.2f\n",
                        listPedido[i].idPedido,listPedido[i].idCliente,listCliente[auxPos].cuit,listCliente[auxPos].direccion,listPedido[i].cantidadDeKilos,listPedido[i].cantidadHdpe,
                        listPedido[i].cantidadLdpe,listPedido[i].cantidadPp);
            }
        }
    }
    return ret;
}
/*6.1*/
void mostrarCantidadPorEstado(Pedido *listPedido,int lenPedido,int idCliente,int estado)
{
    int i;
    int cantidadPorEstadoPendiente=0;
    int cantidadPorEstadoCompleto=0;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].idCliente==idCliente && listPedido[i].estado==estado)
            {
                if(estado==1)
                {
                    cantidadPorEstadoPendiente++;
                }
                else if(estado==0)
                {
                    cantidadPorEstadoCompleto++;
                }
            }
        }
        if(estado==1)
        {
            printf("\nCantidad de pedidos Pendientes: %d\n",cantidadPorEstadoPendiente);
        }
        else if(estado==0)
        {
            printf("\nCantidad de pedidos completos: %d\n",cantidadPorEstadoCompleto);
        }
    }
}
/*6.2*/
void ped_mostrarClienteYCantidadPorEstadoPendiente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
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
            }
        }
    }
}
/*5.1*/
void mostrarPedidoPorIdDeClienteYPorEstado(Pedido *listPedido,int lenPedido,int idCliente,int estado)
{
    int i;
    float sumaHpde=0;
    float sumaLpde=0;
    float sumaPp=0;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].idCliente==idCliente && listPedido[i].estado==estado)
            {
                sumaHpde=sumaHpde+listPedido[i].cantidadHdpe;
                sumaLpde=sumaLpde+listPedido[i].cantidadLdpe;
                sumaPp=sumaPp+listPedido[i].cantidadPp;
                printf("\nId de Pedido: %d\nCantidad de kilos totales: %.2f\n"
                       ,listPedido[i].idPedido,listPedido[i].cantidadDeKilos);
                if(estado==1)
                {
                    printf("\nEstado: PENDIENTE\n\n");
                }
            }
        }
    }
        if(estado==0)
        {
            printf("\nEstado: COMPLETADO\n\n");
            printf("\nCantidad de kilos totales de hpde: %.2f\nCantidad de kilos totales de lpde: %.2f\nCantidad de kilos totales de pp: %.2f\n"
                   ,sumaHpde,sumaLpde,sumaPp);
        }
}
/*5.2*/
void ped_mostrarClientePorEstado(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente,int estado)
{
    int i;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {

        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==estado && listPedido[i].isEmpty==OCUPADO)
            {
                cli_printClienteById(listCliente,lenCliente,listPedido[i].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarPedidoPorIdDeClienteYPorEstado(listPedido,lenPedido,listPedido[i].idCliente,estado);
            }
        }
    }
}

int ordenarPedidosPorIdCliente(Pedido *listPedido,int lenPedido)
{
    int i,j;
    int ret=-1;
    Pedido auxList;
    if(listPedido!=NULL && lenPedido>0)
    {
        for(i=0;i<lenPedido;i++)
        {
            for(j=i+1;j<lenPedido-1;i++)
            {
                if(listPedido[i].idCliente>listPedido[j].idCliente)
                {
                    auxList=listPedido[i];
                    listPedido[i]=listPedido[j];
                    listPedido[j]=auxList;
                }
            }

        }
        ret=0;
    }
    return ret;
}

int generarIdPedido(void)
{
    static int idMax=1;
    return idMax++;
}

/*void ped_mostrarClienteYCAntidadPorEstado(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente,int estado)
{
    int i;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {
        for(i=0; i<lenCliente; i++)
        {
            if(listPedido[i].estado==estado && listPedido[i].isEmpty==OCUPADO)
            {
                cli_printClienteById(listCliente,lenCliente,listPedido[i].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarCantidadPorEstado(listPedido,lenPedido,listPedido[i].idCliente,estado);
            }
        }
    }
}

void ped_mostrarClientePorEstadoPendiente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {

        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==PENDIENTE && listCliente[i].isEmpty==OCUPADO)
            {
                cli_printClienteById(listCliente,lenCliente,listPedido[i].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarPedidoPorIdDeClienteYPorEstado(listPedido,lenPedido,listPedido[i].idCliente,PENDIENTE);
            }
        }
    }
}

void ped_mostrarClientePorEstadoCompleto(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente)
{
    int i;
    if(listPedido!=NULL && lenPedido>0 && listCliente!=NULL && lenCliente>0)
    {

        for(i=0; i<lenPedido; i++)
        {
            if(listPedido[i].estado==COMPLETADO && listPedido[i].isEmpty==OCUPADO)
            {
                cli_printClienteById(listCliente,lenCliente,listPedido[i].idCliente);
                printf("\n------PEDIDOS------\n");
                mostrarPedidoPorIdDeClienteYPorEstado(listPedido,lenPedido,listPedido[i].idCliente,COMPLETADO);
            }
        }
    }
}
*/
