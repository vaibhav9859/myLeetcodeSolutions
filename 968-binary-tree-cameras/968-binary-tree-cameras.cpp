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
        int count = 0;
        
        if(!root) return 0;
        if(root and !root->left and !root->right) return 1;
        int val = cameraNeed(root, count);
        
        if(val == -1) count++;
        return count;
    }
    
    
    int cameraNeed(TreeNode* root, int &count){
        // cout<<count<<" ";
        if(!root) return 1;
        if(!root->left and !root->right) return -1;
        
        int leftNeed = cameraNeed(root->left, count);
        int rightNeed = cameraNeed(root->right, count);
        
        if(leftNeed == -1 or rightNeed == -1){
            count++;
            return 0;
            
        }else if(leftNeed == 1 and rightNeed == 1){
            return -1;
        }
        
        return 1;
    }
};