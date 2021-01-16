#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

// Count All Palindrome Sub-Strings in a String - Bottom up
// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

int main() 
{	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll Test; cin >> Test;
    while(Test--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll dp[n + 1][n + 1];
        for(int i =  1 ; i < n + 1 ; i++) {
            for(int j = 1 ; j < n + 1 ; j++) {
                dp[i][j] = 1;
            }
        }
        for(int i =  1 ; i < n + 1 ; i++) {
            dp[i][i] = 1;
        }
        for(int i =  n - 1 ; i >= 1 ; i--) {
            for(int j = i + 1 ; j < n + 1 ; j++) { 
                    dp[i][j] = ( dp[i + 1][j - 1] == 1 && s[i - 1] == s[j - 1]);
            }
        }
        ll ans = 0;
        // Memoization Array
        // for(int i =  1 ; i < n + 1 ; i++) {
        //     for(int j = 1 ; j < n + 1 ; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        for(int i =  1 ; i < n + 1 ; i++) {
            for(int j = i + 1 ; j < n + 1 ; j++) {
                ans += dp[i][j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
  