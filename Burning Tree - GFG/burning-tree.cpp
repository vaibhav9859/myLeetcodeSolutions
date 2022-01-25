// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int ans = 0;
        vector<Node*> v;
        helper(root, target, v);
        map<Node*, bool> m;
        
        // cout<<endl;
        // for(auto a: v) cout<<a->data<<" ";
        // cout<<endl;
        
        for(int i=0; i<v.size(); i++){
            m[v[i]] = true;
        }
        
        for(int i=0; i<v.size(); i++){
            m[v[i]] = false;
            help(v[i], ans, m, v.size()-i-1);
        }
        
        // cout<<ans;
        
        return ans;
    }
    
    bool helper(Node* root, int target, vector<Node*> &v){
        // cout<<"x"<<endl; 
        // for(auto a:v)cout<<a->data<<" ";
        // cout<<endl;
        if(!root) return false;
        if(root->data == target){
            v.push_back(root);
        //     for(auto a:v)cout<<a->data<<" ";
        // cout<<endl;
            return true;
        }
        v.push_back(root);
        if(helper(root->left, target, v)) return true;
        if(helper(root->right, target, v)) return true;
        v.pop_back();
        return false;
    }
    
    void help(Node* root, int &ans, map<Node*, bool> &m, int level){
        // cout<<ans<<endl;
        if(!root) return;
        if(m[root]) return;
        
        ans = max(ans, level);
        
        help(root->left, ans, m, level+1);
        help(root->right, ans, m, level+1);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends