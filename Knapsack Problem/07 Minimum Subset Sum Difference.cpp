#include <bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 1000000007
using namespace std;
	
//Minimum Subset Sum Difference

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j ;
    cin >> n ;
    int a[n] ;
    int sum = 0 ;
    for(i = 0 ; i < n ;i++) {
    	cin >> a[i] ;
    	sum += a[i] ;
    }
    int sum_copy = sum ;
    if(sum % 2) sum = sum/2 + 1 ;
    else sum = sum / 2 ;
    int dp[n+1][sum+1] ;
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
	for( i = sum ; i >= 0 ; i++ ) {
		if(dp[n][i] == 1) {
			break ;
		}
	}
	cout << abs((sum_copy - i)- i) << '\n' ;
}
