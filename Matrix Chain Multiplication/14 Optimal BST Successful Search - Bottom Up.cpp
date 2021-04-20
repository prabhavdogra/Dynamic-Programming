#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Optimal BST Successful Search
// https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/

int main() {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin) ;
    //     freopen("output.txt", "w", stdout) ;
    // #endif 
    ll n;
    cin >> n;
    ll p[n];
    for(ll i = 0 ; i < n ; i++) 
        cin >> p[i];
    ll pref[n] = {p[0]};
    for(ll i= 1 ; i < n ; i++) 
        pref[i] = pref[i - 1] + p[i];
    ll dp[n][n];
    for(ll i = 0 ; i < n ; i++) 
        for(ll j = 0 ; j < n ; j++) 
            dp[i][j] = 0;
    for(ll g = 0 ; g < n ; g++) {
        for(ll i = 0, j = g ; j < n ; i++, j++) {
            if(g == 0) dp[i][j] = p[i];
            else if(g == 1) 
                dp[i][j] = min(p[i] + 2 * p[j], p[j] + 2 * p[i]);
            else {
                dp[i][j] = pref[j];
                if(i != 0) dp[i][j] -= pref[i - 1];
                ll mn = min(dp[i + 1][j], dp[i][j - 1]);
                for(ll k = i + 1 ; k < j ; k++) {
                    ll temp = dp[i][k - 1] + dp[k + 1][j];
                    mn = min(mn, temp);
                }
                dp[i][j] += mn;
            }
        }
    }
    // Bottom Up Array
    // for(ll i = 0 ; i < n ; i++) {
    //     for(ll j = 0 ; j < n ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
