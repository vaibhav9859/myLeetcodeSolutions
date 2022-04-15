// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
//User function Template for C++

/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    int singlevalued(Node *root)
    {
        //code here
        int ans = 0; 
        svHelper(root, ans);
        
        return ans;
    }
    
    pair<int, bool> svHelper(Node* root, int &ans){
        if(!root) return {INT_MAX, true};
        
        if(!root->left and !root->right){
            ans += 1; return {root->data, true};
        }
        
        // if(!root->left) return svHelper(root->right, ans);
        // if(!root->right) return svHelper(root->left, ans);
        
        pair<int, bool> leftVal = svHelper(root->left, ans);
        pair<int, bool> rightVal = svHelper(root->right, ans);
        
        if(leftVal.second and rightVal.second){
            if(leftVal.first != INT_MAX and rightVal.first != INT_MAX){
                if(root->data == leftVal.first and leftVal.first == rightVal.first){
                    ans += 1; 
                    return {root->data, true};                   
                }

            }
            else if(leftVal.first == INT_MAX and rightVal.first == root->data){
                ans += 1;
                return {root->data, true};
            }
            else if(root->data == leftVal.first){
                ans += 1;
                return {root->data, true};
            }
        }
        
        return {-1, false};
    }
    
};


// { Driver Code Starts.

int main()
{

	int t;
	cin >> t;
	getchar();
	while (t--)
	{

		string inp;
		getline(cin, inp);

        Solution ob;
        
		struct Node* root = buildTree(inp);
		cout << ob.singlevalued(root) << "\n";

	}
	return 0;
}
  // } Driver Code Ends