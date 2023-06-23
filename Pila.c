#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Pila.h"

struct nodoEstPila{

    void * dato;
    nodoPila proximo;

};


struct PilaEst{

int tamanioDelDatoEnByte;
int tamanioPila;
nodoPila primera;

};


nodoPila crearNodoPila(Pila pil,void * dato){

nodoPila aux= malloc(sizeof(struct PilaEst));
aux->dato = malloc(pil->tamanioDelDatoEnByte);

if(!aux->dato){
    free(aux);
    return aux;
}
memcpy(aux->dato,dato,pil->tamanioDelDatoEnByte);
return aux;
};

Pila crearPila(int tamanioDelDatoEnByte){

Pila pil = malloc(sizeof(struct PilaEst));

pil->primera=NULL;
pil->tamanioPila=0;
pil->tamanioDelDatoEnByte=tamanioDelDatoEnByte;
return pil;

};

int apilar (Pila pil,void * dato){

nodoPila aux=NULL;
if(!(aux=crearNodoPila(pil,dato))){
    return FalsePila;
}

if(pil->tamanioPila==0){

    pil->primera= aux;
    pil->tamanioPila++;
    aux->proximo=NULL;
    return TruePila;
}

    aux->proximo= pil->primera;
    pil->primera = aux;
    pil->tamanioPila++;
    return TruePila;
};

int desapilar (Pila pil){

nodoPila aux;

if(pil->tamanioPila==0){
    return FalsePila;
}

if(pil->tamanioPila==1){


    free(pil->primera->dato);
    free(pil->primera);
    pil->tamanioPila--;

    return TruePila;


}
    aux= pil->primera->proximo;
    free(pil->primera->dato);
    free(pil->primera);
    pil->primera= aux;
    pil->tamanioPila--;
    return TruePila;

};
void * obtenerElementoPila(Pila pil){
    if(pil->tamanioPila==0){
    return NULL;
}

    return pil->primera->dato;
};

int getTamanioPila(Pila pil){
    return pil->tamanioPila;
}
