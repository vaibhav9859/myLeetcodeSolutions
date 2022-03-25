// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numOfSubsets(int arr[], int N, int k) {
        // code here
        return helper(arr, N, k, 0, 1);
    }
    
    int helper(int arr[], int N, int k, int curPos, long long curProd){
        if(curPos == N) return 0;
        
        int x = 0, y = 0;
        if(curProd * arr[curPos] <= k){
            x = (1 + helper(arr, N, k, curPos+1, curProd * arr[curPos]));
        }
        // else{
            y = helper(arr, N, k, curPos+1, curProd);
        // }
        
        return x+y;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends