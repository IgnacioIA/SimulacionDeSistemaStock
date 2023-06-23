#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
enum bolean {FalsePila,TruePila};

struct nodoEstPila;
typedef struct nodoEstPila * nodoPila;

struct PilaEst;
typedef struct PilaEst * Pila;

nodoPila crearNodoPila(Pila pil,void * dato);
Pila crearPila(int tamanioDelDatoEnByte);
int apilar (Pila pil,void * dato);
int desapilar (Pila pil);
void * obtenerElementoPila(Pila pil);

int getTamanioPila(Pila pil);

#endif // PILA_H_INCLUDED
