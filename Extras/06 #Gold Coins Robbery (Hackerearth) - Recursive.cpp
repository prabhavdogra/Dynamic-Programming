#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Gold Coins Robbery - Recursive Approach
// Codathon - Inter NIT Coding Competition 2021 (HackerEarth)

ll n_copy;
pair<ll, ll> rec(ll a[], ll b[], ll c, ll id, ll r1, ll r2, bool t) {
    if(c == 0) return {0, 0};
    pair<ll, ll> ans = {0, 0};
    if(id != -2 && ((id + 1 != n_copy && b[id + 1] != 1) || (id - 1 != -1 && b[id - 1] != 1)) ) {
        ll x = -1, y = -1, x1 = -1, x2 = -1, x3 = -1, x4 = -1;
        pair<ll, ll> tem1, tem2; // a[] : y, a[id], x
        if((id + 1 != n_copy && b[id + 1] != 1)) {
            x = a[id + 1];
            b[id + 1] = 1;
            tem1 = rec(a, b, c - 1, id + 1, r1, r2, !t);
            if(t == 0) x1 = x + tem1.first;
            else x3 = x + tem1.second;
            b[id + 1] = 0;
        }
        if((id - 1 != -1 && b[id - 1] != 1)) {
            y = a[id - 1];
            b[id - 1] = 1;
            tem2 = rec(a, b, c - 1, id - 1, r1, r2, !t);
            if(t == 0) x2 = y + tem2.first;
            else x4 = y + tem2.second;
            b[id - 1] = 0;
        }    
        if(t == 0) {
            if(x1 > x2) return {x1, tem1.second};
            else return {x2, tem2.second};
        }
        else {
            if(x3 > x4) return {tem1.first, x3};
            else return {tem2.first, x4};
        }
    }
    for(ll i = 0 ; i < n_copy ; i++) {
        if(b[i] == 1) continue;
        b[i] = 1;
        pair<ll, ll> temp = rec(a, b, c - 1, i, r1, r2, !t);
        if(t == 0) temp.first += a[i];
        else temp.second += a[i];
        b[i] = 0;
        if(t == 0 && temp.first > ans.first) ans = temp;
        if(t == 1 && temp.second > ans.second) ans = temp;
    }
    return ans;
}

int main() 
{	
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin) ;
    //     freopen("output.txt", "w", stdout) ;
    // #endif 
    ll n; cin >> n; 
    n_copy = n;
    ll a[n], b[n] = {0};
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    pair<ll, ll> answer = rec(a, b, n, -2, 0ll, 0ll, 0);
    cout << answer.first << " " << answer.second << '\n';
    return 0;  
}

