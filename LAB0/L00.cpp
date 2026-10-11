#include <iostream>
using namespace std;

long long int suma(long long int n){
    return (((n*(n+1))%1000000007)*500000004)%1000000007;
}

int main(){
    int T;
    long long int n, m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        cout << (suma(n)%1000000007*suma(m)%1000000007)%1000000007 << endl;
    }
    return 0;
}