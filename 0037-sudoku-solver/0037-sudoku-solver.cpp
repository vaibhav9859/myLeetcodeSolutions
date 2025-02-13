class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int sz = 9;
        solve(board, sz);
    }

    bool solve(vector<vector<char>>& board, int &sz){
        int anyEmptyPlace = 0;

        for(int row=0; row < sz; row++){
            for(int col = 0; col < sz; col++){
                if(board[row][col] == '.'){
                    anyEmptyPlace = 1;
                    for(char val = '1'; val <= '9'; val++){
                        if(isValidPlace(board, row, col, val)){
                            board[row][col] = val;
                            if(solve(board, sz)) return true;
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        if(!anyEmptyPlace) return true;
        return false;
    }

    bool isValidPlace(vector<vector<char>>& board, int row, int col, int val){
        // check curRow
        for(int itrcol=0; itrcol < 9; itrcol++){
            if(board[row][itrcol] == val) return false;
        }

        // check curCol
        for(int itrRow=0; itrRow < 9; itrRow++){
            if(board[itrRow][col] == val) return false;
        }

        // check curMatrix
        int startRow =3 * (row/3), startCol = 3 * (col/3);

        for(int row = startRow; row < startRow + 3; row++){
            for(int col = startCol; col < startCol + 3; col++){
                if(board[row][col] == val) return false;
            }
        }

        return true;
    }
};