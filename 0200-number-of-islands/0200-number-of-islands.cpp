class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    count++;
                    grid[row][col] = '2';
                    dfs(grid, row, col, rows, cols);
                }
            }
        }   

        return count;
    }

    void dfs(vector<vector<char>>& grid, int curRow, int curCol, int rows, int cols){

        vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i=0; i<4; i++){
            int newRow = curRow + moves[i][0];
            int newCol = curCol + moves[i][1];

            if(newRow < rows and newCol < cols and newRow >= 0 and newCol >= 0 and grid[newRow][newCol] == '1'){
                grid[newRow][newCol] = '2';
                dfs(grid, newRow, newCol, rows, cols);
            }
        }
    }
};