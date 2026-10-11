#include <bits/stdc++.h>
#include "TRIE32.h"
#define opES ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
    opES
    Trie trie;
    string word, lng;
    int bigger=0, N;
    cin >> N;
    while(N--){
        cin >> word;
		trie.insert(word,0);
		if(word.size() > bigger ){
			bigger = word.size();
			lng = word;
		}
    }  
	trie.insert(lng,1);

    string ans;
    trie.imprenta(ans);
    cout << ans.size() << "\n";
    for(char c: ans) cout << c << "\n";

    return 0;
}