#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Longest Common Substring

int main()
{
	
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    string x, y ;
    int i, j ;
    cin >> x >> y ;
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
				dp[i][j] = 0 ;
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
	int max = dp [1][1];
	for(i = 1 ; i < m + 1 ; i++) {
		for(j = 1 ; j < n + 1 ; j++) {
			if(max < dp[i][j]) {
				max = dp[i][j] ;
			}
		}
	}
	cout << max << '\n' ;
    return 0;
}

