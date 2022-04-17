// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int rPos, cPos, reqRPos, reqCPos;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    rPos = i, cPos = j;
                } 
                else if(grid[i][j] == 2){
                    reqRPos = i, reqCPos = j;
                }
            }
        }
        
        return isReach(grid, reqRPos, reqCPos, rPos, cPos, grid.size(), grid[0].size());
    }
    
    
    bool isReach(vector<vector<int>>& grid, int reqRPos, int reqCPos, int rPos, int cPos, int nRows, int nCols){
        
        if(rPos == reqRPos and cPos == reqCPos) return true;
        
        if(rPos<0 or rPos>=nRows or cPos<0 or cPos>=nCols or grid[rPos][cPos] == -1 or grid[rPos][cPos] == 0){
            return false;
        }
        
        int val = grid[rPos][cPos]; grid[rPos][cPos] = -1; 
        
        if(isReach(grid, reqRPos, reqCPos, rPos, cPos+1, nRows, nCols) or
        isReach(grid, reqRPos, reqCPos, rPos+1, cPos, nRows, nCols) or
        isReach(grid, reqRPos, reqCPos, rPos, cPos-1, nRows, nCols) or
        isReach(grid, reqRPos, reqCPos, rPos-1, cPos, nRows, nCols)  ) return true;
        
        grid[rPos][cPos] = val;
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends