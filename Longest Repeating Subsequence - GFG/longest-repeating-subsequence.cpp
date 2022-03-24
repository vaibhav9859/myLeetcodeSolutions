// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
        int dp[1001][1001];
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    memset(dp, -1, sizeof(dp));
		    return helper(str, 0, 0, str.size());
		}
		
		int helper(string str, int i, int j, int sz){
		    
		    if(i==sz or j==sz) return 0;
		    
		    if(dp[i][j] != -1) return dp[i][j];
		    
		    if(i!= j and str[i] == str[j]){
		        return dp[i][j] = 1 + helper(str,i+1, j+1, sz);
		    }
		    else{
		        return dp[i][j] = max(helper(str, i+1, j, sz),
		                    helper(str, i, j+1, sz));
		    }
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends