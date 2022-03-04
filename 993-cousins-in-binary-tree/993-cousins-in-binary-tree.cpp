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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x or root->val == y) return false;
        
        int levX = -1, levY = -2; TreeNode* parX = NULL; TreeNode* parY = NULL;
        
        trav(root, x, y, 0, root, levX, levY, parX, parY);
        
        if(levX == levY and parX != parY) return true;
        
        return false;
    }
    
    void trav(TreeNode* root, int x, int y, int curLev, TreeNode* par, int &levX, int &levY, TreeNode* &parX, TreeNode* &parY){
        if(!root) return;
        
        if(root->val == x){
            levX = curLev; parX = par;
        }
        if(root->val == y){
            levY = curLev; parY = par;
        }
        
        trav(root->left, x, y, curLev+1, root, levX, levY, parX, parY);
        trav(root->right, x, y, curLev+1, root, levX, levY, parX, parY);
    }
};