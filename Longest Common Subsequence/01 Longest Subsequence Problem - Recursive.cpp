#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Longest Common Subsequence or LCS - Recursive Solution

int fun(string x, string y, int m, int n) {
	if(m == 0 || n == 0) {
		return 0 ;
	}
	if( x[m - 1] == y[n - 1] ) {
		return 1 + fun(x, y, m - 1, n - 1) ;
	}
	else {
		return max(fun(x, y, m - 1, n), fun(x, y, m, n - 1)) ;
	}
}
int main()
{
	
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    string x, y ;
    cin >> x >> y ;
    int m = x.length() ;
	int n = y.length() ;
    cout << fun(x, y, m, n) ;
    return 0;
}

