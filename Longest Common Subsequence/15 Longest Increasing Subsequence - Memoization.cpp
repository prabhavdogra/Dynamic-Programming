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

// Longest Increasing Subsequence - Memoized
// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

int dp[1001][1001] ;

int rec(int a[], int n, int x) {
    if(n == -1) {
        return 0 ;
    }
    if(dp[n][x] != -1) {
    	return dp[n][x] ;
	}
    if(a[n] < x) {
    	return dp[n][x] = max(rec(a, n - 1, x) , 1 + rec(a, n - 1, a[n]));
    }
    else {
        return dp[n][x] =  rec(a, n - 1, x) ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int T;
    cin >> T;
    while(T--)
    {
    	memset(dp, -1, sizeof(dp)) ;
        int n, i ;
        cin >> n ;
        int a[n] ;
        for( i = 0 ; i < n ; i++) cin >> a[i] ;
        cout << rec(a, n - 1, 10000) << N ;
    }
    return 0;
}
	
