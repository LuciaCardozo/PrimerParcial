/*
 ============================================================================
 Name        : primerParcialEclipse.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "recoleccion.h"
#include "subMenu.h"
#define CANT_CLI 100
#define CANT_REC 1000

int main()
{
    Cliente listCliente[CANT_CLI];
    Recoleccion listRecoleccion[CANT_REC];
    menuDeOpciones(listCliente,CANT_CLI,listRecoleccion,CANT_REC);
    return 0;
}

