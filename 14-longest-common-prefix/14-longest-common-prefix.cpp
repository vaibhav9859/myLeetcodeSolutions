class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        for(int col = 0; col<strs[0].size(); col++){
            char curChar = strs[0][col];
            for(int row = 1; row < strs.size(); row++){
               if(strs[row][col] != curChar) return ans;
            }
            
            ans += curChar;
       } 
        
        return ans;
    }
};