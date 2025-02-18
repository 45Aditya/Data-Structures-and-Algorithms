#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll GCD(ll a, ll b) {
    if(b==0) {
        return a;
    } else {
        return GCD(b, a%b);
    }
}

ll Gcd(ll a, ll b) {
    while(b) {
        a = a%b;
        swap(a,b);
    }
    return a;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << GCD(a,b) << '\n';
    cout << Gcd(a,b) << '\n';
}