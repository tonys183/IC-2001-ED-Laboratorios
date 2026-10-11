#include <iostream>
#include "SET.H"

using namespace std;

int main() {
    int C, N, M;
    string palabra;
    cin >> C;
    while(C--){
        cin >> N >> M;
        SET* conjunto = new SET();
        SET* conjunto2 = new SET();

        SET temp;
        for(int i=0; i<N; i++){
            cin >> palabra;
            if(!temp.contiene(palabra)) {
                conjunto->insertar(palabra);
                temp.insertar(palabra);
            } else {
                conjunto->eliminar(palabra);
            }
        }
        temp.mkClean();
        for(int i=0; i<M; i++){
            cin >> palabra;
            if(!temp.contiene(palabra)) {
                conjunto2->insertar(palabra);
                temp.insertar(palabra);
            } else {
                conjunto->eliminar(palabra);
            }
        }

        SET diferencia = conjunto->getDiferencia(conjunto2);
        SLL<string> listaDiferencia = diferencia.elementos();
        if(listaDiferencia.longitud()){
            listaDiferencia.ordenarRapido(1);
            listaDiferencia.mostrar();
        }
        else cout << "-1" << endl;
    }
    return 0;
}