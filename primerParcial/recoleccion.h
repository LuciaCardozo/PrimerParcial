#ifndef RECOLECCION_H_INCLUDED
#define RECOLECCION_H_INCLUDED
#include "cliente.h"


typedef struct
{
    int isEmpty;
    int idPedido;
    int idCliente;
    int estado;
    float cantidadHdpe;
    float cantidadLdpe;
    float cantidadPp;
    float cantidadDeKilos;
}Pedido;

int generarIdPedido(void);
int ped_initPedido(Pedido* listPedido, int lenPedido);
int ped_findFreePlace(Pedido* listPedido, int lenPedido);
int ped_findPedidoById(Pedido* listPedido, int lenPedido,int id,int *posicion);
int ped_addPedido(Pedido* listPedido, int lenPedido,int id,int idCliente,int estado,float kilos);
int ped_addPedidoKilos(Pedido* listPedido, int lenPedido,int id,int idCliente,int estado,float kilos,float hdpe,float ldpe,float pp);
int ped_registerAnPedido(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
void mostrarPedidoPorIdDeClienteYPorEstado(Pedido *listPedido,int lenPedido,int idCliente,int estado);
void ped_mostrarClientePorEstado(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente,int estado);
int ped_procesarResiduos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
void mostrarCantidadPorEstado(Pedido *listPedido,int lenPedido,int idCliente,int estado);
void ped_mostrarClienteYCantidadPorEstadoPendiente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int ped_mostrarPedidoPendiente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente,int estado);
int ped_mostrarPedidoCompleto(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);

#endif /* RECOLECCION_H_INCLUDED */
