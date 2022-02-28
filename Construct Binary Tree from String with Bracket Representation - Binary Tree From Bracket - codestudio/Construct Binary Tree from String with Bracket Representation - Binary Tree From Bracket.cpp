BinaryTreeNode<int>* helper(string &str, int &i, int &strLen){
    
    if(i>=strLen) return NULL;
    
    bool neg = false;
    if(str[i] == '-'){ neg = true; i++;}
    
    int curNum = 0; bool isNum = false;
    while(i<strLen and str[i]>= '0' and str[i] <= '9'){
        isNum = true;
        curNum = (curNum * 10) + (int)(str[i] - '0');
        i++;
    }
    if(neg) curNum = -1 * curNum;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(curNum);
    
    if(i >= strLen) return root;
    
    if(i<strLen and str[i] == '('){
        i++;
        root->left = helper(str, i, strLen);
    }
        
    if(i<strLen and str[i] == ')'){
        i++; 
        if(!isNum) return NULL;
        return root;
    }
    
    if(i<strLen and str[i] == '('){
        i++; root->right = helper(str, i, strLen);
    }
    
    if(i<strLen and str[i] == ')'){
        i++; return root;
    }
    
    return root;
}

BinaryTreeNode<int>* treeFromBracket(string &str)
{
    int i = 0; int strLen = str.length();
    BinaryTreeNode<int> * root = helper(str, i, strLen);
}