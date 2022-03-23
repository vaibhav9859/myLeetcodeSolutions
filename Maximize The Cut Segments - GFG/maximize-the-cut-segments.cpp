// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10004];
    int maximizeTheCuts(int n, int x, int y, int z){
        //Your code here
        memset(dp, -1, sizeof(dp));
   
        
        int ans = helper(n, x, y, z);
        if(ans < 0) return 0;
        return ans;
        
    }
    
    int helper(int n, int x, int y, int z, int seg = 0){
        if(n<0) return INT_MIN;
        if(n==0) { return 0;}
        
        if(dp[n] != -1) return dp[n];
 

        int temp1 = helper(n-x, x, y, z);
  
        int temp2 = helper(n-y, x, y, z);
  
        int temp3 = helper(n-z, x, y, z);
        
        dp[n] = 1+max(temp1, max(temp2, temp3));
        
      
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends