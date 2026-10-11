#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

bitset<18> grafito[18];
bitset<18> visi;

int solve(int n, int nodo, int &maxi, int centas, bitset<18> visi) {
    visi.set(nodo);
    maxi = max(maxi, centas);
    
    for (int i = 0; i < n; i++) {
        if (grafito[nodo][i] && !visi[i]) {
            solve(n, i, maxi, centas + 1, visi);
        }
    }
    return maxi;
}

int main() {
    opIO
    int n, c, maxi = 0;
    cin >> n >> c;

    for (int i = 0; i < c; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        grafito[a][b] = grafito[b][a] = 1;
    }
    for (int i = 0; i < n; i++) {
        visi.reset();
        solve(n, i, maxi, 1, visi);
    }
    cout << maxi << "\n";
    return 0;
}
