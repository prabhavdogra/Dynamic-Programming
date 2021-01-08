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

// Matrix Chain Multiplication Recursive Approach

ll mcm(int a[], int i, int j) {
	if(i >= j) {
		return 0 ;
	}
	ll min = 1e14 ;
	for( int k = i ; k < j; k++) {
		ll temp = mcm(a, i , k) + mcm(a, k + 1, j) + (a[i - 1] * a[k] * a[j]); 	
		if((ll)min > (ll)temp) min = temp ;
	}
	return min ;
}

int main()
{
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	int n ;
	cin >> n ;
	int a[n], i ;
	for(i = 0 ; i < n ; i++) {
		cin >> a[i] ;
	}
	cout << (ll)mcm(a, 1, n - 1) ;
    return 0;
}

