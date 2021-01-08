#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Longest Common Subsequence or LCS between 3 strings - Bottom Up

int main()
{
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	int m, i, j, k, n, o ;
	string x, y, z;
	cin >> x >> y >> z ;
	m = x.length() ;
	n = y.length() ;
	o = z.length() ;
    for(i =  0 ; i < o ; i++) cin >> z[i] ;
    int dp[m + 1][n + 1][o + 1] ;
	for (i=0; i < m + 1 ; i++) { 
		for (j = 0 ; j < n + 1 ; j++) { 
            for (k = 0; k < o + 1 ; k++) { 
                if (i == 0 || j == 0 || k == 0) 
                    dp[i][j][k] = 0; 
            } 
        } 
    } 
	for(i = 1 ; i < m + 1 ; i++) {
		for(j = 1 ; j < n + 1 ; j++) {
			for(k = 1 ; k < o + 1 ; k++) {
				if(x[i - 1] == y[j -1] && y[j - 1] == z[k - 1]) {
					dp[i][j][k] = 1 + dp[i -1][j - 1][k - 1] ;
				}
				else {
					dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1])) ;
				}
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
	cout << dp[m][n][o] << '\n' ;
    return 0;
}

