#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Maximum path sum in matrix - Bottom Up Approach
// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

ll maximumPath(ll n, vector<vector<ll>> m) {
    if(n == 0) return m[0][0];
    ll ans = INT_MIN;
    ll dp[n][n];
    memset(dp, -1, sizeof(dp));
    for(ll i = 0 ; i < n ; i++)
        dp[n - 1][i] = m[n - 1][i];
    
    for(ll i = n - 2 ; i >= 0 ; i--) {
        for(ll j = 0 ; j < n ; j++) {
            ll mx;
            if(j == 0) 
                mx = max(dp[i + 1][j], dp[i + 1][j + 1]);
            else if(j == n - 1) 
                mx = max(dp[i + 1][j], dp[i + 1][j - 1]);
            else 
                mx = max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
            dp[i][j] = mx + m[i][j];
        }
    }
    // Memoization Array
    // for(ll i = 0 ; i < n ; i++) {
    //     for(ll j = 0 ; j < n ; j++)
    //         cout << dp[i][j] << " ";
    //     cout << '\n';
    // }
    for(ll i = 0 ; i < n ; i++)
        ans = max(ans, dp[0][i]);
    return ans;
}

int main() 
{   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif 
    ll n;
    cin >> n;
    vector <vector<ll>> m(n, vector<ll>(n));
    for(ll i = 0 ; i < n*n ; i++) 
        cin >> m[i / n][i % n];
    cout << maximumPath(n, m) << '\n';
    return 0;
}