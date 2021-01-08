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

// Pallindrome Partitioning - Memoized Approach
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

int dp[1001][1001] ;
bool p[1001][1001] ;

bool isPallindrome(string s, int m, int n) {
	for(int i = 0 ; i <= (n - m) /2 ; i++) 
		if(s[m + i] != s[n - i]) return false ;
	return true ;
}

int pallin(string s, int i, int j) {
	if(i >= j) 
		return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(p[i][j]) return 0 ;
	int ans = 1e9, x, y ;
	for(int k = i ; k < j ; k++) {
		if(dp[i][k] != -1) x = dp[i][k] ;
		else x = dp[i][k] = pallin(s, i, k) ;
		if(dp[k + 1][j] != -1) y = dp[k + 1][j] ;
		else y = dp[k + 1][j] = pallin(s, k + 1, j) ;
		int temp = 1 + x + y ;
		ans = min(ans, temp) ;
	}
	return ans ;
}

int main()
{
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	memset(dp, - 1, sizeof(dp)) ;
	memset(p, false, sizeof(p)) ;
    string s;
    cin >> s ;
    int i,  j ;
    for(i = 0 ; i <= s.size() ; i++ ) {
    	for( j = 0 ; j <= s.size() ; j++) {
    		p[i][j] = isPallindrome(s, i , j)  ;
		}
	}
	cout << pallin(s, 0, s.size()-1) << '\n' ;
    return 0;
}

