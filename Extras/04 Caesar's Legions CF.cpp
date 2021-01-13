#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define M               100000000

// Caesar's Legions Codeforces
// https://codeforces.com/contest/118/problem/D

ll k1, k2;
ll dp[101][101][11][11];
ll rec(ll n1, ll n2, ll x, ll y) {
    if(n1 == 0 && n2 == 0) return 1;
    
    if(dp[n1][n2][x][y] != -1) return dp[n1][n2][x][y];

    ll a1 = 0, a2 = 0;
    if(x > 0 && n1 > 0) a1 = rec(n1 - 1, n2, x - 1, k2);
    if(y > 0 && n2 > 0) a2 = rec(n1, n2 - 1, k1, y - 1);

    return dp[n1][n2][x][y] = (a1 + a2) % M;
}

int main() 
{	
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));
    ll n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << rec(n1, n2, k1, k2);
    
    return 0;
}
