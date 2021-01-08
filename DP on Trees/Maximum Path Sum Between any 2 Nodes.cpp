#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Maximum Path Sum between any 2 Nodes
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Test Case
// Input: 
// 1 20 3 N N 4 6 N 5 N N 7 N
// Output: 40 (20 + 1 + 3 + 4 + 5 + 7)

// Tree:
//         1
//       /   \
//      20    3
//           / \
//          4   6
//           \
//            5
//           /
//          7
int pathSum(Node *root, int &ans) {
	if(root == NULL) {
		return 0 ;
	}
    
	int l = pathSum(root->right, ans) ;
	int r = pathSum(root->left, ans) ;	
	
    int temp = max(max(l, r) + root -> data, root -> data) ;
	ans = max(ans, max(temp, l + r + root -> data)) ;
	return temp ; 
}

int maxPathSum(Node* root)
{ 
    int ans = -1e9 ;
    pathSum(root, ans) ;
    return ans ;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
     	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    cout << maxPathSum(root) << "\n";
    return 0;
}