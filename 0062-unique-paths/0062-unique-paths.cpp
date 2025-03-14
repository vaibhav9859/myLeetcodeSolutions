class Solution {
public:
    int uniquePaths(int rows, int cols) {
        if(rows == 1 or cols==1) return 1;
	
	vector<vector<int>> dp(rows, vector<int>(cols, 1));

	for(int row=1; row<rows; row++){
		for(int col=1; col<cols; col++){
	dp[row][col] = dp[row-1][col] + dp[row][col-1];
}
}

return dp[rows-1][cols-1];

    }
};