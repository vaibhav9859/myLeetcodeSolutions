// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int sz = arr.size(); int flag = 0;
        // int minVal = INT_MAX;
        for(int i=sz-2; i>=0; i--){
            // minVal = min(minVal, arr[i-1]);
            if(arr[i] < arr[i+1]){
                flag = 1;
                // swap(arr[i], arr[sz-1]);
                
                for(int it = sz-1; it>=i+1; it--){
                    if(arr[it] > arr[i]) {swap(arr[i], arr[it]); break;}
                }
                
                reverse(arr.begin()+i+1, arr.end());
                break;
            }

        }
        
        if(!flag) reverse(arr.begin(), arr.end());
        
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends