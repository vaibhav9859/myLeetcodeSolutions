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
class BSTIterator {
public:
    TreeNode* root;
    vector<TreeNode*> travSaved;
    int curPos = 0;
    
    BSTIterator(TreeNode* root) {
        this->root = root;
        
        inorder(root);
    }
    
    void inorder(TreeNode* root){
        if(!root){return;}
        
        inorder(root->left);
        
        travSaved.push_back(root);
        
        inorder(root->right);
    }
    
    int next() {
        return travSaved[curPos++]->val; 
    }
    
    bool hasNext() {
        if(curPos >= travSaved.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */