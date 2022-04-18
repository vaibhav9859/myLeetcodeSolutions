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
    void helper(TreeNode* root, int k, int &ans , int &i){
        if(!root) return;
        helper(root->left, k, ans, i);
        
        
        if(i==k){
            ans = root->val; 
        }
        i = i+1;
        
        helper(root->right, k, ans, i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MAX, i=1;
        bool flag = false;
        helper(root, k, ans, i);
        return ans;
    }
};