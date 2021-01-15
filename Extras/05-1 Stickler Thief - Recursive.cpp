#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Stickler Thief - Recursive
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=dsa-workshop-1-dp&batchId=308#

ll ans;

ll rec(ll a[], ll n, ll x, ll loot) {
    if(n == -1) { 
        ans = max(ans, loot); 
        return 0; 
    }
    if(x == 0) rec(a, n - 1, 1, loot + a[n]);
    rec(a, n - 1, 0, loot);
    
    return 0ll;
}
ll FindMaxSum(ll a[], ll n){
    ans = 0;
    rec(a, n - 1, 0, 0);
    return ans;
}

int main() {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;
    #endif 
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    cout << FindMaxSum(a, n) << '\n'; 
    return 0;
}

