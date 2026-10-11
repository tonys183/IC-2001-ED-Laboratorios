#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef long long int ll;

const int MAX = 5042;
int dp[MAX];
int countt = 0;
vvi posIni(3, vi(3));
vvi posFin(3, vi(3));
bitset<MAX> visi;
vector<pair<int, int>> G[MAX];
unordered_map<ll, vvi> allIndex; 
unordered_map<ll, int> idM; 

int esValido(int x, int y){ return x >= 0 && x < 3 && y >= 0 && y < 3; }

ll asigPos(const vvi& m) {
    ll pos = 0, temp = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pos += (m[i][j] + 1) * temp; temp *= 31;  
        }
    }
    return pos%1000000007;
}

int indexM(const vvi& m) {
    ll indPos = asigPos(m);

    if (allIndex.find(indPos) != allIndex.end()) {
        if (allIndex[indPos] == m) return idM[indPos];  
        else {
            indPos = (asigPos(m) * 101)%1000000007; 
            if (allIndex.find(indPos) != allIndex.end() && allIndex[indPos] == m) return idM[indPos];
        }
    }
    allIndex[indPos] = m;
    idM[indPos] = countt++;
    return idM[indPos];
}

void allPermu(const vpii& dirs, queue<vvi>& q){
    while (!q.empty()) {
        auto actu = q.front(); q.pop();
        int indiActu = indexM(actu);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (actu[i][j] == -1) continue;
                for (auto dir : dirs) {
                    int ni = i + dir.first; int nj = j + dir.second;
                    if (esValido(ni, nj) && actu[ni][nj] != -1) {
                        swap(actu[i][j], actu[ni][nj]);
                        int newpos = indexM(actu);
                        if (!visi[newpos]) {
                            visi[newpos] = 1; q.push(actu);
                        }
                        G[indiActu].push_back({newpos, actu[i][j] + actu[ni][nj]});
                        swap(actu[i][j], actu[ni][nj]);
                    }
                }
            }
        }
    }
}

void crearGrafito(vvi posIni, ll st) {
    vpii dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<vvi> q; 
    q.push(posIni);
    visi[st] = 1;
    allPermu(dirs, q);
}

void Dijkstra(int st, int end){
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int>> pq;
    dp[st] = 0; pq.push({0, st});
    while(!pq.empty()){
        st = pq.top().second; int w = -pq.top().first; pq.pop();
        if(st == end) break;
        if(dp[st] != w) continue;
        for(auto &p : G[st]){
            int nxt = p.first; int w = p.second;
            if(dp[nxt] < 0 || dp[st] + w < dp[nxt])
                dp[nxt] = dp[st]+w, pq.emplace(-dp[nxt], nxt);
        }
    }
}

int main(){
    opIO
    ll st = 0, end = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if ((i == 0 && j == 0) || (i == 2 && j == 2)) posIni[i][j] = -1;
            else cin >> posIni[i][j];
    st = indexM(posIni);
    crearGrafito(posIni, st);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if ((i == 0 && j == 0) || (i == 2 && j == 2)) posFin[i][j] = -1;
            else cin >> posFin[i][j];
    end = indexM(posFin);
    Dijkstra(st, end);
    cout << dp[end] << "\n";
    return 0;
}
