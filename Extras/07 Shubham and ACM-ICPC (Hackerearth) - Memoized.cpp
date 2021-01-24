#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Shubham and ACM-ICPC - Memoized Approach
// Codathon - Inter NIT Coding Competition 2021 (HackerEarth)
// https://www.hackerearth.com/problem/algorithm/question-3-112/

ll ans = 1, ncopy;
map<pair<pair<ll, ll>, ll>, ll> mp;
    
ll rec(ll a[], ll b[], ll n, ll x, ll c) {
    if(n == -1) return ans = max(ans, x);
    if(mp.find({{n, x}, c}) != mp.end()) return 0;
    mp[{{n, x}, c}] = 1;
    if(b[n] == 1) rec(a, b, n - 1, x, c);
    b[n] = 1;
    for(ll i = 0 ; i < ncopy ; i++) {
        if(b[i] == 1) continue;
        b[i] = 1;
        rec(a, b, n - 1, __gcd(x, a[n] + a[i]), c - 1);
        b[i] = 0;
    }
    b[n] = 0;
    return 0;
}
    
int main() {	
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mp.clear();
    ll n; 
    cin >> n; 
    ncopy = n;
    ll a[n], b[n] = {0}; 
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    rec(a, b, n - 1, 0, n/2);
    cout << ans << '\n';
    return 0;
}
