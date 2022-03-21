// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
    
//     int dp[1001][1001];

//     int equalPartition(int N, int arr[])
//     {
//         // code here
        
//         memset(dp, -1, sizeof(dp));
        
//         int rightSum = 0;
//         for(int i=1; i<N; i++) rightSum += arr[i];
        
//         return helper(N, arr, arr[0], rightSum);
//     }
    
//     bool helper(int N, int arr[], int leftSum, int rightSum, int i=1){
//         if(leftSum == rightSum) return true;
//         if(i==N) return false;
        
//         if(dp[leftSum][i] != -1) return dp[leftSum][i];
        
//         return dp[leftSum][i] = ( helper(N, arr, leftSum + arr[i], rightSum - arr[i], i+1) or
//         helper(N, arr, leftSum, rightSum, i+1) );
//     }
// };

class Solution{
public:
   int dp[101][10001];
   bool helper(int N,int arr[],int sum)
   {
           
       if(sum==0)
           return true;
       
       if(N==0)
           return false;
       
       if(dp[N][sum]!=-1)
           return dp[N][sum];
       
       if(arr[N-1]<=sum)
           return dp[N][sum]=helper(N-1,arr,sum-arr[N-1]) || helper(N-1,arr,sum);
       
       else if(arr[N-1]>sum)
           return dp[N][sum]=helper(N-1,arr,sum);
       
       
   }
   bool isSubsetSum(int N,int arr[],int sum)
   {
       memset(dp,-1,sizeof(dp));
       return helper(N,arr,sum);
   }
   int equalPartition(int N, int arr[])
   {
      long long int sum(0);
       sum=accumulate(arr,arr+N,sum);
       
       if(sum%2!=0)
           return false;
       
       else if(sum%2==0)
           return isSubsetSum(N,arr,sum/2);
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