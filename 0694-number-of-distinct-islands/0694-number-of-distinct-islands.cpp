class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        string dirStr = "RDLU";
        
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 1 and !vis[row][col]){
                    vis[row][col] = 1;
                    string curDir;
                    dfs(grid, row, col, vis, islands, dir, dirStr, curDir);
                    islands.insert(curDir);
                }
            }
        }

        return islands.size();
    }

    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vis, unordered_set<string>& islands, vector<vector<int>> &dir, string &dirStr, string &curDir){
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0; i<4; i++){
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];

            if(newRow >= 0 and newCol >=0 and newRow < rows and newCol < cols and grid[newRow][newCol] == 1 and vis[newRow][newCol] == 0){
                vis[newRow][newCol] = 1;
                curDir += dirStr[i];
                dfs(grid, newRow, newCol, vis, islands, dir, dirStr, curDir);
                curDir += 'B';
            }
        }

        
    }
};