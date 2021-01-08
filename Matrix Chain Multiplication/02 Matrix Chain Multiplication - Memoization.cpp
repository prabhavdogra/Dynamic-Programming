#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define N				'\n'
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Matrix Chain Multiplication Memoization Approach

ll dp[1001][1001] ;
 
ll mcm(int a[], int i, int j) {
	if(i >= j) {
		return 0 ;
	}
	if(dp[i][j] != -1 ) 
		return (ll)dp[i][j] ;
	ll min = 1e14 ;	
	ll x, y ;
	for( int k = i ; k < j; k++) {
		if(dp[i][k] != -1)
			x = dp[i][k] ;
		else 
			x = dp[i][k] = mcm(a, i , k) ;
		if(dp[k + 1][j] != -1)
			y = dp[k + 1][j] ;
		else 
			y = dp[k + 1][j] = mcm(a, k + 1, j) ;
		ll temp = x + y + (a[i - 1] * a[k] * a[j]) ;	
		if( min > temp) min = temp ;
	}
	return dp[i][j] = min ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	memset(dp, -1, sizeof(dp)) ;
	int n ;
	cin >> n ;
	int a[n], i ;
	for(i = 0 ; i < n ; i++) {
		cin >> a[i] ;
	}
	cout << (ll)mcm(a, 1, n - 1) ;
    return 0;
}

