// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int m = s.size()+1, n = t.size()+1;
        int arr[m][n];
        
        // int fi = 0, si = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0){
                    arr[i][j] = j; continue;
                }
                if(j==0){
                    arr[i][j] = i; continue;
                }
                
                
                int temp = min( arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1]) );
                if(s[i-1] == t[j-1]){
                    // fi++; si++;
                    arr[i][j] = arr[i-1][j-1];
                }
                else{
                    arr[i][j] = temp+1;
                }
            }
        }
        
        
 
        return arr[m-1][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends