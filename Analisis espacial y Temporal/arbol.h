
#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
using namespace std;

typedef struct nodo {
    int nro; // 4 bytes.

    struct nodo *izq, *der;
    // Aunque se menciona nuevamente struct nodo,
    // aquí no se están creando dos Nodos adicionales.
    // izq y der son apuntadores que almacenan
    // direcciones de memoria de otros Nodos.
    // Según nuestra metodología, los apuntadores
    // no se contabilizan.

} *ABB;


class arbol
{
    public:
        arbol();
        ABB getraiz();
        ABB crearNodo(int);
        void insertar(ABB &, int);
        ABB unirABB(ABB, ABB);
        void elimina(ABB &, int);

    private:
        ABB raiz;
    
    // ABB es un apuntador a un Nodo.
    // De momento no se ha creado ningún Nodo,
    // únicamente se ha declarado el apuntador raiz.
    // No se contabiliza gasto según la metodología utilizada.
};

#endif // !ARBOL_H


