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

// Maximum Path Sum - Any Node to Any Node
// https://leetcode.com/problems/binary-tree-maximum-path-sum/


struct Node {
	int data ;
	struct node *left ;
	struct node *right ;
};

int pathSum(TreeNode *root, int &ans) {
	if(root == NULL) {
		return 0 ;
	}
	
	int l = pathSum(root->right, ans) ;
	int r = pathSum(root->left, ans) ;	
	
    int temp = max(max(l, r) + root -> val, root -> val) ;
	ans = max(ans, max(temp, l + r + root -> val)) ;
	return temp ; 
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
	#endif
	ans = -1e9 ;
    pathSum(node, ans) ;
    cout << ans << '\n' ;
    return 0;
}

