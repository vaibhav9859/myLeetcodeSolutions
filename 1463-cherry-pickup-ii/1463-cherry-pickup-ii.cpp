class Solution {
public:
    int arr[71][71][71];
    
    int cherryPickup(vector<vector<int>>& grid) {
        int totRows = grid.size();
        int totCols = grid[0].size();
        
        memset(arr, -1, sizeof(arr));
        
        return cherryCal(grid, totRows, totCols, 0, 0, totCols-1);
    }
    
    
    int cherryCal(vector<vector<int>>& grid, int totRows, int totCols, int curRow, int curCol1, int curCol2){

        if(curRow == totRows-1){
            if(curCol1 == curCol2){
                return grid[curRow][curCol1];
            }
            else{
                return grid[curRow][curCol1] + grid[curRow][curCol2];
            }
        }
        
        
        if(arr[curRow][curCol1][curCol2] != -1) return arr[curRow][curCol1][curCol2];
        
        int ans = 0;
        
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                
                if(curRow+1 < totRows and curCol1+i >=0 and curCol1+i < totCols and curCol2+j >=0 and curCol2+j < totCols) 
                    ans = max(ans, cherryCal(grid, totRows, totCols, curRow+1, curCol1+i, curCol2+j));
            }
        }
        
        
   
        if(curCol1 == curCol2){
            ans += grid[curRow][curCol1];
        }
        else{
            ans += grid[curRow][curCol1] + grid[curRow][curCol2];
        }
     

        return arr[curRow][curCol1][curCol2] = ans;
    }
};