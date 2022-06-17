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
        
        //Below addition is done coz
        //When current node's both left and right child were covered
        //the current node told to its parent that we need a camera
        //this addition here will be needed 
        //when root nodes return -1, which means
        //root node says to its parent that it requires a camera
        if(val == -1) count++;
        return count;
    }
    
    
    int cameraNeed(TreeNode* root, int &count){

        if(!root) return 1;
        if(!root->left and !root->right) return -1;
        
        int leftNeed = cameraNeed(root->left, count);
        int rightNeed = cameraNeed(root->right, count);
        
        //When any of the child node says it needs camera
        if(leftNeed == -1 or rightNeed == -1){
            count++;
            return 0;
            
        }
        // When both children say they are covered
        // so present node tells its parent that we need camera
        //but present node does not directly but the camera at its position
        else if(leftNeed == 1 and rightNeed == 1){
            return -1;
        }
        
        //Otherwise we know that we need to return present node is covered
        return 1;
    }
};