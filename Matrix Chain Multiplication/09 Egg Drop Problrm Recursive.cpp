#include <bits/stdc++.h>
#include<math.h>
#define ll              long long int
#define N				'\n'
#define ull             unsigned long long int
#define pb              push_back
#define vi              vector <int>
#define M               1000000007
using namespace std;

// Egg Drop Problem - Recursive Approach
// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

int drop_egg(int e, int f) {
	if(f == 0) {
		return 0 ;
	}
	if(e == 1 || f == 1) {
		return f ;
	}
	int ans = 1e9, x, y ;
	for(int k = 1 ; k <= f ; k++) {
		x = drop_egg(e - 1, k - 1) ;
		y = drop_egg(e, f - k) ;
		int temp = 1 + max(x, y) ;
		ans = min(ans, temp) ;
	}
	return ans ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
    int e, f ;
    cin >> e >> f ; 
    cout << drop_egg(e, f) << '\n';
    return 0;
}

