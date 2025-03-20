class Solution{
public:
	int rows;
	int cols;
	vector<vector<int>> vis;
	vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0} };

	bool checkEdge(int row, int col){
        if(row == 0 or col == 0 or row == rows-1 or col == cols-1) return true;
        return false;
    }

	int closedIsland(vector<vector<int>> &grid){
        int count = 0;
        rows = grid.size();
        cols = grid[0].size();
        vis.assign(rows, vector<int>(cols, 0));

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 0 and vis[row][col] == 0){
                    vis[row][col] = 1;
                    bool isOnEdge = false;
                    if(checkEdge(row, col)) isOnEdge =true;
                    dfs(grid, row, col, isOnEdge);

                    if(isOnEdge == 0) count++;
                }
        }
    }
        

        return count;

}

void dfs(vector<vector<int>> &grid, int row, int col, bool &isOnEdge){
        for(int i=0; i<4; i++){
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];

            if(newRow >=0 and newCol >=0 and newRow < rows and newCol < cols and vis[newRow][newCol] == 0 and grid[newRow][newCol] == 0){
                vis[newRow][newCol] = 1;
                if(checkEdge(newRow, newCol)) isOnEdge =true;
                dfs(grid, newRow, newCol, isOnEdge);
            }
    }
}

};

