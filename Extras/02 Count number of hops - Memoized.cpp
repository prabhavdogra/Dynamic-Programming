#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define M 1000000007

// Count number of hops 
// Given a distance find number of ways to cover the distance with 1, 2 and 3 steps.
// https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/amp/

ll dp[100001];

ll helper(ll n) {
    if(n == 1) return dp[1] = 1;
	helper(n - 1);
	if(n >= 1) dp[n] += dp[n - 1];
	if(n >= 2) dp[n] += dp[n - 2];
	if(n >= 3) dp[n] += dp[n - 3];
	return dp[n];
}

ll countWays(ll n) {
	memset(dp, 0, sizeof(dp));
    return helper(n + 1);
}

int main() 
{   
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin) ;
	// 	freopen("output.txt", "w", stdout) ;
	// #endif 
	ll T;
	// cin >> T;
	T = 1;
	while(T--) {
		ll n;
		cin >> n;
		cout << countWays(n) << '\n';
	}
	return 0;
}

