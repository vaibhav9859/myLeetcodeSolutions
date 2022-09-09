class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int totRows = board.size();
        int totCols = board[0].size();
        
        for(int i=0; i<totRows; i++){
            for(int j=0; j<totCols; j++){
                if(board[i][j] == word[0]){
                    board[i][j]  = '$';
                    if(search(board, word, 1, i, j, totRows, totCols)) return true;
                    board[i][j] = word[0]; 
                }
                
            }
        }
        
        return false;
        
    }
    
    bool search(vector<vector<char>>& board, string word, int idx, int curRow, int curCol, int &totRows, int &totCols){
        if(idx == word.size()) return true;
        
        
        int arr[4][4] = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
        
        for(int i=0; i<4; i++){
            int newRow = curRow + arr[i][0];
            int newCol = curCol + arr[i][1];
            
            if(newRow >=0 and newCol >=0 and newRow < totRows and newCol < totCols and board[newRow][newCol] != '$'){
                if(word[idx] == board[newRow][newCol]){
                    char temp = board[newRow][newCol];
                    board[newRow][newCol] = '$';
                    
                    if(search(board, word, idx+1, newRow, newCol, totRows, totCols)) return true;
                    
                    board[newRow][newCol] = temp;
                }
            }
        }
        
        return false;
    }
};