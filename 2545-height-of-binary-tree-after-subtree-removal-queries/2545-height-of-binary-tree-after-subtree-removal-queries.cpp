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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> nodeLevel;
        unordered_map<int, int> nodeHeight;
        unordered_map<int, pair<int, int>> levelTop2Hts;

        vector<int> output;

        grabData(root, 0, nodeLevel, nodeHeight, levelTop2Hts);

        for(int i=0; i<queries.size(); i++){
            int curQ = queries[i];

            int level = nodeLevel[curQ];
            int ht = nodeHeight[curQ];

            if(levelTop2Hts[level].first == ht){
                output.push_back(level + levelTop2Hts[level].second - 1);
            }
            else{
                output.push_back(level + levelTop2Hts[level].first - 1);
            }
        }

        return output;
    }

    int grabData(TreeNode* root, int curLevel, unordered_map<int, int> &nodeLevel, unordered_map<int, int> &nodeHeight, unordered_map<int, pair<int, int>> &levelTop2Hts){
        if(!root) return 0;

        int leftHt = grabData(root->left, curLevel+1, nodeLevel, nodeHeight, levelTop2Hts);
        int rightHt = grabData(root->right, curLevel+1, nodeLevel, nodeHeight, levelTop2Hts);
        
        int curVal = root->val;
        nodeLevel[curVal] = curLevel;
        nodeHeight[curVal] = 1 + max(leftHt, rightHt);

        if(levelTop2Hts.find(curLevel) == levelTop2Hts.end()) {
            levelTop2Hts[curLevel].first = nodeHeight[curVal];
            levelTop2Hts[curLevel].second = 0;
        }
        else {
            if(nodeHeight[curVal] > levelTop2Hts[curLevel].first){
                levelTop2Hts[curLevel].second = levelTop2Hts[curLevel].first;
                levelTop2Hts[curLevel].first = nodeHeight[curVal];
            }
            else if(nodeHeight[curVal] > levelTop2Hts[curLevel].second){
                levelTop2Hts[curLevel].second = nodeHeight[curVal];
            }
        }

        return nodeHeight[curVal];
    }
};