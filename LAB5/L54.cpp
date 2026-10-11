#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
using namespace std;

vvi grafito;
vi dista;

pair<int, int> bfs(int first, int a) {
    queue<int> q;
    dista.assign(a, -1);
    q.push(first);
    dista[first] = 0;
    int far = first;

    while (!q.empty()) {
        int nodo = q.front(); q.pop();
        for (int veci : grafito[nodo]) {
            if (dista[veci] == -1) {
                dista[veci] = dista[nodo]+1;
                q.push(veci);
                if (dista[veci] > dista[far]) far = veci;
            }
        }
    }
    return {far, dista[far]};
}

int main() {
    opIO
    int a, c;
    cin >> a >> c;
    grafito.resize(a+1);
    while(c--){
        int i, j;
        cin >> i >> j;
        grafito[i].push_back(j);
        grafito[j].push_back(i);
    }
    int maxi = 0;
    for(int i=0; i<a; i++) maxi = max(maxi, bfs(i, a).second);
    cout << maxi << "\n";
    return 0;
}
