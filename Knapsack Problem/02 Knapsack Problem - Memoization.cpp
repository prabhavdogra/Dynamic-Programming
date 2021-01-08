#include <bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 1000000007
using namespace std;

// Knapsack Problem - Memoization

int s, n ;
int dp[2001][2001] ;
int rec (int size[], int val[], int s, int n) {
	if (s == 0 || n == 0) {
		return 0 ;
	}
	if( dp[s][n] != -1 )
		return dp[s][n] ;
	if( size[n - 1] <= s ) {
		return dp[s][n] = max( val[n-1] + rec(size, val, s-size[n-1], n-1) , rec(size, val, s, n-1) ) ;
	}
	else {
		return dp[s][n] = rec(size, val, s, n-1);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	memset(dp, -1, sizeof(dp) ) ;
    cin >> s >> n ;
	int size[n] ;
	int val[n] ;
	int i ;
	for ( i = 0 ; i < n ; i++ ) {
		cin >> size[i] ;
	}
	for ( i = 0 ; i < n ; i++ ) {
		cin >> val[i] ;
	}
	for ( i = 0 ; i < 2001 ; i++ ) {
		dp[i][0] = 0 ;
		dp[0][i] = 0 ;
	}
	cout << rec (size, val, s, n);
    return 0;
}
