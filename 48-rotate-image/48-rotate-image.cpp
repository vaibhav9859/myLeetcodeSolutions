class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size();
        
        reverse(matrix.begin(), matrix.end());
        
        for(int row=0; row<size; row++){
            for(int col=row+1; col<size; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        
    }
};