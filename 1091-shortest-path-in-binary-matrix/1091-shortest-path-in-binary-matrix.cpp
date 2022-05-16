class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int pathLength = 0;
        if(grid[0][0] or grid[rows-1][cols-1]){
            return -1;
        }
        else{
             q.push({0, 0});
            grid[0][0]  = -1;
            pathLength++;
            if(rows == 1 and cols == 1) return 1;
        } 
            
        while(!q.empty()){
            int sz = q.size();
            
            pathLength++;
            for(int i=0; i<sz; i++){
                
                int curRow = q.front().first;
                int curCol = q.front().second;
                q.pop();
                
                // cout<<curRow<<" "<<curCol<<endl;
                
                int temp[8][8] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1},
                                  {-1, -1}, {-1, 0}, {-1, 1}};
                
                for(int j=0; j<8; j++){
                    int newRow = curRow + temp[j][0];
                    int newCol = curCol + temp[j][1];
                    
                    if(newRow == rows-1 and newCol == cols-1){
                        return pathLength;
                    }
                    else if(newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols
                            or grid[newRow][newCol] == -1){
                        continue;
                    }
                    else if(grid[newRow][newCol] == 0){
                        grid[newRow][newCol] = -1;
                        q.push({newRow, newCol});
                    }
                }
                
            }
        }
        
        return -1;
    }
};