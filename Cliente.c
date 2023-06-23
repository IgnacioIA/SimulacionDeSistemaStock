#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Cliente.h"

struct ClienteEst{

char nombre[20];
char apellido[20];

char nombreUsuario[20];
char contrasena[20];
};

Cliente crearCliente(char nombre[20],char apellido[20], char nombreDeUsuario[20], char contra[20]){

Cliente cl = malloc(sizeof(struct ClienteEst));

strcpy(cl->nombre,nombre);
strcpy(cl->apellido,apellido);

strcpy(cl->nombreUsuario,nombreDeUsuario);
strcpy(cl->contrasena,contra);
return cl;

};

void mostrarCliente(Cliente cl){

printf("\n--------------------------------------------\n");
printf("Nombre: %s            Apellido: %s      Usuario: %s",cl->nombre,cl->apellido,cl->nombreUsuario);
printf("\n--------------------------------------------\n");

};


char * getNomUsuario(Cliente cl){
    return cl->nombreUsuario;
};
char * getContra(Cliente cl){
    return cl->contrasena;
};
