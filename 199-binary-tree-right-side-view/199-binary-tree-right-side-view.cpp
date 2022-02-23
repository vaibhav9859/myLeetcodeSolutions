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
    
    void rvHelper(TreeNode* root, vector<int> &output, int &maxHTN, int curH = 0){
        if(!root) return;
        
        if(curH > maxHTN){
            maxHTN = curH; output.push_back(root->val);
        }
        
        rvHelper(root->right, output, maxHTN, curH+1);
        rvHelper(root->left, output, maxHTN, curH+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output; int maxHTN = -1;
        rvHelper(root, output, maxHTN);
        
        return output;
    }
};