#include <bits/stdc++.h>
#include "DJSL.h"
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
typedef std::vector<string> vs;
typedef std::vector<int> vi;
using namespace std;

vs fig;
vi posI, posJ;
UnionFindL ufUp, ufRight, ufDown, ufLeft;
int up=0, rightt=0, down=0, leftt=0, l, m;

void countPnts() {
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= m; j++) {
            if (fig[i][j] == '#') {
                posI.push_back(i);
                posJ.push_back(j);
                if (fig[i-1][j] == '.') up++;
                if (fig[i][j+1] == '.') rightt++;
                if (fig[i+1][j] == '.') down++;
                if (fig[i][j-1] == '.') leftt++;
            }
        }
    }
}

void solve() {
    int tempU=0, tempD=0, tempR=0, tempL=0;
    for (int k=0; k<posI.size(); k++) {
        int i = posI[k], j = posJ[k];
        if (fig[i+1][j] == '.') {
            tempU++;
            if (fig[i+1][j-1] == '.' && fig[i][j-1] == '#') ufUp.unionSet(tempU, tempU-1);
        }
        if (fig[i-1][j] == '.') {
            tempD++;
            if (fig[i-1][j-1] == '.' && fig[i][j-1] == '#') ufDown.unionSet(tempD, tempD-1);
        }
        if (fig[i][j+1] == '.') {
            tempR++;
            if (fig[i-1][j+1] == '.' && fig[i-1][j] == '#') ufRight.unionSet(tempR, tempR-1);
        }
        if (fig[i][j-1] == '.') {
            tempL++;
            if (fig[i-1][j-1] == '.' && fig[i-1][j] == '#') ufLeft.unionSet(tempL, tempL-1);
        }
    }
}

int main() {
    opIO
    cin >> l >> m;
    fig.resize(l+2, string(m+2, '.'));
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= m; j++) cin >> fig[i][j];
    }
    countPnts();
    ufUp = UnionFindL(up); ufRight = UnionFindL(rightt); ufDown = UnionFindL(down); ufLeft = UnionFindL(leftt);
    solve();
    cout << ufUp.getDJS() + ufRight.getDJS() + ufDown.getDJS() + ufLeft.getDJS() << "\n";
    return 0;
}
