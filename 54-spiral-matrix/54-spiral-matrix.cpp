class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int rs = 0, cs = 0, re = matrix.size()-1, ce = matrix[0].size()-1;
        
        
        while(rs<=re and cs<=ce){
            for(int i=cs; i<=ce; i++){
                output.push_back(matrix[rs][i]);
            }
            if(++rs > re) break;
            

            for(int i=rs; i<=re; i++){
                output.push_back(matrix[i][ce]);
            }
            if(--ce < cs) break;
            
          
            for(int i=ce; i>=cs; i--){
                output.push_back(matrix[re][i]);
            }
            if(--re < rs) break;
            
            
            for(int i=re; i>=rs; i--){
                output.push_back(matrix[i][cs]);
            }
            if(++cs > ce) break;
        }
        
        return output;
    }
};