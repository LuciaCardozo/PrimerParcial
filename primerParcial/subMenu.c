#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "recoleccion.h"
#include "Informes.h"
#include "utn.h"
#include "subMenu.h"
#define PENDIENTE 1
#define COMPLETADO 0

int menuDeOpciones(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    cli_initCliente(listCliente,lenCliente);
    ped_initPedido(listPedido,lenPedido);
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"Telefonica","30-11223344-5","Lima 1234","CABA");
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"DATASOFT","30-44556677-6","Corrientes 2547","CABA");
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"NESTLE","30-88995521-9","cucha cucha 555","LANUS");
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"TERRABUSI","30-56781423-5","rocha 784","QUILMES");
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"DIA","31-54581253-3","Mitre 750","AVELLANEDA");
    cli_addCliente(listCliente,lenCliente,generarIdCliente(),"QUILMES","30-51485759-6","rocha 741","QUILMES");
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),1,COMPLETADO,1000,200,145,230);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),1,COMPLETADO,800,210,45,30);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),2,PENDIENTE,100,0,0,0);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),2,PENDIENTE,300,0,0,0);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),3,COMPLETADO,1500,500,150,270);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),4,COMPLETADO,750,100,50,70);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),1,PENDIENTE,200,0,0,0);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),5,COMPLETADO,30,10,5,3);
    ped_addPedidoKilos(listPedido,lenPedido,generarIdPedido(),6,PENDIENTE,456,0,0,0);
    int opciones;
    int ret=-1;
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
                    }
                    else
                    {
                        printf("\nError.");
                    }
                    break;
                case 2:
                    cli_printCliente(listCliente,lenCliente);
                    if(cli_modifyAnCliente(listCliente,lenCliente)==0)
                    {
                        printf("\nModificaciones exitosa");
                    }
                    else
                    {
                        printf("\nError en modificacion.");
                    }
                    break;
                case 3:
                    cli_printCliente(listCliente,lenCliente);
                    if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorpedta.",&auxId,1,99999,2)==0)
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
                    else
                    {
                        printf("\nError no se pudo remover el cliente\n");
                    }
                    break;
                case 4:
                    cli_printCliente(listCliente,lenCliente);
                    if(ped_registerAnPedido(listPedido,lenPedido,listCliente,lenCliente)==0)
                    {
                        printf("\nPedido Pendiente\n");
                    }
                    else
                    {
                        printf("\nError, en pedido");
                    }
                    break;
                case 5:
                    ped_mostrarClientePorEstado(listPedido,lenPedido,listCliente,lenCliente,PENDIENTE);
                    if(ped_procesarResiduos(listPedido,lenPedido,listCliente,lenCliente)==0)
                    {
                        printf("\nProceso de residuos exitosa");
                    }
                    break;
                case 6:
                ped_mostrarClienteYCantidadPorEstadoPendiente(listPedido,lenPedido,listCliente,lenCliente);
                break;
                case 7:
                ped_mostrarPedidoPendiente(listPedido,lenPedido,listCliente,lenCliente,PENDIENTE);
                break;
                case 8:
                ped_mostrarPedidoCompleto(listPedido,lenPedido,listCliente,lenCliente);
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


int subMenuInformes(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido)
{
    int ret=-1;
    int opciones;
    do
    {
        if(utn_getValidInt("\n1-Cliente con mas pedidos pendiente\n2-Cliente con mas pedidos completados\n3-Cliente con menos pedidos\n4- Mostrar por Lugar\n5-Salir pedido\n6- cliente\n7-  \n8-  \n9-\nIngrese opcion: ",
        "\nError, no es una opcion",&opciones,1,5,2)==0)
        {
            switch(opciones)
            {
                case 1:
                clienteConMasPedidosPendiente(listCliente,lenCliente,listPedido,lenPedido);
                break;
                case 2:
                clienteConMasPedidosCompleto(listCliente,lenCliente,listPedido,lenPedido);
                break;
                case 3:
                clienteConMenosKilos(listPedido,lenPedido,listCliente,lenCliente);
                break;
                case 4:
                mostrarPorLugar(listPedido,lenPedido,listCliente,lenCliente);
                break;
                case 5:
                break;
            }
        }

    }while(opciones!=5);

    return ret;
}
