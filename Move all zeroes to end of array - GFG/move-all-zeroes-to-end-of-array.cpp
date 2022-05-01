// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i, j;
	    for(i=0, j=0; i<n and j<n; ){
            while(j<n and arr[j] == 0){
                j++;
            }
            
            if(j<n and arr[j] != 0){
                arr[i] = arr[j]; i++; j++;
            }
            
            // while(i<n and arr[i] != 0) i++;
	    }
	    
	    while(i<n){
	        arr[i] = 0; i++;
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends