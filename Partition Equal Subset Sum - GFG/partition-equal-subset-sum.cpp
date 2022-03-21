// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int equalPartition(int N, int arr[])
    {
        // code here
        int rows = 33000, cols = 101;
        vector<vector<int> > dp(rows, vector<int> (cols, -1));
        long long int rightSum = 0;
        for(int i=1; i<N; i++) rightSum += arr[i];
        
        return helper(N, arr, arr[0], rightSum, dp);
    }
    
    bool helper(int N, int arr[], long long int leftSum, long long int rightSum, vector<vector<int> > &dp, int i=1){
        if(leftSum == rightSum) return true;
        if(i==N) return false;
        
        if(dp[leftSum][i] != -1) return dp[leftSum][i];
        
        dp[leftSum][i] = ( helper(N, arr, leftSum + arr[i], rightSum - arr[i], dp, i+1) or
        helper(N, arr, leftSum, rightSum, dp, i+1) );
        
        return dp[leftSum][i];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends