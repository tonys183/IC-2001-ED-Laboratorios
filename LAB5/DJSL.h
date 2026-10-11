#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class UnionFindL {
private: 
    vector<ll> p, rank, size;
    int djs;

public:
    UnionFindL(int n);
    UnionFindL() = default;
    ll find(ll i);
    bool inSameSet(ll i, ll j);
    void unionSet(ll i, ll j);
    int getDJS();
};

UnionFindL::UnionFindL(int n){
    rank.assign(n+1, 0);
    p.assign(n+1, 0);
    size.assign(n+1, 1);
    djs = n;
    
    for(ll i = 0; i < n+1; i++) p[i] = i;
}

ll UnionFindL::find(ll i){
    return (p[i] == i) ? i : (p[i] = find(p[i]));
}

bool UnionFindL::inSameSet(ll i, ll j){
    return find(i) == find(j);
}

void UnionFindL::unionSet(ll i, ll j){
    if(!inSameSet(i, j)){
        djs--;
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

int UnionFindL::getDJS(){ return djs; }