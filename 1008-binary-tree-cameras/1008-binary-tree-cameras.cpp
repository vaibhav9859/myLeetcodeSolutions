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
        if(!root->left and !root->right) return 1;
        int camCount = 0;
        pair<int, int> reqDetails = helper(root, camCount);

        if(reqDetails.first and !reqDetails.second){
            camCount++;
        }

        return camCount;
    }

    pair<int, int> helper(TreeNode* root, int &camCount){
        if(!root) return {0, 0};

        pair<int, int> left = helper(root->left, camCount);
        pair<int, int> right = helper(root->right, camCount);

        int leftReq = left.first;
        int rightReq = right.first;
        int leftCov = left.second;
        int rightCov = right.second;

        if(leftReq or rightReq){
            camCount++;
            return {0, 1};
        } else{
            if(leftCov or rightCov){
                return{0, 0};
            }
        }

        // if(leftReq or rightReq){
        //     if(leftCov or rightCov){
        //         return {1, 0};
        //     } else {
        //         camCount++;
        //         return{0, 1};
        //     } 
        // } else {
        //     if(leftCov or rightCov) return {0, 0};
        // }

        // return {1, 0};

        return {1, 0};
    }
};