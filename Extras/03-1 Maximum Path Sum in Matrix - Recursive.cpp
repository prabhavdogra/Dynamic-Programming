#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Maximum Path Sum in Matrix - Recursive
// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

ll ans2;
ll helper(ll n, vector<vector<ll>> m, ll r, ll c, ll sum) {
    if(r == m.size()) return ans2 = max(ans2, sum);

    if(c != 0) helper(n, m, r + 1, c - 1, sum + m[r][c - 1]);
    helper(n, m, r + 1, c, sum + m[r][c]);
    if(c != n - 1) helper(n, m, r + 1, c + 1, sum + m[r][c + 1]);
    
    return 0;
}   

ll maximumPath(ll n, vector<vector<ll>> m) {
    ll ans = INT_MIN;
    for(ll i = 0 ; i < n ; i++) {
        ans2 = INT_MIN;
        helper(n, m, 0, i, 0ll);
        ans = max(ans, ans2);
    }
    return ans;
}

int main() 
{   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif 
    ll n;
    cin >> n;
    vector <vector<ll>> m(n, vector<ll>(n));
    for(ll i = 0 ; i < n*n ; i++) 
        cin >> m[i / n][i % n];
    cout << maximumPath(n, m) << '\n';
    return 0;
}