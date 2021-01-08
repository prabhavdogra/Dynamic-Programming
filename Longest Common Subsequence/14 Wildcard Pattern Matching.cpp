#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define ull             unsigned long long int
#define forp(i,a,b)     for(int i=(int)a;i<(int)b;i++)
#define forpe(i,a,b)    for(int i=(int)a;i<=(int)b;i++)
#define pb              push_back	
#define M               1000000007
using namespace std;

// Wildcard Pattern Matching

// #TEST CASES
// Text = "baaabab",
// Pattern = “*****ba*****ab", output : true
// Pattern = "baaa?ab", output : true
// Pattern = "ba*a?", output : true
// Pattern = "a*ab", output : false 

bool wc(string pattern, string text, int a, int  b) {
	if(a == 0 || b == 0) {
		if((a == 0 && b == 0) || (a == 0 && pattern[0] == '*') || (pattern[0] == '*' && a == 1))  
			return true ;
		return false ; 
	}
	if(pattern[a - 1] == '*') {
		return max(wc(pattern, text, a - 1, b), wc(pattern, text, a, b - 1)) ;
	}
	else if(pattern[a - 1] == '?') {
		return wc(pattern, text, a - 1, b - 1) ;
	}
	else if(pattern[a - 1] == text[b - 1]) {
		return wc(pattern, text, a - 1, b - 1) ;
	}
	else if(pattern[a - 1] != text[b - 1]) {
		return false ;
	}
}

int main()
{
	
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	int T ;
	cin >> T ;
	
	string t ;
	cin >> t ; // taking string text once
	while (T--) {
		string p ;
		cin >> t ;
		int i = 0 ;
		while(i < p.length() - 1){ // deleting consecutive *'s
			if(p[i] == p[i + 1] && p[i] == '*') 
				p.erase(p.begin() + i + 1) ;
			else i++ ;
		}
		int a = p.length() ;
		int b = t.length() ;
		if(wc(p, t, a, b ) == true) cout << "1"  << '\n' ;
		else cout << "0" << '\n' ;
	}
    return 0;
}

