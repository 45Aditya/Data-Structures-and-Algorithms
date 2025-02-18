#include<bits/stdc++.h>
using namespace std;

void prime(int n) {
    if(n==0 || n==1) cout << 0 << '\n';
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=n; i++) {
        if(isPrime[i] && i*i <= n) {
            for(int j=i*i; j<=n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i=0; i<=n; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    prime(n);
}