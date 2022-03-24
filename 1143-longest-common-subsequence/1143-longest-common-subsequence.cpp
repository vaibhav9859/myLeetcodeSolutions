class Solution {
public:
    int dp[1003][1003];
    int longestCommonSubsequence(string &text1, string &text2, int i=0, int j=0,int flag = 1) {
        if(flag) {flag = 0; memset(dp, -1, sizeof(dp));}
        
        if(i == text1.size() or j == text2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j]){
            return dp[i][j] = 1+longestCommonSubsequence(text1, text2, i+1, j+1, 0);
        }
        else{
            return dp[i][j] = max(longestCommonSubsequence(text1, text2, i+1, j, 0),
                                    longestCommonSubsequence(text1, text2, i, j+1, 0));
        }
    }
};