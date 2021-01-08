#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define N               '\n'
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define vi              vector <int>
#define M               1000000007
using namespace std;

// Boolean Parenthesization Recursive Approach
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

ll dp[201][201][2];

ll boolean(string s, int start, int end, int isTrue) {
	if(start > end) return 0;
	if(start == end) {
		if(isTrue) return 'T' == s[start];
		else return 'F' == s[start];
	}
	if(dp[start][end][isTrue] != -1) return dp[start][end][isTrue];
	ll ans = 0 ;
	
	for(int k = start + 1 ; k < end ; k += 2) {
		ll leftTrue, leftFalse, rightTrue, rightFalse;
		if(dp[start][k - 1][1] != -1)
			leftTrue = dp[start][k - 1][1];
		else
			leftTrue = dp[start][k - 1][1] = boolean(s, start, k - 1, 1);
		if(dp[start][k - 1][0] != -1)
			leftFalse = dp[start][k - 1][0];
		else
			leftFalse = dp[start][k - 1][0] = boolean(s, start, k - 1, 0);
		if(dp[k + 1][end][1] != -1)
			rightTrue = dp[k + 1][end][1];
		else
			rightTrue = dp[k + 1][end][1] = boolean(s, k + 1, end, 1);
		if(dp[k + 1][end][0] != -1)
			rightFalse = dp[k + 1][end][0];
		else
			rightFalse = dp[k + 1][end][0] = boolean(s, k + 1, end, 0);

		if(isTrue == 1) {
			if(s[k] == '&') ans += rightTrue * leftTrue ;
			else if(s[k] == '|') ans += (rightTrue * leftTrue) + (rightFalse * leftTrue) + (rightTrue * leftFalse) ;
			else if(s[k] == '^') ans += (rightFalse * leftTrue) + (rightTrue * leftFalse) ;
		}
		else {
			if(s[k] == '&') ans += (rightFalse * leftFalse) + (rightFalse * leftTrue) + (rightTrue * leftFalse) ;
			else if(s[k] == '|') ans += (rightFalse * leftFalse) ;
			else if(s[k] == '^') ans += (rightTrue * leftTrue) + (rightFalse * leftFalse) ;
		}
	}

	return dp[start][end][isTrue] = ans ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin) ;
		freopen("output.txt", "w", stdout) ;
	#endif
	memset(dp, -1, sizeof(dp));
	ll temp, n ;
	cin >> n;
	string s;
	cin >> s;
	cout << boolean(s, 0, s.length() - 1, 1) << '\n';
	return 0;
}

