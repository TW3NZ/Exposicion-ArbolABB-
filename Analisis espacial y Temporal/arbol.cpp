
#include "arbol.h"

// CONSTRUCTOR

arbol::arbol()
{
    raiz = NULL;
    // raiz es un apuntador.
    // NULL indica que el árbol está vacío.
    // No se crea ningún Nodo.
    // Gasto contabilizado = 0 bytes.
}


// OBTENER RAÍZ

ABB arbol::getraiz()
{
    return raiz;
    // Se devuelve el apuntador existente.
    // No se crea ningún Nodo ni variable adicional.
    // Gasto contabilizado = 0 bytes.
}


// CREAR NODO
ABB arbol::crearNodo(int x)
{
    // x se pasa por valor = 4 bytes temporales.

    ABB nuevoNodo = new(struct nodo);
    // nuevoNodo es un apuntador, no se contabiliza.
    // new crea un Nodo que contiene int nro = 4 bytes.
    // Estos 4 bytes permanecen después de la función.

    nuevoNodo->nro = x;
    // Se asigna x al atributo nro.
    // No se reserva memoria adicional.

    nuevoNodo->izq = NULL;
    // Se inicializa el apuntador izquierdo.
    // No se crea ningún Nodo adicional.

    nuevoNodo->der = NULL;
    // Se inicializa el apuntador derecho.
    // No se crea ningún Nodo adicional.

    return nuevoNodo;
    // Se devuelve el apuntador al Nodo creado.
    // Al finalizar, desaparecen los 4 bytes temporales de x.
}

/*
 
   Metodo crearNodo :
 
   Gasto maximo del metodo seria 8 bytes pero al crear el nodo
   Se liberan los 4 bytes temporales de x. Permanece el Nodo creado de 4 bytes.


 */

// INSERCIÓN
void arbol::insertar(ABB &arbolabb, int x)

// ABB &arbolabb no consume , int x por valor 4 bytes

{
    if(arbolabb == NULL)
    {
        arbolabb = crearNodo(x);
        
        // 4 bytes (x de insertar) + 4 bytes (x de crearNodo)
        // + 4 bytes (Nodo creado) = 12 bytes de gasto máximo.

        // Al finalizar crearNodo se liberan 4 bytes temporales.
        // Quedan 8 bytes.

        cout << "\n\t Insertado..!" << endl << endl; // 1 byte
        
        // 8 bytes + 1 byte = 9 bytes
    }
  
    else if(x < arbolabb->nro)
        insertar(arbolabb->izq, x);
        // Nueva llamada recursiva = 4 bytes por x.

    else if(x > arbolabb->nro)
        insertar(arbolabb->der, x);
        // Nueva llamada recursiva = 4 bytes por x.
}

/*

Como no sabemos cuántas llamadas recursivas serán
necesarias para insertar el Nodo, utilizamos k
para representar la cantidad de llamadas activas.

Cada llamada ocupa 4 bytes por el parámetro x.

Gasto de las llamadas = 4k bytes.

Al llegar a crearNodo:
4k + 4 bytes (x de crearNodo)
   + 4 bytes (Nodo creado)

Gasto máximo adicional = [4k + 8 bytes].

Al finalizar las funciones, se libera la memoria
temporal y permanecen los 4 bytes del Nodo creado.
*/


// UNIR SUBÁRBOLES
ABB arbol::unirABB(ABB izq, ABB der)
{


    if(izq == NULL)
        return der; // Retorna un apuntador existente.

    if(der == NULL)
        return izq; // Retorna un apuntador existente.

    ABB centro = unirABB(izq->der, der->izq);
 

    izq->der = centro;

    der->izq = izq;


    return der;
}

/*

ABB izq = no se contabiliza.
ABB der = no se contabiliza.
ABB centro = no se contabiliza.

Aunque existe recursividad, no necesitamos
utilizar k en nuestro conteo, puesto que
cada llamada recibe únicamente apuntadores.

No se crean nuevos Nodos ni variables
de tipos que estemos contabilizando.

Gasto adicional contabilizado = 0 bytes.
*/




// ELIMINACIÓN

void arbol::elimina(ABB &arbolabb, int x)
{
    // ABB &arbolabb es una referencia, no se contabiliza.
    // int x por valor = 4 bytes temporales.

    if(arbolabb == NULL) return;

    if(x < arbolabb->nro)
        elimina(arbolabb->izq, x);
        // Cada llamada recursiva agrega 4 bytes por x.

    else if(x > arbolabb->nro)
        elimina(arbolabb->der, x);
        // Cada llamada recursiva agrega 4 bytes por x.

    else
    {
        ABB p = arbolabb;
        // p es un apuntador, no se contabiliza.

        arbolabb = unirABB(
            arbolabb->izq,
            arbolabb->der
        );
        // unirABB recibe apuntadores.
        // Gasto adicional contabilizado = 0 bytes.

        delete p;
        // Libera los 4 bytes permanentes del Nodo eliminado.
    }
}

/*


k representa las llamadas recursivas activas.
Cada llamada consume 4 bytes por x.

Gasto temporal máximo = 4k bytes.

ABB p y unirABB no se contabilizan.
delete p libera 4 bytes del Nodo eliminado.

Al finalizar, se liberan los 4k bytes temporales.
*/


