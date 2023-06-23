#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Lista.h"
#include "Cliente.h"
#include "Pila.h"
#include "Cola.h"

void iniciaPrograma(Lista ls);
int verificar(char nombreDeUsuario[20],char contra[20],Lista ls);
Cliente conseguirCliente(char nombreDeUsuario[20],char contra[20],Lista ls);

void menuDeCompra(Cliente cli);
void menuVerduleria(Pila carrito);
void menuMercaderia(Pila carrito);
void menuCarniceria(Pila carrito);

void pagar(Pila carrito,Cliente cli);

Pila generadorDeStock(char nombreProducto[20]);
Pila ordenarYapilar(Lista ls);
Cola generarCola();

#endif // MENU_H_INCLUDED
