#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Count of Subset with given difference

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int n, d, i, j ; 
	cin >> n >> d ;
	int a[n] ;
	int sum = 0 ;
	for( i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		sum += a[i] ;
	}
	int x = (sum + d)/ 2 ;
	if(sum + d % 2 == 1) {
		cout << "No" << '\n' ;
		return 0 ; // or continue
	}
	int y = sum - x ;
	sum = min(x, y);
	int dp[n + 1][sum + 1] ;
	memset(dp, -1, sizeof(dp)) ;
	for( i = 0 ; i < sum + 1 ; i++ ) {
		dp[0][i] = 0 ;
	}
	for( i = 0 ; i < n + 1  ; i++ ) {
		dp[i][0] = 1 ;
	}
	for( i = 1 ; i < n + 1 ; i++) {
		for( j = 1 ; j < sum + 1 ; j++) {
		    if(a[i-1] <= j)
			    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]] ;
		    else
		        dp[i][j] = dp[i-1][j] ;
		}
	}
//	Memoization Array
//	for( i = 0 ; i < n + 1 ; i++) {
//		for( j = 0 ; j < sum + 1 ; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << '\n' ;
//	}
    cout << dp[n][sum] << '\n';
    return 0;
}
