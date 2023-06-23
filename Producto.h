#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct productoEst;
typedef struct productoEst * Producto;

Producto crearProducto(char nombreProducto[20],int precio,int enCuantosDiasVence);
void mostrarProducto(Producto pr);

char * getNombreProducto(Producto pr);
int getPrecio(Producto pr);
int getDiasAVencer(Producto pr);
#endif // PRODUCTO_H_INCLUDED
