#include <iostream>
using namespace std;

int esValido(int i, int j, int F, int C){
     return i >= 0 && i < F && j >= 0 && j < C;
}

int main(){
    int F,C,P,pI,pJ,total=0;
    cin >> F >> C >> P;
    int mat[F][C];
    for(int i=0; i<F;i++){
        for(int j=0; j<C; j++){
          cin >> mat[i][j];
        }
    }
    while(P--){
        cin >> pI >> pJ;
        for(int i=-1;i<=1;i++){
            for(int j=-1; j<=1;j++){
                if(esValido(pI+i, pJ+j,F,C) && mat[pI+i][pJ+j]){
				    total++;
                    mat[pI+i][pJ+j] = 0;
                }
            }
        }
    }
    cout << total << endl;
    return 0;
}