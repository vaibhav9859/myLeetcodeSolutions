// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int sz = q.size(); int flag = 0;
            for(int i=0; i<sz; i++){
                int curRow = q.front().first, curCol = q.front().second;
                q.pop();
                
                if(curCol+1 < m and grid[curRow][curCol+1] == 1){
                    grid[curRow][curCol+1] = 2;
                    q.push({curRow, curCol+1});
                    flag = 1;
                }
                if(curCol-1 >= 0 and grid[curRow][curCol-1] == 1){
                    grid[curRow][curCol-1] = 2;
                    q.push({curRow, curCol-1});
                    flag = 1;
                }
                 if(curRow+1 < n and grid[curRow+1][curCol] == 1){
                    grid[curRow+1][curCol] = 2;
                    q.push({curRow+1, curCol});
                    flag = 1;
                }
                if(curRow-1 >= 0 and grid[curRow-1][curCol] == 1){
                    grid[curRow-1][curCol] = 2;
                    q.push({curRow-1, curCol});
                    flag = 1;
                }  
            
            }
        
            if(flag) ans++;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends