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

// Boolean Parenthesization Recursive Approach
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

int op(char a, char c, char b) {
	int x, y ;
	if(a == 'T') x = 1 ;
	else x = 0 ;
	if(b == 'T') y = 1 ;
	else y = 0 ;
	if(c == '^') {
		return x ^ y ;
	}
	if(c == '|') {
		return x | y ;
	}
	if(c == '&') {
		return x & y ;
	}
}

int boolean(vector <char> x, vector <char> y, int a, int b) {
	
	int ans = 0 ;
	for(int k = i ; k < j ; k++) {
		int x = op(boolean(x, y, a + 1, b), b[i + ], boolean(x, y, a, b - 1)) ;
		if(x == 1) ans ++
	}	
	return ans ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int temp, i, n ;
    cin >> n ;
	vector <char> x(n), y(n - 1) ;
	for( i = 0 ; i < n ; i++) {
		cin >> temp ;
		x.pb(temp) ;
	}
	for( i = 0 ; i < n - 1 ; i++) {
		cin >> temp ;
		y.pb(temp) ;
	}
	cout << boolean(x, y, 0, n - 1) << N ;
//	cout << op('T', '^', 'F') ;
	return 0;
}

