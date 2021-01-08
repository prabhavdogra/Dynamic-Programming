#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Longest Pallindromic Subsequence

int main()
{
	
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    string x, y ;
    int i, j ;
    cin >> x ;
    y = x ;
    reverse(y.begin(), y.end()) ;
    int m = x.length() ;
	int n = y.length() ;
	int dp[m + 1][n + 1] ;
	for (i = 0 ; i < m + 1 ; i++) {
		dp[i][0] = 0 ;
	}
	for (i = 0 ; i < n + 1 ; i++) {
		dp[0][i] = 0 ;
	}
	for(i = 1 ; i < m + 1 ; i++) {
		for(j = 1 ; j < n + 1 ; j++) {
			if(x[i - 1] == y[j -1]) {
				dp[i][j] = 1 + dp[i -1][j - 1] ;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) ;
			}
		}	
	}
//	Memoization Array
//	for(i = 0 ; i < m + 1 ; i++) {
//		for(j = 0 ; j < n + 1 ; j++) {
//			cout << dp[i][j] << " " ;
//		}
//		cout << '\n' ;
//	}
	i = m ;
	j = n ;
	string ans ;
	while(i > 0 && j > 0) {
		if(x[i - 1] == y[j - 1]) {
			ans.push_back(x[i - 1]) ;
			i -- ; 
			j -- ;
		}
		else {
			if(dp[i - 1][j] < dp[i][j - 1]) {
				j -- ;
			}
			else {
				i -- ;
			}
		}
	}
	cout << ans << '\n' ; 
    return 0;	
}

