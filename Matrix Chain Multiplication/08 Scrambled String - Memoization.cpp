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

// Scrambled String - Memoized Approach
// https://leetcode.com/problems/scramble-string/

map <pair<string, string>, bool> m;

bool scrambled_helper(string s1, string s2) {
    if(s1 == s2) return true;
    if(s1.length() <= 1) return false;
    if(m.find({s1, s2}) != m.end()) return m[{s1,s2}];
    for(ll i = 1 ; i < s1.length() ; i++) {
        ll flag1 = scrambled_helper(s1.substr(0, i), s2.substr(s1.length() - i, i)) &&
                   scrambled_helper(s1.substr(i, s1.length() - i), s2.substr(0, s1.length() - i));
        ll flag2 = scrambled_helper(s1.substr(0, i), s2.substr(0, i)) &&
                   scrambled_helper(s1.substr(i, s1.length() - i), s2.substr(i, s2.length() - i));

        if(max(flag1, flag2)) return m[{s1,s2}] = true;
        else m[{s1, s2}] = false;
    }
    return m[{s1,s2}] = false;
}

bool isScrambled(string s1, string s2)  {
    m.clear();
    if(s1.length() != s2.length()) return false;
    return scrambled_helper(s1, s2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif
    string s1, s2;
    cin >> s1 >> s2;
    cout << isScrambled(s1,s2) ;
    return 0;
}

