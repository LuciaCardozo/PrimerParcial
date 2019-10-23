#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int clienteConMasPedidosPendiente(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);
int clienteConMasPedidosCompleto(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);
int clienteConMenosKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int clienteConMasKilos(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int mostrarPorLugar(Pedido *listPedido,int lenPedido,Cliente * listCliente,int lenCliente);
int buscarClienteConMasPedidos(Pedido *listPedido,int lenPedido,int idCliente);
int clienteConMasPedidos(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);
int clienteConMasKilosPrueba(Pedido *listPedido,int lenPedido,Cliente *listCliente, int lenCliente);
int cantidadYPromedioDeKilosPp(Cliente *listCliente,int lenCliente,Pedido *listPedido,int lenPedido);

int clienteConMenos100Kg(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int clienteConMax1000Kg(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);

int calcularPorcentajePlasticoRecicladoPorIdCliente(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);
int mostrarPorcentajePlasticoReciclado(Pedido *listPedido,int lenPedido,Cliente *listCliente,int lenCliente);

#endif /* INFORMES_H_INCLUDED */
