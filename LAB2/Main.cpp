#include <iostream>
#include "SET.H"

using namespace std;

int main() {
    int lines;
    cin >> lines;
    string element;
    SET* setActu = nullptr;

    while (lines--) {
        char instrucc;
        cin >> instrucc;
        switch(instrucc){
            case 'E':
                int size;
                if(cin >> size){
                    delete setActu;
                    setActu = new SET(size);
                    break;
                }
                cin.clear();
                delete setActu;
                setActu = new SET();
                break;
                
            case 'i':
                cin >> element;
                if (setActu) {
                    if (setActu->insertar(element)) {
                        cout << "SI insertado" << endl;
                    } else {
                        cout << "NO insertado" << endl;
                    }
                } else {
                    cout << "NO CONJUNTO" << endl;
                }
                break;
            case 'r':
                cin >> element;
                if (setActu) {
                    if (setActu->eliminar(element)) {
                        cout << "SI removido" << endl;
                    } else {
                        cout << "NO removido" << endl;
                    }
                } else {
                    cout << "NO CONJUNTO" << endl;
                }
                break;
            case 'c':
                if (setActu) {
                    cout << setActu->cardinalidad() << endl;
                } else {
                    cout << "NO CONJUNTO" << endl;
                }
                break;
            case 'v':
                if (setActu) {
                    if (setActu->estaVacio()) {
                        cout << "VACIO" << endl;
                    } else {
                        cout << "NO VACIO" << endl;
                    }
                } else {
                    cout << "NO CONJUNTO" << endl;
                }
                break;
            case 't':
                cin >> element;
                if (setActu) {
                    if (setActu->contiene(element)) {
                        cout << "SI ESTA" << endl;
                    } else {
                        cout << "NO ESTA" << endl;
                    }
                } else {
                    cout << "NO CONJUNTO" << endl;
                }
                break;
            case '0':
                return 0;
            default:
                cout << "NO CONJUNTO" << endl;
                break;
        }
    }
    delete setActu;
    return 0;
}