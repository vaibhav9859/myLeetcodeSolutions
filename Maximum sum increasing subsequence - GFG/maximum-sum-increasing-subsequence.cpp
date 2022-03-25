// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    return helper(arr, n, -1, 0, dp);
	}
	
	int helper(int arr[], int n, int prev, int curPos, vector<vector<int>> &dp){
	    if(curPos == n) return 0;
	    
	    if(prev != -1 and dp[prev][curPos] != -1) return dp[prev][curPos];
	    
	    if(prev == -1 or arr[prev] < arr[curPos]){
	        int temp = max(arr[curPos] + helper(arr, n, curPos, curPos+1, dp),
	        helper(arr, n, prev, curPos+1, dp));
	        if(prev != -1) dp[prev][curPos] = temp;
	    }
	    else{
	        return dp[prev][curPos] = helper(arr, n, prev, curPos+1, dp);
	    }
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends