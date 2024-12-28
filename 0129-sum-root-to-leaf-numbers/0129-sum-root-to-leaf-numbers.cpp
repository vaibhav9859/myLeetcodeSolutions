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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0);

        return ans;
    }

    void helper(TreeNode* root, int &ans, int curSum){
        if(!root) return;
        if(!root->left and !root->right){
            ans += (curSum * 10) + root->val;
        }

        int newSum = curSum * 10 + root->val;

        helper(root->left, ans, newSum);
        helper(root->right, ans, newSum);

        return;
    }
};