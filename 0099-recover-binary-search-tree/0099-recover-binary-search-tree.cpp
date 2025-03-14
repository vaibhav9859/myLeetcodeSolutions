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
void inorder(TreeNode* root, vector<int> &arr){
	if(!root) return;

	inorder(root->left, arr);
	arr.push_back(root->val);
	inorder(root->right, arr);
}

void inorderPut(TreeNode* root, vector<int> &arr, int &idx){
	if(!root) return;

	inorderPut(root->left, arr, idx);
	root->val = arr[idx];
	idx++;
	inorderPut(root->right, arr, idx);
}



void recoverTree(TreeNode* root){
	vector<int> arr;
// inorder traversal
	inorder(root, arr);

// sort	
	sort(arr.begin(), arr.end());

	

	// inorder traveral
	int idx = 0;
inorderPut(root, arr, idx);

}

};