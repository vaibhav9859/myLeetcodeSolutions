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


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    void tvHelper(Node* root, map<int, pair<int, int>> &m, int curBreadth, int curLev){
        if(!root) return;
        
        if(!m[curBreadth].first) m[curBreadth] = {curLev, root->data};
        else if(curLev < m[curBreadth].first) m[curBreadth] = {curLev, root->data};
        
        tvHelper(root->left, m, curBreadth-1, curLev+1);
        tvHelper(root->right, m, curBreadth+1, curLev+1 );
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        //To solve top view problem I need to consider two things
        //At every breadth ... -1, 0, 1, 2... only one top view element will be present
        //Now problem is at ... -1, 0, 1, 2... there can be multiple elements, but top view will be only one
        //That only one element will be at the topmost level for that particular breadth
        //so we need to save two things one is breadth, and second one is height
        
        map<int, pair<int, int>> m;
        tvHelper(root, m, 0, 1);
        
        vector<int> output;
        
        for(pr: m){
            output.push_back(pr.second.second);
        }
        return output;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends