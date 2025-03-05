class Solution {
public:
    int rows;
    int cols;
    set<vector<pair<int, int>>> islandsSet;
    vector<vector<int>> vis;
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vis.assign(rows, vector<int>(cols, 0));

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(vis[row][col] == 0 and grid[row][col] == 1){
                    vis[row][col] = 1;
                    vector<pair<int,int>> curTrav;
                    curTrav.push_back({0, 0});
                    dfs(grid, row, col, row, col, curTrav);
                    islandsSet.insert(curTrav);
                }
            }
        }

        return islandsSet.size();
    }

    void dfs(vector<vector<int>>& grid, int baseRow, int baseCol, int row, int col, vector<pair<int,int>> &curTrav){

        for(int i=0; i<4; i++){
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];

            if(newRow >= 0 and newCol >= 0 and newRow < rows and newCol < cols and !vis[newRow][newCol] and grid[newRow][newCol]){
                vis[newRow][newCol] = 1;
                curTrav.push_back({newRow-baseRow, newCol-baseCol});
                dfs(grid, baseRow, baseCol, newRow, newCol, curTrav);
            }
        }
    }
};