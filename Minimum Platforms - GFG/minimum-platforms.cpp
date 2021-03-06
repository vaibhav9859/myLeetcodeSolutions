// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // int findPlatform(int arr[], int dep[], int n)
    // {
        
    // 	sort(arr, arr+n);
    // 	sort(dep, dep+n);
    // 	int mp = 0, np = 0;
    	
    // 	for(int i=0, j =0; i<n and j<n; ){
    // 	    if(arr[i] <= dep[j]){
    // 	        i++; mp++;
    // 	        if(np<mp) np = mp;
    // 	    }
    // 	    else if(arr[i]>dep[j]){
    // 	        j++; mp--;
    // 	       // if(np<mp) np = mp;
    // 	    }
    // 	}
    	
    // 	return np;
    // }
    
    int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr+n); sort(dep, dep+n);
    int curpt = 0, maxpt = 0;
    for(int i=0, j=0; i<n and j<n; ){
        if(arr[i]<=dep[j]){
            curpt++; if(maxpt<curpt) maxpt = curpt;
            i++;
        }
        else{
            curpt--; j++;
        }
    }

    return maxpt;
}

};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends