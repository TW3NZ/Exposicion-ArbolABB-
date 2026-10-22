
#include "arbol.h"

void menu();

int main()
{
    arbol arbolABB;
    // Objeto de la clase arbol.
    // Solo contiene el apuntador raiz.
    // No se contabiliza según nuestra metodología.

    ABB raizABB;
    // Apuntador a Nodo, no se contabiliza.

    raizABB = arbolABB.getraiz();
    // Devuelve el apuntador raiz.
    // No crea ningún Nodo ni agrega memoria contabilizada.

    int x;   // 4 bytes.
    char r;  // 1 byte.
    int op;  // 4 bytes.

    // Gasto base = 4 + 1 + 4 = 9 bytes.
    
    do // do while no consume
    {
        menu(); // 5 bytes temporales.

                // 9 + 5 = 14 bytes.
                // Al finalizar menu(), se liberan los 5 bytes.
                // Quedan 9 bytes.

                cin >> op;
                // No agrega memoria según nuestro conteo.

                cout << endl; // 1 byte temporal.
                // 9 + 1 = 10 bytes.

     switch(op){
             
                // Al finalizar cout, se libera su byte temporal.
                // Quedan los 9 bytes base.

        case 1:
            do
            {
                cout << "\nIngrese valor : "; // 1 byte temporal.
                
                // 9 + 4n + 1 = 10 + 4n bytes. // 4n porque no sabemos si hay un nodo creado antes
                
                // Al finalizar cout, se libera 1 byte.

                cin >> x;
                // x ya fue declarada en main.
                // No se contabiliza nuevamente.

                arbolABB.insertar(raizABB, x);

                // n = cantidad de Nodos existentes antes de insertar.
                // k = cantidad de llamadas activas a insertar.

                // 9 bytes base + 4n bytes de Nodos existentes
                // + 4k bytes de insertar + 4 bytes de crearNodo
                // + 4 bytes del nuevo Nodo.
 
                // Gasto máximo = 17 + 4n + 4k bytes. teniendo en cuenta los parametros por valor

                // Al finalizar insertar, se liberan los
                // parámetros temporales y permanece el nuevo Nodo.

                // Gasto restante = 9 + 4n + 4 = 13 + 4n bytes.

                cout << "¿Continuar?(s/n)... "; // 1 byte temporal.

                // 9 + 4n + 4 + 1 = 14 + 4n bytes.
                // Al finalizar cout, se libera 1 byte.

                cin >> r;
                // r ya fue declarada en main.
                // No agrega memoria.

            }while(r == 's');

            break;

        /*
        CONCLUSIÓN ESPACIAL DEL CASE 1:

        n = Nodos existentes antes de insertar.
        k = llamadas recursivas activas.

        Gasto mínimo = 9 + 4n bytes.
        Gasto máximo = 17 + 4n + 4k bytes.

        Después de una inserción exitosa permanecen:
        9 + 4n + 4 bytes.

        Los parámetros temporales se liberan al
        finalizar la inserción.
        */

            
        case 2:
            if(raizABB != NULL)
            {
                cout << "Valor a eliminar: "; // 1 byte temporal.
                // 9 + 4n + 1 = 10 + 4n bytes.
                // Al finalizar cout, se libera 1 byte.

                cin >> x;
                // x ya fue declarada en main.
                // No se contabiliza nuevamente.

                arbolABB.elimina(raizABB, x);

                // k = cantidad de llamadas recursivas activas.
                // Cada llamada agrega 4 bytes temporales por x.

                // 9 bytes base + 4n bytes de Nodos existentes
                // + 4k bytes temporales de elimina.

                // Gasto máximo = 9 + 4n + 4k bytes.

                // Si encuentra el Nodo, delete libera 4 bytes.
                // Al finalizar elimina, se liberan los 4k bytes.
                // Gasto restante = 9 + 4n - 4 = 5 + 4n bytes.

                cout << "\n\tOperacion de eliminacion realizada..!";
                // 1 byte temporal.
                // Si se eliminó el Nodo: 6 + 4n bytes.
                // Al finalizar cout, queda 5 + 4n bytes.
            }
            else
            {
                cout << "\n\tArbol vacio..!"; // 1 byte temporal.
                // 9 + 1 = 10 bytes.
                // Al finalizar cout, quedan 9 bytes.
            }

            break;

        /*
        CONCLUSIÓN ESPACIAL DEL CASE 2:

        n = cantidad de Nodos antes de eliminar.
        k = cantidad de llamadas activas a elimina.

        Gasto base = 9 + 4n bytes.
        Gasto máximo = 9 + 4n + 4k bytes.

        Si la eliminación es exitosa:
        Gasto permanente final = 5 + 4n bytes.

        Si no encuentra el valor, no se libera ningún Nodo.
        */

            case 3:
                break;

            default:
                cout << "\n\tOpcion no valida..!"; // 1 byte temporal
        }

    }while(op != 3);

    return 0;
}

void menu()
{
    cout << "\n\n\t\t ..[ ARBOL BINARIO DE BUSQUEDA ]..\n\n";
    cout << "\t [1] Insertar elemento\n";
    cout << "\t [2] Eliminar elemento\n";
    cout << "\t [3] SALIR\n";
    cout << "\n\t Ingrese opcion : ";
}



    /*


    n = cantidad de Nodos existentes antes de la operación.
    k = cantidad de llamadas recursivas activas.

    Gasto base del main = 9 bytes.
    Cada Nodo creado ocupa 4 bytes.

    CASO 1: INSERCIÓN

    Gasto mínimo = 9 + 4n bytes.
    Gasto máximo = 17 + 4n + 4k bytes.

    Después de insertar exitosamente:
    Gasto restante = 13 + 4n bytes.


    CASO 2: ELIMINACIÓN

    Gasto mínimo = 9 + 4n bytes.
    Gasto máximo = 9 + 4n + 4k bytes.

    Después de eliminar exitosamente:
    Gasto restante = 5 + 4n bytes.

    Si el árbol está vacío:
    Gasto máximo = 10 bytes.


    CASO 3: SALIR

    Gasto = 9 + 4n bytes.
    No agrega memoria adicional.


    DEFAULT: OPCIÓN NO VÁLIDA

    Gasto mínimo = 9 + 4n bytes.
    Gasto máximo = 10 + 4n bytes.

    El byte adicional de cout es temporal.


    CONCLUSIÓN FINAL:

    El mayor gasto espacial se presenta durante
    la inserción de un nuevo Nodo:

      17 + 4n + 4k bytes.
     
    */
