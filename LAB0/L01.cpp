#include <iostream>
using namespace std;

int main(){
    int P, cantEstu, cantNotasTotal[6]={0};
    cin >> P;
    while(P--){
        char notas[6];
        int cantNotas[6]={0};
        cin >> cantEstu;
        for(int i=0; i<cantEstu;i++){
            cin >> notas[i];
            cantNotas[notas[i]-65]++;
            cantNotasTotal[notas[i]-65]++;
            
        }
        cout << "A:" << cantNotas[0] << " B:" << cantNotas[1] << " C:" << cantNotas[2] << " D:" << cantNotas[3] << " E:" << cantNotas[4] << " F:" << cantNotas[5] << endl;
    }
    cout << "TOTAL: A:" << cantNotasTotal[0] << " B:" << cantNotasTotal[1] << " C:" << cantNotasTotal[2] << " D:" << cantNotasTotal[3] << " E:" << cantNotasTotal[4] << " F:" << cantNotasTotal[5] << endl;
    return 0;
}