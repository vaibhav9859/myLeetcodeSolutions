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
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* middle = NULL; TreeNode* last = NULL;
        TreeNode* prev = NULL;
        
        inorder(root, first, middle, last, prev);
        
        if(last) swap(last->val, first->val);
        else swap(first->val, middle->val);
    }
    
    void inorder(TreeNode* root, TreeNode* &first, TreeNode* &middle, TreeNode* &last, TreeNode* &prev){
        
        if(!root) return;
        
        
        inorder(root->left, first, middle, last, prev);
        
        if(!prev) prev = root;
        if(root->val < prev->val){
            if(!first){
                first = prev; middle = root;
            }
            else{
                last = root; return;
            }
        }
        
        prev = root;
        
        inorder(root->right, first, middle, last, prev);
    }
    
    
};