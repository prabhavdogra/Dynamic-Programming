#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Coin Change Problem Total Number of ways

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
	#endif
    int n, i, j, s ;
    cin >> n >> s ;
    int coin[n] ;
	for( i = 0 ; i < n ; i++) {
    	cin >> coin[i] ;
	}
	int dp[n + 1][s + 1] ;	
	for( i = 0 ; i < s + 1 ; i++ ) {
		dp[0][i] = 0 ;
	}
	for( i = 0 ; i < n + 1 ; i++ ) {
		dp[i][0] = 1 ;
	}
	for( i = 1 ; i < n + 1 ;i++) {
		for( j = 1 ; j < s + 1 ; j++) {
			if(coin[i - 1]<= j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]] ;
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
	cout << dp[n][s] << '\n' ;
    return 0;
}
