#include <iostream>
#include "TRIE31.h"
#define opES ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    opES
    int T;
    Trie trie;
    cin >> T;
    while(T--){
        string numeros;
        cin >> numeros;
        trie.insert(numeros);
    }
    cout << trie.countPfix() << endl;
    return 0;
}