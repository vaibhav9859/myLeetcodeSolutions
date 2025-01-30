class Solution {
public:
    void fillForwSlash(vector<vector<int>> &exGrid, int row, int col){
        exGrid[row][col+2] = 1;
        exGrid[row+1][col+1] = 1;
        exGrid[row+2][col] = 1;
    }

    void fillBackSlash(vector<vector<int>> &exGrid, int row, int col){
        exGrid[row][col] = 1;
        exGrid[row+1][col+1] = 1;
        exGrid[row+2][col+2] = 1;
    }

    int countRegions(vector<vector<int>> &exGrid){
        int sz = exGrid.size();
        int regionCount = 0;
        for(int row = 0; row < sz; row++){
            for(int col = 0; col < sz; col++){
                if(exGrid[row][col] == 0){
                    regionCount++;
                    bfs(exGrid, row, col);
                }
            }
        }

        return regionCount;
    }

    void bfs(vector<vector<int>> &exGrid, int row, int col){
        int sz = exGrid.size();
        vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        queue<pair<int, int>> q;
        q.push({row, col});
        exGrid[row][col] = 1;

        while(!q.empty()){
            pair<int, int> curLoc = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = curLoc.first + dir[i][0];
                int newCol = curLoc.second + dir[i][1];

                if(newRow >= 0 and newRow < sz and newCol >= 0 and newCol < sz and exGrid[newRow][newCol] == 0){
                    exGrid[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int sz = grid.size();
        vector<vector<int>> exGrid(3*sz, vector<int>(3*sz, 0));

        for(int row=0; row<sz; row++){
            for(int col=0; col<sz; col++){
                if(grid[row][col] == '/'){
                    fillForwSlash(exGrid, 3*row, 3*col);
                } 
                else if(grid[row][col] == '\\') {
                    fillBackSlash(exGrid, 3*row, 3*col);
                }
            }
        }

        return countRegions(exGrid);
    }
};