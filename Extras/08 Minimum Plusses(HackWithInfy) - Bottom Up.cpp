#include <bits/stdc++.h>
#define ll long long int
using namespace std; 

// Minimum Pluses - Bottom Up
// HackWithInfy Sample Paper - Round 1 

// Q.  Given an equation "x=y", for example, "111=12", you need to add pluses inside x to make the equation correct. 
//     In our example "111=12", we can add one plus "11+1=12" and the equation becomes correct. You need to find the
//     minimum number of pluses to add to x to make the equation correct. If there is no answer print -1.
// Note:
// The value of y won't exceed 5000. The numbers in the corrected equation may contain arbitrary amounts of leading zeros.

// Input Format
// The first line contains a string, A as described in the problem statement.

// Constraints
// 1 <= len(A) <= 10^3

// Sample Input |	Sample Output	     |              Explanation
// 23=5         |   	1                |  It can be accomplished with only one "+" by doing "2+3=5".

void solve() {
	string a, s, b;
	cin >> s;
	ll id = 0;
	while(s[id] != '=') 
		a.push_back(s[id]), id++;
	id++;
	while(id != s.length()) 
		b.push_back(s[id]), id++;
	ll y = stoll(b), n = a.length();
	if(b == a) {
		cout << 0 << endl;
		return;
	}
	vector<vector<ll>> dp(n + 1, vector<ll> (y + 1, 1e9));
	dp[0][0] = 0;
	for(ll i = 1 ; i <  n + 1 ; i++) {
		for(ll j = 1 ; j <  y + 1 ; j++) {
			ll id = i - 1, count = 0;
			while(id >= 0 && count < 5) {
				ll val = stoll(a.substr(id, count + 1));
				if(j >= val && dp[i - count - 1][j - val] != 1e9) 
					dp[i][j] = min(dp[i][j], dp[i - count - 1][j - val] + 1);
				id--;
				count++;
			}
		}
	}
	// forp(i, 0, n + 1) {
	// 	forp(j, 0, y + 1) {
	// 		if(dp[i][j] != 1e9) cout << dp[i][j] << " ";
	// 		else cout << I << " ";
	// 	}		
	// 	cout << endl;
	// }
	if(dp[n][y] != 1e9) 
		cout << dp[n][y] - 1 << endl;
	else 
		cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
