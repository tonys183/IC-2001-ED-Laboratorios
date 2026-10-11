#include <iostream>
#include "CDLL.h"
#include "DLL.h"
#include "SLL.h"

using namespace std;

void menuCDLL();
void menuDLL();
void menuSLL();

int main() {
    int choice;
    do {
        cout << "Tipo de lista:" << endl;
        cout << "1. Lista Simple (SLL)" << endl;
        cout << "2. Lista Doble (DLL)" << endl;
        cout << "3. Lista Doble Circular (CDLL)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuSLL();
                break;
            case 2:
                menuDLL();
                break;
            case 3:
                menuCDLL();
                break;
            case 0:
                break;
            default:
                cout << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}


void menuSLL() {
    int option;
    SLL<int> lista;
    do {
        cout << "\n--- Menú SLL ---" << endl;
        cout << "1. Longitud" << endl;
        cout << "2. Insertar en una posición" << endl;
        cout << "3. Push" << endl;
        cout << "4. Append" << endl;
        cout << "5. Remove" << endl;
        cout << "6. Mostrar lista" << endl;
        cout << "7. Barajar" << endl;
        cout << "8. Ordenar Rapido" << endl;
        cout << "9. Ordenar Radio" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> option;

        int val, pos;
        switch (option) {
            int asc;
            case 1:
                cout << lista.longitud() << endl;
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> val;
                cout << "Ingrese posición: ";
                cin >> pos;
                lista.insertarPosicion(pos, val);
                break;
            case 3:
                cout << "Ingrese valor: ";
                cin >> val;
                lista.push(val);
                break;
            case 4:
                cout << "Ingrese valor: ";
                cin >> val;
                lista.append(val);
                break;
            case 5:
                cout << "Ingrese posición: ";
                cin >> pos;
                cout << "Elemento eliminado: "<< lista.remove(pos) << endl;
                break;
            case 6:
                lista.mostrar();
                break;  
            case 7:
                lista.barajar();
                break;
            case 8:
                cout << "Ordenar (0: Descendente, 1: Ascendente): ";
                cin >> asc;
                lista.ordenarRapido(asc);
                break;
            case 9:
                cout << "Ordenar (0: Descendente, 1: Ascendente): ";
                cin >> asc;
                lista.ordenarRadix(asc);
                break;
            default:
                cout << endl;
                break;
        }
    } while (option != 0);
}


void menuDLL() {
    int option, numListas=0, indexActual=-1;
    DLL<int>* listas[10];
    DLL<int>* listaActual = nullptr;

    for (int i=0; i<10; ++i) listas[i] = nullptr;
    do {
        cout << "\n--- Menú DLL ---" << endl;
        if (listaActual) {
            cout << "Lista actual: ["<<indexActual<<"]" << endl;
        } else {
            cout << "Lista actual: [None]" << endl;
        }

        cout << "1. Longitud" << endl;
        cout << "2. Insertar en una posición" << endl;
        cout << "3. Push" << endl;
        cout << "4. Append" << endl;
        cout << "5. Remove" << endl;
        cout << "6. Mostrar lista" << endl;
        cout << "7. Concatenar" << endl;
        cout << "8. Max/Min" << endl;
        cout << "9. Ordenar Heap" << endl;
        cout << "10. Agregar nueva lista*" << endl;
        cout << "11. Seleccionar lista*" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> option;

        int val, pos;
        switch (option) {
            int asc;
            case 1:
                if (listaActual) {
                    cout << listaActual->longitud() << endl;
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 2:
                if (listaActual) {
                    cout << "Ingrese valor: ";
                    cin >> val;
                    cout << "Ingrese posición: ";
                    cin >> pos;
                    listaActual->insertarPosicion(pos, val);
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 3:
                if (listaActual) {
                    cout << "Ingrese valor: ";
                    cin >> val;
                    listaActual->push(val);
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 4:
                if (listaActual) {
                    cout << "Ingrese valor: ";
                    cin >> val;
                    listaActual->append(val);
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 5:
                if (listaActual) {
                    cout << "Ingrese posición: ";
                    cin >> pos;
                    cout << "Elemento eliminado: " << listaActual->remove(pos) << endl;
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 6:
                if (listaActual) {
                    listaActual->mostrar();
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 7:
                if (listaActual) {
                    int index2;
                    cout << "Seleccionar lista para concatenar (0-" << numListas - 1 << "): ";
                    cin >> index2;
                    if (index2 >= 0 && index2 < numListas && index2 != indexActual) {
                        listaActual->concatenar(*listas[index2]);
                    } else {
                        cout << "Índice inválido o misma lista." << endl;
                    }
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 8:
                if (listaActual) {
                    cout << "Max/Min (0: Max, 1: Min): ";
                    cin >> asc;
                    if (asc) cout << "Min: " << listaActual->maxmin(asc) << endl;
                    else cout << "Max: " << listaActual->maxmin(asc) << endl;
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 9:
                if (listaActual) {
                    cout << "Ordenar (0: Descendente, 1: Ascendente): ";
                    cin >> asc;
                    listaActual->ordenarHeap(asc);
                } else {
                    cout << "Lista no seleccionada" << endl;
                }
                break;
            case 10:
                listas[numListas] = new DLL<int>(); 
                listaActual = listas[numListas];
                indexActual = numListas;
                numListas++;
                cout << "Nueva lista creada" << endl;
                break;
            case 11:
                if(!numListas){
                    cout << "Sin listas" << endl;
                    break;
                }
                cout << "Seleccionar lista (0 - " << numListas-1 <<"): ";
                int index;
                cin >> index;
                if (index >= 0 && index < numListas) {
                    listaActual = listas[index];
                    indexActual = index;
                    cout << "Lista seleccionada" << endl;
                } else {
                    cout << "Índice inválido." << endl;
                }
                break;
            default:
                cout << endl;
                break;
        }
    } while (option != 0);
    for (int i=0; i<numListas; i++) delete listas[i];
}


void menuCDLL() {
    int option;
    CDLL<int> lista;
    do {
        cout << "\n--- Menú CDLL ---" << endl;
        cout << "1. Longitud" << endl;
        cout << "2. Insertar en una posición" << endl;
        cout << "3. Push" << endl;
        cout << "4. Append" << endl;
        cout << "5. Remove" << endl;
        cout << "6. Mostrar lista" << endl;
        cout << "7. Permutar" << endl;
        cout << "0. Volver" << endl;
        cout << "Opción: ";
        cin >> option;

        int val, pos;
        switch (option) {
            int asc;
            case 1:
                cout << lista.longitud() << endl;
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> val;
                cout << "Ingrese posición: ";
                cin >> pos;
                lista.insertarPosicion(pos, val);
                break;
            case 3:
                cout << "Ingrese valor: ";
                cin >> val;
                lista.push(val);
                break;
            case 4:
                cout << "Ingrese valor: ";
                cin >> val;
                lista.append(val);
                break;
            case 5:
                cout << "Ingrese posición: ";
                cin >> pos;
                cout << "Elemento eliminado: "<< lista.remove(pos) << endl;
                break;
            case 6:
                lista.mostrar();
                break;
            case 7:
                lista.permutar();
                lista.mostrarPermu();
                break;
            default:
                cout << endl;
                break;
        }
    } while (option != 0);
}