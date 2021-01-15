#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Stickler Thief - Bottom Up
// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/?track=dsa-workshop-1-dp&batchId=308#

ll FindMaxSum(ll a[], ll n){
    ll dp[n][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = a[0];
    dp[0][1] = 0;
    for(ll i = 1 ; i < n ; i++) {
        for(ll j = 0 ; j < 2 ; j++) {
            if(j == 0) {
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
            }
            else {
                dp[i][j] = dp[i - 1][0];
            }
        }   
    }
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

