#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Edit Distance - Memoized
// https://www.geeksforgeeks.org/edit-distance-dp-5/

ll ans = INT_MAX;

ll distanceHelper(string a, string b, ll m, ll n) {
    if(m == 0 || n == 0) {
        return max(m, n);
    }
    if(a[m - 1] == b[n - 1]) {
    	return distanceHelper(a, b, m - 1, n - 1);
    }
	else {
    	return 1 + min(distanceHelper(a, b, m - 1, n), // remove
                         min(distanceHelper(a, b, m - 1, n - 1), // replace
                         distanceHelper(a, b, m, n - 1))); // insert
	}
	return 0;
}


ll editDistance(string s, string t){
	ll m = s.length(), n = t.length(); 
	ans = 1e9;
	return distanceHelper(s, t, m, n);
}


int main() 
{   
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin); 
	// 	freopen("output.txt", "w", stdout);
	// #endif 
	ll T; 
	// cin >> T;
	T = 1;
	while(T--) {
		string s, t; 
		cin >> s >> t;
		cout << editDistance(s, t) << '\n';
	}
	return 0;
}

