class Solution {
public:
     int rows, cols;
    vector<vector<int>> dir = {{0,1}, {1,0}, {0, -1}, {-1,0}};
    
    int orangesRotting(vector<vector<int>> &grid){
        rows = grid.size();  // 3
        cols = grid[0].size(); // 3
        
        queue<pair<int,int>> bfsQ;
        
        
        // Here I am putting loc of rotten oranges
        for(int row= 0; row<rows; row++){
            for(int col = 0; col<cols; col++){
                
                if(grid[row][col] == 2){
                    bfsQ.push({row, col}); // (0, 0)
                }
            }
        }
        
        int min = 0;
        
        // going through the bfs std::queue;
        while(!bfsQ.empty()){
            int sz = bfsQ.size();
            
            while(sz--){
                int curRow = bfsQ.front().first;
                int curCol = bfsQ.front().second;
                
                // (0,1), (1,0)
                bfsQ.pop();
                
                // going through all 4 directions
                for(int i=0; i<4; i++){
                    int newRow = curRow + dir[i][0];
                    int newCol = curCol + dir[i][1];
                    
                    if(newRow >=0 and newCol >=0 and newRow <rows and newCol <cols 
                    and grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        
                        bfsQ.push({newRow, newCol});
                    }
                }
            }
            
            if(!bfsQ.empty()) min++;
        }
        
        
        // if any loc has fresh orange return -1
        for(int row= 0; row<rows; row++){
            for(int col = 0; col<cols; col++){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }
        
        return min;
        
    }

};