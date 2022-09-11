class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int totRows = grid.size();
        int totCols = grid[0].size();
        
        int time = 0;
        
        for(int i=0; i<totRows; i++){
            for(int j=0; j<totCols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        
        int arr[4][4] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int curRow = q.front().first;
                int curCol = q.front().second;
                q.pop();
                
                
                for(int i=0; i<4; i++){
                    int newRow = curRow + arr[i][0];
                    int newCol = curCol + arr[i][1];
                    
                    if(newRow >= 0 and newCol >= 0 and newRow < totRows and newCol < totCols and grid[newRow][newCol]==1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        
        for(int i=0; i<totRows; i++){
            for(int j=0; j<totCols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return time;
    }
};