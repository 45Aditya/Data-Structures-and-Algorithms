#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long binaryPower(ll a, ll b) {
    if(b==0) {
        return 1;
    }
    long long res = binaryPower(a, b/2);
    if(b%2) {
        return res * res * a;
    } else {
        return res * res;
    }
}

long long binPow(ll a, ll b) {
    long long res = 1;
    while(b>0) {
        if(b&1) {
            res = res * a;
        }
        a = a*a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << "a^b = " << binPow(a,b) << '\n'; 
    cout << "a^b = " << binaryPower(a, b);
}