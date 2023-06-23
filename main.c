#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include "Pila.h"
#include "Cliente.h"
#include "Menu.h"
#include "Lista.h"
#include "Producto.h"


int main()
{




    Cliente cli=crearCliente("Ignacio","Cruz","Usuario","usuario");
    Lista ls= crearLista(sizeof(Cliente));
    Lista l= crearLista(sizeof(Cliente));
    insertarInicio(l,&cli);

    iniciaPrograma(l);





    return 0;
}
