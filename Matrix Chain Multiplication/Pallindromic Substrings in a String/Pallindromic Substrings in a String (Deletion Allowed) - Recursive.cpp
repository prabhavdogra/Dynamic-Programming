#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;

set <string> SET;
string s; // String to associate each string with a unique index
// Here unique character at each index in the string acts as the index

bool isPallindrome(string s, ll start, ll end) {
    while(start < end) {
        if(s[start] != s[end]) return false;
        else start++,end--;        
    }
    return true;
}

ll countPallindrome(string b, ll start, ll end) {
    if(start > end) return 0;
    if(start == end) {
        SET.insert(s.substr(start, 1));
        return 0;
    }
    if(isPallindrome(b, start, end)) SET.insert(s.substr(start, end - start + 1));
    for(ll i = start ; i <= end ; i++) {
        string a = b.substr(i, 1);
        string a2 = s.substr(i, 1);
        b.erase(i, 1); 
        s.erase(i, 1);
            countPallindrome(b, start, end - 1);
        b.insert(i, a);
        s.insert(i, a2);
    }
    return 0;
}

int main() 
{	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;
    #endif 
    ll Test; cin >> Test;
    for(ll  i = 64 ; i < 126 ; i++) s += (char)i;
    while(Test--) {
        string b;
        cin >> b;
        countPallindrome(b, 0, b.length() - 1); 
        cout << SET.size() << '\n';
        SET.clear();
    }
    return 0;
}
  