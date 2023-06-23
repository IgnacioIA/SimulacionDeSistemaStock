#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

struct productoEst{

    char nombre[20];
    int precio;
    int diasVencer;

};


Producto crearProducto(char nombreProducto[20],int precio,int enCuantosDiasVence){

Producto prod= malloc(sizeof(struct productoEst));

prod->precio=precio;
prod->diasVencer= enCuantosDiasVence;
strcpy(prod->nombre,nombreProducto);

return prod;

};


void mostrarProducto(Producto pr){

printf("\n---------------------\n");
printf("| Producto: %s   \n",pr->nombre);
printf("| Precio: %d      \n",pr->precio);
printf("| Vence en: %d Dias",pr->diasVencer);
printf("\n---------------------\n");


};

char * getNombreProducto(Producto pr){

return pr->nombre;

};
int getPrecio(Producto pr){

return pr->precio;

};
int getDiasAVencer(Producto pr){

return pr->diasVencer;

};
