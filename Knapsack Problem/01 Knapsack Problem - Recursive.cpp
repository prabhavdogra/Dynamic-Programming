#include <bits/stdc++.h>
#include<math.h>
#define ll long long int
#define M 1000000007
using namespace std;

//Recursion Solution for KnapSack Problem
//https://www.spoj.com/problems/KNAPSACK/

int rec (int size[], int val[], int s, int n) {
	if (s == 0 || n == 0) {
		return 0 ;
	}
	if( size[n - 1] <= s ) {
		return max( val[n-1] + rec(size, val, s-size[n-1], n-1) , rec(size, val, s, n-1) ) ;
	}
	else {
		return rec(size, val, s, n-1);
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int s, n ;
    cin >> s >> n ;
	int size[n] ;
	int val[n] ;
	int i ;
	for ( i = 0 ; i < n ; i++ ) {
		cin >> size[i] ;
	}
	for ( i = 0 ; i < n ; i++ ) {
		cin >> val[i] ;
	}
	cout << rec (size, val, s, n);
    return 0;
}
