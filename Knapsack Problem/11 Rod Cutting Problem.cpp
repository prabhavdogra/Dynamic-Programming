#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Rod Cutting Problem

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int n, i, j ;
    cin >> n ;
    int length[n], price[n] ;
    for( i = 0 ; i < n ; i++) {
    	cin >> length[i] ;
	}
	for( i = 0 ; i < n ; i++) {
    	cin >> price[i] ;
	}
	int dp[n + 1][n + 1] ;
	for( i = 0 ; i < n + 1 ; i++ ) {
		dp[i][0] = dp[0][i] = 0 ;
	} 
	for( i = 1 ; i < n + 1 ;i++) {
		for( j = 1 ; j < n + 1 ; j++) {
			if(length[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - length[i - 1]]) ;
			}
			else {
				dp[i][j] = dp[i - 1][j] ;
			}
		}
	}
//		Memoization Array
//		for (i = 0 ; i < n + 1 ; i++)	{
//			for( j = 0 ; j < n + 1 ; j++) {
//				cout << dp[i][j] << " ";
//			}
//			cout << '\n' ;
//		}
	cout << dp[n][n] << '\n' ;
    return 0;
}
