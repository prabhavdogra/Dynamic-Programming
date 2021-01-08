#include <bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 1000000007
using namespace std;

// Equal Sum Partition Problem

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, j;
    cin >> n;
    ll sum = 0 ;
    int a[n] ;
    for (i = 0 ; i < n ; i++) {
    	cin >> a[i];
    	sum+= a[i] ;
	}
    if(sum % 2s) {
    	cout << "False" << '\n' ;
    	return 0 ; // or continue
	}
	sum = sum /2 ;
	int dp[n+1][sum+1] ;
	for( i = 0 ; i < n+1 ; i++) {
		dp[i][0] = 1 ;
	}
	for( i = 0 ; i < sum+1 ; i++) {
		dp[0][i] = 0 ;
	}
	for (i = 1 ; i < n+1 ; i++)	{
		for( j = 1 ; j< sum+1 ; j++) {
			if( a[i-1] <= j) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]]);
			}
			else {
				dp[i][j] = dp[i-1][j] ;
			}
		}
	}
//		Memoization Array
//		for (i = 0 ; i < n + 1 ; i++)	{
//			for( j = 0 ; j< sum + 1 ; j++) {
//				cout << dp[i][j] << " ";
//			}
//			cout << '\n' ;
//		}
	if(dp[n][sum] == 1) 
		cout << "True "<<'\n' ;
	else
		cout << "False "<<'\n' ;
	return 0;
}
