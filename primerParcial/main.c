#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "recoleccion.h"
#include "subMenu.h"
#define CANT_CLI 100
#define CANT_PED 1000

int main()
{
    Cliente listCliente[CANT_CLI];
    Pedido listPedido[CANT_PED];
    menuDeOpciones(listCliente,CANT_CLI,listPedido,CANT_PED);
    subMenuInformes(listCliente,CANT_CLI,listPedido,CANT_PED);

    return 0;
}
