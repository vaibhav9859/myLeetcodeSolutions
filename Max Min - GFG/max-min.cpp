// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	if(N == 1) return A[0] + A[0];
    	int minVal, maxVal;
    	
	    if(A[0] <= A[1]){
	        minVal = A[0];
	        maxVal = A[1];
	    }        
	    else{
	        minVal = A[1];
	        maxVal = A[0];
	    }
    	
    	for(int i=2; i<N; i++){
            if(A[i] < minVal) minVal = A[i];
            else if(A[i] > maxVal){
                maxVal = A[i];
            }
    	}
    	
    	return maxVal + minVal;
    }

};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends