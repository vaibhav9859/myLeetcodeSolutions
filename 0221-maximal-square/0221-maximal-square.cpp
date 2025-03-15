class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxLen = 0;

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(row == 0 or col == 0) dp[row][col] = matrix[row][col] - '0';
                else {
                    if(matrix[row][col] == '1'){
                        dp[row][col] = 1 + min(dp[row-1][col], min(dp[row-1][col-1], dp[row][col-1]));
                    }
                }

                maxLen = max(maxLen, dp[row][col]);
            }
        }

        return maxLen*maxLen;
    }
};