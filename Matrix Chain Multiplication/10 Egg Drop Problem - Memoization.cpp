#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define N				'\n'
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define vi              vector <int>
#define M               1000000007
using namespace std;

int dp[1001][1001] ;

int drop_egg(int e, int f) {
	if(f == 0) {
		return 0 ;
	}
	if(e == 1 || f == 1) {
		return f ;
	}
	if(dp[e][f] != -1) {
		return dp[e][f] ;
	}
	int ans = 1e9, x, y ;
	for(int k = 1 ; k <= f ; k++) {
		if(dp[e - 1][k - 1] != -1) 
			x = dp[e - 1] [k - 1] ;
		else 
			x = dp[e - 1][k - 1] = drop_egg(e - 1, k - 1) ;
		if(dp[e][f - k] != -1) 
			y = dp[e] [f - k] ;
		else 
			y = dp[e][f - k] = drop_egg(e, f - k) ;
		int temp = 1 + max(x, y) ;
		ans = min(ans, temp) ;
	}
	return dp[e][f] = ans ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	memset(dp, -1 , sizeof(dp)) ;
    int e, f ;
    cin >> e >> f ;
    cout << drop_egg(e, f) << '\n';
    return 0;
}

