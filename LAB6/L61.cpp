#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int a, c, costo = 0, contVerti = 0;
vi visi;
vector<vp> AL;
priority_queue<pii> pq;

void adyacentes(int x) {
    visi[x] = 1;
    for (auto &[i, j] : AL[x])
        if (!visi[i]) pq.push({-j, -i});
}

void prim(){
    visi.assign(a+1, 0);
    adyacentes(1);
    while (!pq.empty()) {
        auto [i, j] = pq.top(); pq.pop();
        i = -i; j = -j;
        if (visi[j]) continue;
        costo += i;
        adyacentes(j);
        contVerti++;
        if (contVerti == a-1) break;
    }
}

int main() {
    opIO
    cin >> a >> c;
    AL.assign(a+1, vp());

    for(int i = 0; i < c; i++){
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }
    prim();
    cout << costo << "\n";
    return 0;
}