#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << lcm(a,b) << '\n';
}