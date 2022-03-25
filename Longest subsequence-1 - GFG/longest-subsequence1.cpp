// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        
        helper(N, A, -1, 0);
    }
    
    int helper(int N, int A[], int prevPos, int curPos){
        if(curPos == N) return 0;
        
        if(prevPos == -1 or abs(A[curPos] - A[prevPos]) == 1){
           return max(1 + helper(N, A, curPos, curPos+1), 
                        helper(N, A, prevPos, curPos+1 ));
        }
        else{
            return helper(N, A, prevPos, curPos+1);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends