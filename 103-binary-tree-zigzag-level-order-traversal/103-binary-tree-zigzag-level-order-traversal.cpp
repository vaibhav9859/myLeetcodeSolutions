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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(!root) return output;
        
        queue<TreeNode*> q;
        q.push(root); bool leftToRight = true;
        
        while(!q.empty()){
            int qSize = q.size(); vector<int> curLev;
            for(int i=0; i<qSize; i++){
                TreeNode* curNode = q.front(); q.pop();
                curLev.push_back(curNode->val);
                
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            
            if(leftToRight) output.push_back(curLev);
            else{
                reverse(curLev.begin(), curLev.end());
                output.push_back(curLev);
            }
            
            leftToRight = !leftToRight;
        }
        
        return output;
    }
};