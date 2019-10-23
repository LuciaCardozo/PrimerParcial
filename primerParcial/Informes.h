#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int clienteConMasPedidosPendiente(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);
int clienteConMasPedidosCompleto(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);
int clienteConMenosKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int mostrarPorLugar(Pedido *listPedido,int lenPedido,Cliente * listCliente,int lenCliente);


#endif /* INFORMES_H_INCLUDED */
