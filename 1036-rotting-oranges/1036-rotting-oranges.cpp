class Solution {
public:
	int rows;
	int cols;
	vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

	int orangesRotting(vector<vector<int>> &grid){	
		rows = grid.size();
		cols = grid[0].size();
		queue<pair<int,int>> bfsQ;

		for(int row=0; row<rows; row++){
	for(int col=0; col<cols; col++){
	if(grid[row][col] == 2){
			bfsQ.push({row, col});
}
}
}

int ans = 0;
		
		
		
while(!bfsQ.empty()){
	int sz = bfsQ.size();

	while(sz--){
		int curRow = bfsQ.front().first;
            int curCol = bfsQ.front().second;
            bfsQ.pop();
            
            for(int i=0; i<4; i++){
        int newRow = curRow + dir[i][0];
            int newCol = curCol + dir[i][1];

            if(newRow >= 0 and newCol >=0 and newRow < rows and newCol < cols 
    and grid[newRow][newCol] == 1){
            
            grid[newRow][newCol] = 2;
            bfsQ.push({newRow, newCol });
    }
    }
		
}

ans++;
}

for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        if(grid[i][j] == 1) return -1;
    }
}
	
return ans == 0? 0:ans-1;
}

};
