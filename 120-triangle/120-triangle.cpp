class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int endRow = triangle.size()-1, endCol = triangle[endRow].size()-1;
        
        for(int curRow = endRow-1, curColSize = endCol-1; curRow >= 0; curRow--, curColSize--){
            for(int j=0; j<=curColSize; j++){
                triangle[curRow][j] = min(triangle[curRow][j]+triangle[curRow+1][j], triangle[curRow][j]+triangle[curRow+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};