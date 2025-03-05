class Solution{
public:
	int rows;
	int cols;
	vector<vector<int>> vis;
	vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
	
	int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2){
	rows = grid2.size();
	cols = grid2[0].size();
	vis.assign(rows, vector<int>(cols, 0));
	int count = 0;
	
	for(int row=0; row<rows; row++){
	for(int col=0; col<cols; col++){
		if(grid2[row][col] and !vis[row][col]){
			int isSubIsland = 1;
			vis[row][col] = 1;
			if(grid1[row][col] == 0) isSubIsland = 0;

			dfs(grid1, grid2, isSubIsland, row, col);
			
			if(isSubIsland) count++;
}
}
}

return count;
}
	
	void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int &isSubIsland, int row, int col){
		
		for(int i=0; i<4; i++){
	int newRow = row + dir[i][0];
int newCol = col + dir[i][1];

if(newRow >= 0 and newCol >= 0 and newRow < rows and newCol < cols and grid2[newRow][newCol] and !vis[newRow][newCol]){
	vis[newRow][newCol] = 1;
	if(!grid1[newRow][newCol]){
		isSubIsland = 0;
}

dfs(grid1, grid2, isSubIsland, newRow, newCol);

}
}

}
};
