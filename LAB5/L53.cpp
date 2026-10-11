#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
using namespace std;

int maxi=0;
vi visi;
vvi grafito, levels;

void solve(int nodo, int level){
    queue<pair<int, int>> q;
    q.push({nodo, level});
    visi[nodo] = 1;

    while(!q.empty()){
        pair<int, int> a = q.front();
        q.pop();
        int nodoT = a.first;
        int levelT = a.second;
        maxi = max(maxi, levelT);

        for(int v : grafito[nodoT]){
            if(!visi[v]){
                visi[v] = 1;
                levels[levelT + 1].push_back(v);
                q.push({v, levelT + 1});
            }
        }
    }
}

int main() {
    opIO
    int a, c, k;
    cin >> a >> c >> k;
    grafito.resize(a+1);
    visi.resize(a+1, 0);
    levels.resize(a+1);
    while(c--){
        int i, j;
        cin >> i >> j;
        grafito[i].push_back(j);
        grafito[j].push_back(i);
    }
    solve(k, 0);
    for(int i = 0; i < a; i++) if(!visi[i]) levels[0].push_back(i);
    for(int i = 0; i <= maxi; i++){
        cout << i << ": ";
        for(int j = 0; j < levels[i].size(); j++) cout << levels[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
