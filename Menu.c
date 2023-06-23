#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "Menu.h"
#include "Cliente.h"
#include "Lista.h"
#include "Producto.h"
#include "Cola.h"

    void iniciaPrograma(Lista ls){

        Cliente clienteEncontrado=NULL;
        int contador=0;
        int nVerificar=0;
        int opcion;
        char nUsuario[20];
        char contra[20];

    do
    {
        printf( "\n  --------- SuperMercado --------- \n ");
        printf( "\n  Nombre de usuario:   ");

        scanf( "%s", &nUsuario );

        printf( "\n  Contrasena:   ");

        scanf( "%s", &contra );


        nVerificar=verificar(nUsuario,contra,ls);

        if(nVerificar==0){

            system("CLS");
            printf("Usuario o contrasena inconrrecta\n");
            system("pause");
            system("CLS");
            contador++;


            if(contador==4){
                opcion=4;}


        }else{
            opcion=1;

        switch ( opcion )
        {
            case 1:
                    system("CLS");
                    clienteEncontrado= conseguirCliente(nUsuario,contra,ls);
                    menuDeCompra(clienteEncontrado);

                    opcion=4;
                    break;


         }
        }


    } while ( opcion != 4 );

    };



    int verificar(char nombreDeUsuario[20],char contra[20],Lista ls){
    int numeroRetorno=0;
    int i=0;
    int nDeWhile=0;
    Cliente cli;


    while (nDeWhile!=1){


            cli= *((Cliente*)obtenerDato(ls,i));
            if(strcmp(nombreDeUsuario,getNomUsuario(cli))==0){
                    if(strcmp(contra,getContra(cli))==0){
                            numeroRetorno= 1;
                            nDeWhile=1;
            }

            }

            if(i <= obtenerTamanio(ls)){
                nDeWhile=1;
            }
            i++;





    }


    return numeroRetorno;
    };



    Cliente conseguirCliente(char nombreDeUsuario[20],char contra[20],Lista ls){
    int i=0;
    int nDeWhile=0;
    Cliente cli;


    while (nDeWhile!=1){


            cli= *((Cliente*)obtenerDato(ls,i));
            if(strcmp(nombreDeUsuario,getNomUsuario(cli))==0){
                    if(strcmp(contra,getContra(cli))==0){
                            nDeWhile=1;
            }

            }

            if(i <= obtenerTamanio(ls)){
                nDeWhile=1;
            }
            i++;





    }


    return cli;
    };
    //----------------------------------------------------------

void menuDeCompra(Cliente cli){
    Pila carrito= crearPila(sizeof(Producto));
    int n, opcion;

    do
    {
        system("CLS");
        printf("Bienvenido");
        mostrarCliente(cli);
        printf( "\n Elija segun o que necesite\n" );

        printf( "\n   1. Verduleria");
        printf( "\n   2. Mercaderia" );
        printf( "\n   3. Carniceria" );
        printf( "\n   4. Pagar" );

        printf( "\n\n   5. Cerrar Sesion." );
        printf( "\n\n   Introduzca opci%cn (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                    menuVerduleria(carrito);
                    break;

            case 2:
                    menuMercaderia(carrito);
                    break;

            case 3:
                    menuCarniceria(carrito);
                    break;

            case 4:
                    if(getTamanioPila(carrito)>0){
                        pagar(carrito,cli);
                        opcion=5;
                    }else{
                        system("CLS");
                        printf("SU  CARRITO ESTA VACIO\n");
                        system("pause");
                    }

                    break;

         }

         /* Fin del anidamiento */

    } while ( opcion != 5 );

}

void menuVerduleria(Pila carrito){

    Pila p1=generadorDeStock("Papa");
    Pila p2=generadorDeStock("Morron");
    Pila p3=generadorDeStock("Cebolla");
    Pila p4=generadorDeStock("Tomate");

    int n, opcion;

    do
    {
        system("CLS");
        printf("Bienvenido");

        //------------Producto 1------------------------
        printf( "\n\n   1. Para comprar el producto: ");
         if(obtenerElementoPila(p1)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p1));
        mostrarProducto(produc);

            }
        //------------Producto 2------------------------
        printf( "\n\n   2. Para comprar el producto: ");

             if(obtenerElementoPila(p2)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p2));
        mostrarProducto(produc);

            }

        //------------Producto 3------------------------
        printf( "\n\n   3. Para comprar el producto: ");
             if(obtenerElementoPila(p3)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p3));
        mostrarProducto(produc);

            }

        //------------Producto 4------------------------
        printf( "\n\n   4. Para comprar el producto: ");
         if(obtenerElementoPila(p4)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p4));
        mostrarProducto(produc);

            }



        printf( "\n\n   5. Volver." );
        printf( "\n\n   Introduzca opci%cn (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                    if(obtenerElementoPila(p1)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p1));
                        apilar(carrito,&produc);
                        desapilar(p1);
                        }
                    break;

            case 2:
                    if(obtenerElementoPila(p2)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p2));
                        apilar(carrito,&produc);
                        desapilar(p2);
                        }

                    break;

            case 3:
                    if(obtenerElementoPila(p3)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p3));
                        apilar(carrito,&produc);
                        desapilar(p3);
                        }

                    break;
            case 4:
                    if(obtenerElementoPila(p4)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p4));
                        apilar(carrito,&produc);
                        desapilar(p4);
                        }

                    break;

         }

         /* Fin del anidamiento */

    } while ( opcion != 5 );

}

void menuMercaderia(Pila carrito){

    Pila p1=generadorDeStock("Arroz");
    Pila p2=generadorDeStock("Lentejas");
    Pila p3=generadorDeStock("Polenta");
    Pila p4=generadorDeStock("Fideos");

    int n, opcion;

    do
    {
        system("CLS");
        printf("Bienvenido");

        //------------Producto 1------------------------
        printf( "\n\n   1. Para comprar el producto: ");
         if(obtenerElementoPila(p1)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p1));
        mostrarProducto(produc);

            }
        //------------Producto 2------------------------
        printf( "\n\n   2. Para comprar el producto: ");

             if(obtenerElementoPila(p2)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p2));
        mostrarProducto(produc);

            }

        //------------Producto 3------------------------
        printf( "\n\n   3. Para comprar el producto: ");
             if(obtenerElementoPila(p3)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p3));
        mostrarProducto(produc);

            }

        //------------Producto 4------------------------
        printf( "\n\n   4. Para comprar el producto: ");
         if(obtenerElementoPila(p4)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p4));
        mostrarProducto(produc);

            }



        printf( "\n\n   5. Volver." );
        printf( "\n\n   Introduzca opci%cn (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                    if(obtenerElementoPila(p1)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p1));
                        apilar(carrito,&produc);
                        desapilar(p1);
                        }
                    break;

            case 2:
                    if(obtenerElementoPila(p2)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p2));
                        apilar(carrito,&produc);
                        desapilar(p2);
                        }

                    break;

            case 3:
                    if(obtenerElementoPila(p3)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p3));
                        apilar(carrito,&produc);
                        desapilar(p3);
                        }

                    break;
            case 4:
                    if(obtenerElementoPila(p4)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p4));
                        apilar(carrito,&produc);
                        desapilar(p4);
                        }

                    break;

         }

         /* Fin del anidamiento */

    } while ( opcion != 5 );

}

void menuCarniceria(Pila carrito){

    Pila p1=generadorDeStock("Lomo");
    Pila p2=generadorDeStock("Nalga");
    Pila p3=generadorDeStock("Peceto");
    Pila p4=generadorDeStock("Vacio");

    int n, opcion;

    do
    {
        system("CLS");
        printf("Bienvenido");

        //------------Producto 1------------------------
        printf( "\n\n   1. Para comprar el producto: ");
         if(obtenerElementoPila(p1)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p1));
        mostrarProducto(produc);

            }
        //------------Producto 2------------------------
        printf( "\n\n   2. Para comprar el producto: ");

             if(obtenerElementoPila(p2)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p2));
        mostrarProducto(produc);

            }

        //------------Producto 3------------------------
        printf( "\n\n   3. Para comprar el producto: ");
             if(obtenerElementoPila(p3)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p3));
        mostrarProducto(produc);

            }

        //------------Producto 4------------------------
        printf( "\n\n   4. Para comprar el producto: ");
         if(obtenerElementoPila(p4)==NULL){
        printf("\nAGOTADO\n");
            }else{
        Producto produc= *((Producto*)obtenerElementoPila(p4));
        mostrarProducto(produc);

            }



        printf( "\n\n   5. Volver." );
        printf( "\n\n   Introduzca opci%cn (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                    if(obtenerElementoPila(p1)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p1));
                        apilar(carrito,&produc);
                        desapilar(p1);
                        }
                    break;

            case 2:
                    if(obtenerElementoPila(p2)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p2));
                        apilar(carrito,&produc);
                        desapilar(p2);
                        }

                    break;

            case 3:
                    if(obtenerElementoPila(p3)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p3));
                        apilar(carrito,&produc);
                        desapilar(p3);
                        }

                    break;
            case 4:
                    if(obtenerElementoPila(p4)==NULL){
                        system("CLS");
                        printf("\nAGOTADO\n");
                        system("pause");
                    }else{
                        Producto produc= *((Producto*)obtenerElementoPila(p4));
                        apilar(carrito,&produc);
                        desapilar(p4);
                        }

                    break;

         }

         /* Fin del anidamiento */

    } while ( opcion != 5 );

}

void pagar(Pila carrito,Cliente cli){

    Cola colaDeClientes= generarCola();
    encolar(colaDeClientes,&cli);
    int bandera=0;

    while(bandera==0){
        system("CLS");
        if(getTamanioCola(colaDeClientes)==0){
        bandera=1;
        }

        printf("\nUsted tiene %d personas adelante\n",getTamanioCola(colaDeClientes));
        mostrarColaClientes(colaDeClientes);
        desencolar(colaDeClientes);
        system("pause");


}
system("CLS");
printf("Es Su turno");
mostrarCliente(cli);
printf("\n\nUsted lleva:\n");
int monto=0;
int bandera2=0;
while(bandera2==0){

    if(obtenerElementoPila(carrito)==NULL){
        printf("\nFin de La Lista de su carrito\n");

        printf("\n Total a pagar: %d\n",monto);
        system("pause");
        bandera2=1;

    }else{
        Producto produc= *((Producto*)obtenerElementoPila(carrito));
        mostrarProducto(produc);
        monto= monto + getPrecio(produc);
        desapilar(carrito);

    }


}



}


//---------------------------Generadores de Stock-------------------------------
Pila generadorDeStock(char nombreProducto[20]){


    Pila pilaDeRetorno= crearPila(sizeof(Producto));
    Lista ls= crearLista(sizeof(Producto));
    int numero=10; //Variable donde se guardara nuestro numero aleatorio
    Producto pr;

    for(int i =0; i<10 ; i++){


        //srand(time(NULL)); //Generamos numero aleatorio en base al tiempo
        //numero=rand() % 21 + 20;
        numero++;
        pr= crearProducto(nombreProducto,100,numero);
        insertarInicio(ls,&pr);

        //numero=0;


    }


    pilaDeRetorno= ordenarYapilar(ls);


    return pilaDeRetorno;

};

Pila ordenarYapilar(Lista ls){

Pila pilaARetornar= crearPila(sizeof(Cliente));
Producto pr1;
Producto pr2;
Producto ultimoMaximo;
Producto masGrande;
Producto cambio;
int contador=1;

if(obtenerTamanio(ls)==0){
    return NULL;
}


 for (int indiceActual = 0; indiceActual < obtenerTamanio(ls); indiceActual++) {
    // Recuerda que el -1 es porque no queremos llegar al final ya que hacemos
    // un indiceActual + 1 y si fuéramos hasta el final, intentaríamos acceder a un valor fuera de los límites
    // del arreglo
    pr1=*((Producto*)obtenerDato(ls,indiceActual));
    masGrande=pr1;
    for (int segundoBucle = 0; segundoBucle < obtenerTamanio(ls) - 1;segundoBucle++) {
            if(indiceActual==0){
                    pr2=*((Producto*)obtenerDato(ls,segundoBucle+1));

                if (getDiasAVencer(masGrande) <= getDiasAVencer(pr2)) {
                    masGrande=pr2;
                    if(getDiasAVencer(masGrande) == getDiasAVencer(pr2)){
                            contador++;
                    }else{contador=1;}

      }
    }
    else{
         pr2=*((Producto*)obtenerDato(ls,segundoBucle));

         if(getDiasAVencer(masGrande) <= getDiasAVencer(pr2) && getDiasAVencer(pr2)< getDiasAVencer(ultimoMaximo)){
         masGrande=pr2;
            if(getDiasAVencer(masGrande) == getDiasAVencer(pr2)){
                contador++;
            }else{contador=1;}


    }
    }
    }



    for(int i=0;i<contador;i++){
        apilar(pilaARetornar,&masGrande);
    }
    contador=0;
    ultimoMaximo=masGrande;

 }


return pilaARetornar;

};

Cola generarCola(){


    Cola colaDeClientes= crearCola(sizeof(Cliente));
    Cliente aux;
    char nombre [20]= "Cliente";
    char apellido [20]="------";
    char nom [20]="------";
    char us [20]="------";

    for(int i=0;i<10;i++){
        aux= crearCliente(nombre,apellido,nom,us);
        encolar(colaDeClientes,&aux);

    }

return colaDeClientes;

}
