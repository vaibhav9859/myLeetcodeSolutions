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
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        int val = camNeed(root, count);
        if(val==-1) return ++count;
        
        return count;
    }
    
    
    int camNeed(TreeNode* root, int &count){
        if(!root) return 1;
        if(!root->left and !root->right) return -1;
        
        int l = camNeed(root->left, count);
        int r = camNeed(root->right, count);
        
        
        if(l == -1 or r==-1){
            count++;
            return 0;
        }
        
        else if(l==1 and r==1){
            return -1;
        }
        
        return 1;
    }
};