#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Stickler Thief - g4g
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=dsa-workshop-1-dp&batchId=308#

ll dp[10001][2];

ll rec(ll a[], ll n, ll x) {
    if(n == 0) {
        if(x == 1) return dp[n][x] = 0;
        else return dp[n][x] = a[n];
    }
    if(dp[n][x] != -1) return dp[n][x];
    if(x == 0) 
        return dp[n][x] = max(rec(a, n - 1, 0), rec(a, n - 1, 1) + a[n]);
    else 
        return dp[n][x] = rec(a, n - 1, 0);
    
    return 0;
}  

ll FindMaxSum(ll a[], ll n){
    memset(dp, -1, sizeof(dp));
    rec(a, n - 1, 0);
    return max(dp[n - 1][0], dp[n - 1][1]);
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

