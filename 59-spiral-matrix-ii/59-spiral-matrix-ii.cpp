class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> output(n, vector<int>(n, 0));
        int rs = 0, cs = 0, re = output.size()-1, ce = output[0].size()-1;
        
        int val = 1;
        while(rs<=re and cs<=ce){
            for(int i=cs; i<=ce; i++){
                output[rs][i] = val;
                val++;
            }
            if(++rs > re) break;
            

            for(int i=rs; i<=re; i++){
                output[i][ce] = val; val++;
            }
            if(--ce < cs) break;
            
          
            for(int i=ce; i>=cs; i--){
                output[re][i] = val; val++;
            }
            if(--re < rs) break;
            
            
            for(int i=re; i>=rs; i--){
                output[i][cs] = val; val++;
            }
            if(++cs > ce) break;
        }
        
        return output;       
    }
};