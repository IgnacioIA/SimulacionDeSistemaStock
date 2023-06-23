#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

enum Booleanos {FALSEC, TRUEC};

struct nodoEstCola;
typedef struct nodoEstCola * nodoCola;


struct ColaEst;
typedef struct ColaEst * Cola;

nodoCola crearNodoCola(Cola col,void * dato);
Cola crearCola(int tamanioDelDatoEnByte);
int encolar (Cola col,void * dato);
int desencolar (Cola col);
void mostrarColaClientes(Cola col);

void * obtenerDatoCola(Cola col);

int getTamanioCola(Cola col);



#endif // COLA_H_INCLUDED
