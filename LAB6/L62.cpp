#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, l, q, INF = 1e9;
int AM[450][450];

void floyd() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) AM[i][j] = INF;
        AM[i][i] = 0;
    }
    for (int k = 0; k < l; ++k) {
        int i, j, t;
        cin >> i >> j >> t;
        AM[i][j] = t;
        AM[j][i] = t;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
}

int main(){
    opIO
    cin >> n >> l >> q;
    floyd();

    for (int k = 0; k < q; ++k) {
        int i, j;
        cin >> i >> j;
        cout << AM[i][j] << "\n";
    }
    return 0;
}