class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<bool> colAr(n, true); vector<bool> lDiag(2*n-1, true); vector<bool> rDiag(2*n-1, true);
        vector<string> curStrVec;
        helper(n, 0, 0, colAr, lDiag, rDiag, output, curStrVec);
        return output;
    }
    
    void helper(int n, int rowNo, int colNo, vector<bool> &colAr, vector<bool> &lDiag, vector<bool> &rDiag, vector<vector<string>> &output, vector<string> curStrVec){
        if(rowNo == n){
            output.push_back(curStrVec);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(colAr[j] and lDiag[rowNo + j] and rDiag[rowNo - j + n - 1]){
                colAr[j] = false;
                lDiag[rowNo + j] = false;
                rDiag[rowNo - j + n - 1] = false;
                
                string temp; for(int it = 0; it<n; it++){temp+=".";}
                temp[j] = 'Q'; curStrVec.push_back(temp);
                helper(n, rowNo+1, 0, colAr, lDiag, rDiag, output, curStrVec);
                if(!curStrVec.empty()) curStrVec.pop_back();
                
                colAr[j] = true;
                lDiag[rowNo + j] = true;
                rDiag[rowNo - j + n - 1] = true;                
            }
        }
    }
};