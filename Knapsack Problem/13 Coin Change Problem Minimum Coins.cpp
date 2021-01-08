#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Coin Change Problem Minimum Coins

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int n, i, j, s ;
    cin >> n >> s;
    int coins[n] ;
	for( i = 0 ; i < n ; i++) {
    	cin >> coins[i] ;
	}
	int dp[n + 1][s + 1] ;	
	for( i = 0 ; i < s + 1 ; i++ ) {
		dp[0][i] = INT_MAX - 3 ;
	}
	for( i = 0 ; i < n + 1 ; i++ ) {
		dp[i][0] = 0 ;
	}
	for( i = 1 ; i < n + 1 ;i++) {
		for( j = 1 ; j < s + 1 ; j++) {
			if(coins[i - 1]<= j) {
				dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]) ;
			}
			else {
				dp[i][j] = dp[i - 1][j] ;
			}
		}
	}
//		Memoization Array
//		for (i = 0 ; i < n + 1 ; i++)	{
//			for( j = 0 ; j < s + 1 ; j++) {
//				cout << dp[i][j] << " ";
//			}
//			cout << '\n' ;
//		}
	if(dp[n][s] == INT_MAX -3) {
		cout << "-1" << '\n' ;
		return 0 ;
	}
	cout << dp[n][s] << '\n' ;
    return 0;
}
