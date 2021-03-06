#include <bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 1000000007
using namespace std;
	
//Subset Sum Problem 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , sum, i, j ;
    cin >> n >> sum ;
    int a[n] ;
    for(i = 0 ; i < n ;i++) {
    	cin >> a[i] ;
    }
    int dp[n+1][sum +1] ;
    memset(dp, -1, sizeof(dp)) ;
	for(i = 0 ; i < n + 1 ;i++) {
    	dp[i][0] = 1 ;
    }
    for(i = 1 ; i < sum + 1 ;i++) {
    	dp[0][i] = 0 ;
    }
    for(i = 1 ; i < n + 1 ;i++) {
    	for( j = 1 ; j < sum + 1 ; j++) {
    		if( a[i-1] <= j ) {
    			dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]) ;
    		}
    		else {
    			dp[i][j] = dp[i-1][j] ; 
    		}
    	}
    }
//	Memoization Array
//	for( i = 0 ; i <= n ; i++) {
//		for( j = 0 ; j <= sum ; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << '\n' ;
//	}
	if(dp[n][sum])
    	cout << "true";
    else
    	cout <<"false" ;
    return 0;
}
