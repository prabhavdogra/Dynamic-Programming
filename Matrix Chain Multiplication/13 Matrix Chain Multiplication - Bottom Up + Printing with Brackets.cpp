#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Matrix Chain Multiplication Bottom Up 

vector<vector<ll>> dp, s;

void print(vector<vector<ll>> s, ll i, ll j) {
    if(i == j) {
        cout << "A" << i + 1;
        return;
    }
    printf("(");
    print(s, i, s[i][j]);
    print(s, s[i][j] + 1, j);
    printf(")");
}

int main() {
	ll n;
	cin >> n;
	ll a[n - 1];
	for(ll i = 0 ; i < n ; i++) 
		cin >> a[i];
	for(ll i = 0 ; i < n - 1 ; i++) {
        vector <ll> temp;
        dp.push_back(temp); s.push_back(temp);
		dp[i].assign(n - 1, 0);
		s[i].assign(n - 1, 0);
	}
	for(ll g = 0 ; g < n - 1 ; g++) {
		for(ll i = 0, j = g ; j < n - 1 ; i++, j++) {
            if(g == 0) dp[i][j] = 0;
            else if(g == 1) {
                dp[i][j] = a[i] * a[j] * a[j + 1];
                s[i][j] = i;
            }
            else {
                ll mn = 1e9, id = 0;
                for(ll k = i ; k < j ; k++) {
                    if(mn > dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1]) {
                        mn = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
                        id = k;
                    }
                }
                dp[i][j] = mn;
                s[i][j] = id;
            }
        }
	}
    // Bottom-Up matrix
    // for(ll i = 0 ; i < n - 1 ; i++) {
    //     for(ll j = 0 ; j < n - 1 ; j++) 
    //         cout << dp[i][j] << " ";
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(ll i = 0 ; i < n - 1 ; i++) {
    //     for(ll j = 0 ; j < n - 1 ; j++) 
    //             cout << s[i][j] << " ";
    //     cout << '\n';
    // }
    // cout << '\n';
	cout << "Cost: " << dp[0][n - 2] << '\n';
    cout << "The string is: ";
	print(s, 0ll, n - 2);
	return 0;
}

