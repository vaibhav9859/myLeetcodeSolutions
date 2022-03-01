// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n == 0) return NULL;
        int it = 0; 
        return helper(in, pre, n, 0, n-1, it);
    }
    
    Node* helper(int in[],int pre[], int n, int sIndex, int eIndex, int &it){
        if(it == n) return NULL;
        if(sIndex>eIndex) return NULL;
        
        Node* root = new Node(pre[it]); it++;
        
        int midIndex = 0;
        for(int i = sIndex; i<=eIndex; i++){
            if(in[i] == root->data){
                midIndex = i; break;
            }
        }
        
        root->left = helper(in, pre, n, sIndex, midIndex-1, it);
        root->right = helper(in, pre, n, midIndex+1, eIndex, it);
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends