#include <iostream>
using namespace std;

long long int penta(long long int n) {
    return n*(3*n-1)/2;
}

long long int bb(long long int n, long long int inicio, long long int final){
    while (inicio <= final) {
        long long int medio = (inicio + final) / 2;
        long long int pentaMed = penta(medio);

        if (pentaMed == n) return pentaMed;
        if (pentaMed < n) inicio = medio + 1;
        else {final = medio - 1;}
    }
    long long int pentaIni = penta(inicio);
    long long int pentaFin = penta(final);

    if (abs(pentaIni - n) < abs(pentaFin - n)) return pentaIni;
    return pentaFin;
}

int main(){
    int T;
    long long int C;
    cin >> T;
    while(T--){
        cin >> C;
        cout << bb(C,1,C) << endl;
    }
    return 0;
}