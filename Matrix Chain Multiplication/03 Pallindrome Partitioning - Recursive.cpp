#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define N				'\n'
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back
#define M               1000000007
using namespace std;

// Pallindrome Partitioning - Recursive Approuach
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

bool isPallindrome(string s, int m, int n) {
	for(int i = 0 ; i <= (n - m) /2 ; i++) 
		if(s[m + i] != s[n - i]) return false ;
	return true ;
}

int pallin(string s, int i, int j) {
	if(i >= j) 
		return 0 ;
	if(isPallindrome(s, i, j)) return 0 ;
	int ans = 1e9 ;
	for(int k = i ; k < j ; k++) {
		int temp = 1 + pallin(s, i, k) + pallin(s, k + 1, j) ;
		ans = min(ans, temp) ;
	}
	return ans ;
}

int main()
{
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    string s;
    cin >> s ;
	cout << pallin(s, 0, s.size()-1) << '\n' ;
    return 0;
}

