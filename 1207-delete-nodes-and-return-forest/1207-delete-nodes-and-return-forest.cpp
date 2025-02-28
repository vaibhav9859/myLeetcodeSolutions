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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> uniqueSet;
        vector<TreeNode*> allRoots;

        for(auto &val: to_delete){
            uniqueSet.insert(val);
        }

        if(uniqueSet.find(root->val) == uniqueSet.end()){
            allRoots.push_back(root);
        }

        getRoots(root, uniqueSet, allRoots);

        return allRoots;
    }

    TreeNode* getRoots(TreeNode* root, unordered_set<int>& uniqueSet, vector<TreeNode*>& allRoots){
        if(!root) return root;

        TreeNode* leftRoot = getRoots(root->left, uniqueSet, allRoots);
        TreeNode* rightRoot = getRoots(root->right, uniqueSet, allRoots);

        if(uniqueSet.find(root->val) != uniqueSet.end()){
            if(leftRoot) allRoots.push_back(leftRoot);
            if(rightRoot) allRoots.push_back(rightRoot);

            return NULL;
        }
        else{
            root->left = leftRoot;
            root->right = rightRoot;
        }

        return root;
    }
};