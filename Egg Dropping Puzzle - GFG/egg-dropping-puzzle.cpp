// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, dp);
    }
    int helper(int eggs, int floors, vector<vector<int>> &dp){
        if(eggs == 1 or floors == 1 or floors == 0) return floors;
        int ans = INT_MAX;
        
        if(dp[eggs][floors] != -1) return dp[eggs][floors]; 
        
        for(int k=1; k<=floors; k++){
            int temp = 1 +  max(helper(eggs-1, k-1, dp), helper(eggs, floors-k, dp) ) ;
            
            ans = min(temp, ans);
        }
        
        return dp[eggs][floors] = ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends