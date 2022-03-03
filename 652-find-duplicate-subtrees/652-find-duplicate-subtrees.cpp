/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> output;
        
        unordered_map<string, pair<int, TreeNode*>> m;
        
        helper(root, m);
        
        for(auto a: m){
            if(a.second.first > 1) output.push_back(a.second.second);
        }
        
        return output;
    }
    
    string helper(TreeNode* root, unordered_map<string, pair<int, TreeNode*>> &m){
        if(!root) return "N";
        
        string l = helper(root->left, m);
        string r = helper(root->right, m);
        
        if(l == "N") l = "LN";
        if(r == "N") r = "RN";
        
        string temp = l + to_string(root->val) + r;
        
        // cout<<temp<<" ";
        
        m[temp].second = root; (m[temp].first)++;
        
        return temp;
    }
};