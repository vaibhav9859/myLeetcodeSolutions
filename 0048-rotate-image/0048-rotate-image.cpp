class Solution {
public:
void rotate(vector<vector<int>> &mat){
	
	int sz = mat.size();
	
	for(int i=0; i<sz; i++){
	reverse(mat[i].begin(), mat[i].end());
}

// swap element
int tempCol = sz-1;

for(int row=0; row<sz; row++){
    int itr = sz-1-row;
	for(int col=0; col<tempCol; col++){
	
	swap(mat[row][col], mat[row+itr][col+itr]);
    itr--;
}
tempCol--;

}
}

};