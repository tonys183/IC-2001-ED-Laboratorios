#include <bits/stdc++.h>
#include "TRIE30.h"
#define opES ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int countBits(int mask) {
    int count = 0;
    while (mask > 0) {
        mask = mask & (mask-1);
        count++;
    }
    return count;
}

int main() {
    opES
    Trie trie; int T, P, R, C, N, profsID; string profs;
    cin >> T;
    while (T--) {
        trie.clear();
        cin >> P >> R;
        for (int i = 0; i < P; i++) {
            cin >> C; profsID = i;
            for (int j = 0; j < C; j++) {
                cin >> profs; trie.insert(profs, profsID);
            }
        }
        vector<int> results(R, 0);
        for (int i = 0; i < R; i++) {
            int seenMask = 0;
            cin >> N;
            for (int j = 0; j < N; j++) {
                cin >> profs;
                int mask = trie.getMask(profs);
                if (trie.esPot2(profs)) seenMask |= mask;
            }
            cout << countBits(seenMask) << endl;
        }
    }
    return 0;
}