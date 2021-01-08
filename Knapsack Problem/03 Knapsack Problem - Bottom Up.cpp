#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Knapsack Problem Bottom Up

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	int n, w, i, j ; 
	cin >> w >> n ;
	int dp[n + 1][w + 1] ;
	int wt[n], val[n] ;
	memset(dp, -1, sizeof(dp)) ;
	for( i= 0 ; i < n ; i++) {
		cin >> wt[i] ;
	}
	for( i= 0 ; i < n ; i++) {
		cin >> val[i] ;
	}
	for( i = 0 ; i < n + 1  ; i++ ) {
		dp[i][0] = 0 ;
	}
	for( i = 0 ; i <= w ; i++ ) {
		dp[0][i] = 0 ;
	}
	for( i = 1 ; i <= n ; i++) {
		for( j = 1 ; j <= w ; j++) {
		    if(wt[i-1] <= j)
			    dp[i][j] = max (dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]) ;
		    else
		        dp[i][j] = dp[i-1][j] ;
		}
	}
//	Memoization Array
//	for( i = 0 ; i <= n ; i++) {
//		for( j = 0 ; j <= w ; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << '\n' ;
//	}
    cout << dp[n][w] ;
    return 0;
}
