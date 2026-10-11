#include <bits/stdc++.h>
#include "DJS.h"
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    opIO
    int n, h, frats = 0, alones = 0;
    cin >> n >> h;
    UnionFind uf(n);
    while(h--){
        int i, j;
        cin >> i >> j;
        uf.unionSet(i, j);
    }
    for(int i = 1; i <= n; i++){
        if(uf.getP(i) == i) uf.getSize(i) == 1 ? alones++ : frats++;
    }
    cout << frats << " " << alones << "\n";
    return 0;
}