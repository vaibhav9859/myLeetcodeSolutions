// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> output; list<int> lst;
        
        
        for(int i=0; i<k; i++){
            
            // for(auto &a: lst) cout<< arr[a]<<" ";
            // cout<<endl;
        
            if(lst.empty() or arr[lst.back()] >= arr[i]) lst.push_back(i);
            else{
                while(!lst.empty() and arr[lst.back()] < arr[i]){
                    lst.pop_back();
                }
                lst.push_back(i);
            }
        }
        
        output.push_back(arr[lst.front()]);
        
        for(int i=k; i<n; i++){
            
            // for(auto &a: lst) cout<< arr[a]<<" ";
            // cout<<endl;            
            
            if(lst.front() == i-k) lst.pop_front();
            if(lst.empty() or arr[lst.back()] >= arr[i]) lst.push_back(i);
            else{
                while(!lst.empty() and arr[lst.back()] < arr[i]){
                    lst.pop_back();
                }
                lst.push_back(i);
            }
            
            output.push_back(arr[lst.front()]);
        }
        // output.push_back(arr[lst.front()]);
        return output;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends