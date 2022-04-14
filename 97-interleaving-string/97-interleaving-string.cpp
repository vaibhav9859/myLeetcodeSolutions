class Solution {
public:
    int dp[101][101][201];
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0, 0);
    }
    
    
    bool helper(string s1, string s2, string s3, int fptr, int sptr, int tptr){
        
        if(fptr == s1.size() and sptr == s2.size() and tptr == s3.size()) return true;
        
        // if(tptr == s3.size()) return false;
        
        if(dp[fptr][sptr][tptr] != -1) return dp[fptr][sptr][tptr];
        
        bool opt1 = false, opt2 = false;
        
        if(fptr < s1.size() and s3[tptr] == s1[fptr]) opt1 = helper(s1, s2, s3, fptr+1, sptr, tptr+1);
        if(sptr < s2.size() and s3[tptr] == s2[sptr]) opt2 = helper(s1, s2, s3, fptr, sptr+1, tptr+1);
        
        return dp[fptr][sptr][tptr] = opt1 or opt2;
    }
};