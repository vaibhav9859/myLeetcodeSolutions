// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> output;
        sumHelper(arr, N, 0, 0, output);
        return output;
    }
    
    void sumHelper(vector<int> &arr, int n, int index, int sum, vector<int> &output){
        if(index == n){
            output.push_back(sum);
            return;
        }
    
        sumHelper(arr, n, index+1, sum, output);
        
        sum += arr[index];
        sumHelper(arr, n, index+1, sum, output);
        sum -= arr[index];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends