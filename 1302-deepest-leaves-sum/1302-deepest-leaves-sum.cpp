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
    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> sumMap;
        int ans = 0;
        preOrder(root, sumMap, ans, 1);   
        
        return sumMap[ans];
    }
    
    void preOrder(TreeNode* root, unordered_map<int, int> &sumMap, int &ans, int curLev){
        if(!root) return;
        
        if(!root->left and !root->right){
            sumMap[curLev] += root->val;
            ans = max(ans, curLev);
        }
        
        preOrder(root->left, sumMap, ans, curLev+1);
        preOrder(root->right, sumMap, ans, curLev+1);
    }
};