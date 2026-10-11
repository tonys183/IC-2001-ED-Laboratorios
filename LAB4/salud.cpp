#include <bits/stdc++.h>
#define opIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
    opIO
    int prdad;
    string name;
    int ordn = 0;
    priority_queue<tuple<int, int, string>> pq;
    while(cin >> name){
        if(name == "V") {
            if(!pq.empty()){
                cout << get<2>(pq.top()) << "\n";
                pq.pop();
            } else cout << "\n";
        } else {
            cin >> prdad;
            pq.push(make_tuple(prdad, -ordn, name));
            ordn++;
        }
    }
    return 0;
}
