#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include "Cliente.h"

struct nodoEstCola{
    void * dato;
    nodoCola proximo;

};

struct ColaEst{
    nodoCola primero;
    nodoCola ultimo;
    int numeroDElDatoEnBytes;
    int tamanioCola;

};


nodoCola crearNodoCola(Cola col,void * dato){

nodoCola auxNodo = malloc(sizeof(struct nodoEstCola));
auxNodo->dato=malloc(col->numeroDElDatoEnBytes);



 if (!auxNodo->dato) {
        free(auxNodo);
        return auxNodo;
    }

   ///Analizar
    memcpy(auxNodo->dato, dato, col->numeroDElDatoEnBytes);

    return auxNodo;


};

Cola crearCola(int tamanioDelDatoEnByte){

Cola auxCola = malloc(sizeof(struct ColaEst));

auxCola->numeroDElDatoEnBytes= tamanioDelDatoEnByte;
auxCola->primero= NULL;
auxCola->tamanioCola=0;
auxCola->ultimo= NULL;

return auxCola;


};

int encolar (Cola col,void * dato){

nodoCola auxNodo;
if(!(auxNodo=crearNodoCola(col,dato))){
    return FALSEC;
}

if(col->tamanioCola==0){
    col->primero=auxNodo;
    col->ultimo=auxNodo;
    col->tamanioCola++;
    return TRUEC;
}

auxNodo->proximo=col->primero;
col->primero=auxNodo;
col->tamanioCola++;
return TRUEC;


};
int desencolar (Cola col){

nodoCola aux;
nodoCola auxUltimo;
if(col->tamanioCola==0){
    return FALSEC;
}

if(col->tamanioCola==1){

    free(col->primero->dato);
    free(col->primero);
    free(col->ultimo->dato);
    free(col->ultimo);
    col->tamanioCola--;
    return TRUEC;

}else{
//-----------------------------------Tomo el anteultimo--------------------------------------
aux= NULL;
 for (aux = col->primero; aux != col->ultimo; aux = aux->proximo){
            auxUltimo=aux;
            }
//-------------------------------------------------------------------------------------------

free(col->ultimo->dato);
free(col->ultimo);
col->ultimo=auxUltimo;
col->tamanioCola--;
return TRUEC;

}


};

void * obtenerDatoCola(Cola col){

Cola aux;

if(col->tamanioCola==0){
    return NULL;
}
aux= col->ultimo->dato;
return aux;


};

int getTamanioCola(Cola col){
    return col->tamanioCola;
};

void mostrarColaClientes(Cola col){
nodoCola aux;
nodoCola auxUltimo;
nodoCola ultimo;
 for (aux = col->primero; aux != col->ultimo; aux = aux->proximo){

             auxUltimo=aux;
             Cliente cli=*((Cliente*)auxUltimo->dato);
             mostrarCliente(cli);


            }

};
