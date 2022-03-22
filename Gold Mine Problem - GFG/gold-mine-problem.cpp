// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> vec(n, vector<int> (m, 0));
        
        for(int row=0; row<n; row++){
            vec[row][m-1] = M[row][m-1];
        }
        
        for(int col = m-2; col>=0; col--){
            for(int row=0; row<n; row++){
                int temp = 0;
                if(row-1>=0) temp = max(temp, vec[row-1][col+1]);
                temp = max(temp, vec[row][col+1]);
                if(row+1 < n) temp = max(temp, vec[row+1][col+1]);
                
                vec[row][col] = M[row][col] + temp;
            }
        }
        
        
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<vec[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int finalAns = 0;
        for(int row=0; row<n; row++){
            finalAns = max(finalAns, vec[row][0]);
        }
        
        return finalAns;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends