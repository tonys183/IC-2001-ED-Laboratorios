#include <bits/stdc++.h>
#include "FENWICK.h"
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {
    opIO
    int N, Q, i, j;
    cin >> N >> Q;
    vector<unsigned long long int> ar(N+1, 0);
    for(int i=1; i<=N; i++) cin>>ar[i];
    FenwickTree<unsigned long long int> fenTree(ar);
    while(Q--){
        char consult;
        cin >> consult;
        switch(consult){
            case 'q':
                if(cin >> i >> j){
                    cout << fenTree.query(i, j) << "\n";
                    break;
                }
                cin.clear();
                break;
            case 'u':
                if(cin >> i >> j){
                    fenTree.apply(i, j);
                    break;
                }
                cin.clear();
                break;
            default:
                break;
        }
    }
    return 0;
}
