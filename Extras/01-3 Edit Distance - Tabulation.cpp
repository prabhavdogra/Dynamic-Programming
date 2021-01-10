#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Edit Distance - Tabulation
// https://www.geeksforgeeks.org/edit-distance-dp-5/

ll editDistance(string s, string t){
	ll n = s.length();
    ll m = t.length(); 
    ll dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for(ll i = 1 ; i < n + 1 ; i++) 
        dp[i][0] = i;
    for(ll i = 1 ; i < m + 1 ; i++) 
        dp[0][i] = i;
    for(ll i = 1 ; i < n + 1 ; i++) {
        for(ll j = 1 ; j < m + 1 ; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
	// Tabulated Array
	// for(ll i = 1 ; i < n + 1 ; i++) {
    //     for(ll j = 1 ; j < m + 1 ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
	// 	cout << '\n';
    // }
    return dp[n][m];
}


int main() 
{   
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin); 
	// 	freopen("output.txt", "w", stdout);
	// #endif 
	ll T; 
	// cin >> T;
	T = 1;
	while(T--) {
		string s, t; 
		cin >> s >> t;
		cout << editDistance(s, t) << '\n';
	}
	return 0;
}

