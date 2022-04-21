// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// This function returns the sum of elements on maximum path
	// from beginning to end
	int maxPathSum(int arr1[], int arr2[], int m, int n) {
	    // code here
	    
	    int i = 0, j = 0;
	    long sum1 = 0, sum2 = 0, finalAns = 0;
	    
	    for(; i<m and j<n;){
	        if(arr1[i] < arr2[j]){
	            sum1 += arr1[i]; i++;
	        }
	        else if(arr1[i] > arr2[j]){
	            sum2 += arr2[j]; j++;
	        }
	        else{
	            finalAns += max(sum1, sum2);
	            finalAns += arr1[i]; sum1 = sum2 = 0;
	            i++; j++;
	        }
	    }
	    
	    while(i<m) {sum1 += arr1[i]; i++;}
	    while(j<n) {sum2 += arr2[j]; j++;}
	    
	    finalAns += max(sum1, sum2);
	    
	    return finalAns;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maxPathSum(arr1, arr2, m, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends