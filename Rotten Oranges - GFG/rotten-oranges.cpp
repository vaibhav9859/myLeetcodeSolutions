// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int flag = 0;
                int curRow = q.front().first, curCol = q.front().second;
                q.pop();
                
                if(curCol+1 < m and grid[curRow][curCol+1] == 1){
                    grid[curRow][curCol+1] = 2;
                    q.push({curRow, curCol+1});
                }
                if(curCol-1 >= 0 and grid[curRow][curCol-1] == 1){
                    grid[curRow][curCol-1] = 2;
                    q.push({curRow, curCol-1});
                }
                 if(curRow+1 < n and grid[curRow+1][curCol] == 1){
                    grid[curRow+1][curCol] = 2;
                    q.push({curRow+1, curCol});
                }
                if(curRow-1 >= 0 and grid[curRow-1][curCol] == 1){
                    grid[curRow-1][curCol] = 2;
                    q.push({curRow-1, curCol});
                }  
            
            }
            ans++;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return --ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends