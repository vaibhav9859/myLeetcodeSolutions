// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define MOD 1000000007


class Solution{
public:
    int nCr(int n, int r){
        // code here
        vector<int> dp(r+1, 0);
        dp[0] = 1;

        for(int i=0; i<n; i++){
            for(int j=r; j-1>=0; j--){
                dp[j] = (dp[j]%MOD + dp[j-1]%MOD)%MOD;
            }
            

        }
        
        
        return dp[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends