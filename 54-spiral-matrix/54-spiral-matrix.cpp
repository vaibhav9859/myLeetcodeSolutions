class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int rs = 0, cs = 0, re = matrix.size()-1, ce = matrix[0].size()-1;
        
        
        while(rs<=re and cs<=ce){
            for(int i=cs; i<=ce; i++){
                output.push_back(matrix[rs][i]);
            }
            rs++;

            for(int i=rs; i<=re; i++){
                output.push_back(matrix[i][ce]);
            }
            ce--;
            
            if(rs>re or cs>ce) break;
            for(int i=ce; i>=cs; i--){
                output.push_back(matrix[re][i]);
            }
            re--;
            
            if(rs>re or cs>ce) break;
            for(int i=re; i>=rs; i--){
                output.push_back(matrix[i][cs]);
            }
            cs++;
        }
        
        return output;
    }
};