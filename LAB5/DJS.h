#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class UnionFind {
private: 
    vector<ll> p, rank, size;

public:
    UnionFind(int n);
    ll find(ll i);
    bool inSameSet(ll i, ll j);
    void unionSet(ll i, ll j);
    int getP(int x);
    int getSize(int x);
};

UnionFind::UnionFind(int n){
    rank.assign(n+1, 0);
    p.assign(n+1, 0);
    size.assign(n+1, 1);
    
    for(ll i = 1; i <= n; i++) p[i] = i;
}

ll UnionFind::find(ll i){
    return (p[i] == i) ? i : (p[i] = find(p[i]));
}

bool UnionFind::inSameSet(ll i, ll j){
    return find(i) == find(j);
}

void UnionFind::unionSet(ll i, ll j){
    if(!inSameSet(i, j)){
        ll x = find(i), y = find(j);
        if(rank[x] > rank[y] ) {
            p[y] = x;
            size[x] += size[y];
            size[y] = size[x];
        }
        else{
            p[x] = y;
            size[y] += size[x];
            size[x] = size[y];
            if(rank[x] == rank[y]) rank[y] ++;
        }
    }
}

int UnionFind::getP(int x){ return p[x]; }
int UnionFind::getSize(int x){ return size[x]; }