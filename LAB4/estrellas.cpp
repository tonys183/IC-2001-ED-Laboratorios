#include <bits/stdc++.h>
#include "SEGMENT.h"
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

void solve(SegmentTree<int> treeMax, SegmentTree<int> treeMin, int Q, int i, int j, int ni){
    opIO
    while(Q--){
        string consult;
        cin >> consult;
        if (consult == "MAX") {
            if (cin >> i >> j) cout << treeMax.query(i, j) << "\n";
        } else if (consult == "MIN") {
            if (cin >> i >> j) cout << treeMin.query(i, j) << "\n";
        } else if (consult == "UPD") {
            if (cin >> i >> ni) {
                treeMax.update(i, ni);
                treeMin.update(i, ni);
            }
        }
    }
}

int main() {
    opIO
    int N, Q, i, j, ni;
    auto fMax = [](int a, int b) { return max(a, b); };
    auto fMin = [](int a, int b) { return min(a, b); };

    cin >> N >> Q;
    vector<int> ar(N, 0);
    for(int i=0; i<N; i++) cin>>ar[i];
    
    SegmentTree<int> tree_max(ar, fMax, true);
    SegmentTree<int> tree_min(ar, fMin, false);

    solve(tree_max, tree_min, Q, i, j, ni);
    return 0;
}