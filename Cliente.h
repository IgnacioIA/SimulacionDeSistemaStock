#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct ClienteEst;
typedef struct ClienteEst * Cliente;

Cliente crearCliente(char nombre[20],char apellido[20], char nombreDeUsuario[20], char contra[20]);
void mostrarCliente(Cliente cl);
char * getNomUsuario(Cliente cl);
char * getContra(Cliente cl);

#endif // CLIENTE_H_INCLUDED
