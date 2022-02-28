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
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        helper(root, prev);
        
        return;
    }
    
    void helper(TreeNode* root, TreeNode* &prev){
        if(!root) return;
        
        TreeNode* curRight = root->right; 
        if(prev){
            prev->right = root;
            prev->left = NULL;
        }
        
        prev = root;
        
        helper(root->left, prev);
        helper(curRight, prev);
    }
};