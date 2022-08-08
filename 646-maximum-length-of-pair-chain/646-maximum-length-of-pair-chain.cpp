class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<pair<int, int>> prs;
    	
    	for(int i=0; i<n; i++){
    		prs.push_back({pairs[i][0], pairs[i][1]});
    	}
    	
    	sort(prs.begin(), prs.end());
    	
    	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    	
    	return recFun(prs, 0, -1, n, dp);
    }
    
    int recFun(vector<pair<int, int>> &prs, int curPos, int prevPos, int n, vector<vector<int>> &dp){
    	if(curPos == n) return 0;
    
        if(prevPos != -1 and dp[curPos][prevPos] != -1) return dp[curPos][prevPos];
        	
    	int pick = 0;
    	int notPick = 0;
    
    	if(prevPos == -1 or (prs[prevPos].second < prs[curPos].first)) 
    		pick = 1 + recFun(prs, curPos+1, curPos, n, dp);
    	
    	
    	notPick = recFun(prs, curPos+1, prevPos, n, dp);
    	
    	if(prevPos != -1) dp[curPos][prevPos] =  max(pick, notPick);
    	
    	return max(pick, notPick);
    }

};