#include <iostream>
using namespace std;

void criba(int n, bool primos[]) {
    for (int i=0; i<=n; i++) {
        primos[i] = true;
    }
    primos[0] = primos[1] = false;
    for (int i=2; i*i<=n; i++) {
        if (primos[i]) {
            for (int j=i*i; j<=n; j+=i) {
                primos[j] = false;
            }
        }
    }
}

unsigned long long cb(int n, int k) {
    k = min(k, n-k);
    unsigned long long r = 1;
    for (int i=1; i<=k; i++) {
        r = r*(n-i+1) / i;
    }
    return r%1000000007;
}

unsigned long long hileras(int n, bool primos[]) {
    unsigned long long cont = 0;
    for (int unos=1; unos<=n; unos++) {
        if (primos[unos] && primos[n-unos]) {
            cont += cb(n, unos);
            cont %= 1000000007;
        }
    }
    return cont%1000000007;
}

int main() {
    int Q;
    bool primos[2001] = {false};
    unsigned long long res[2001] = {0};
    cin >> Q;
    criba(2001, primos);
    for (int n = 1; n <= 2000; n++) {
        res[n] = hileras(n, primos);
    }

    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        unsigned long long result = 0;
        if (X >= 1 && Y <= 2000) {
            for (int i=X; i<=Y; i++) {
                result += res[i];
                result %= 1000000007;
            }
        }
        cout << result << endl;
    }
    return 0;
}