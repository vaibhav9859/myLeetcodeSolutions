class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<string> board(n, str);
        vector<vector<string>> allComb;
        solve(board, 0, n, allComb);
        return allComb;
    }

    void solve(vector<string> &board, int curCol, int &sz, vector<vector<string>> &allComb){
        if(curCol == sz){
            allComb.push_back(board);
            return;
        }

        for(int row = 0; row < sz; row++){
            if(isSafe(row, curCol, board, sz)){
                board[row][curCol] = 'Q';
                solve(board, curCol+1, sz, allComb);
                board[row][curCol] = '.';
            }
        }
    }

    bool isSafe(int curRow, int curCol, vector<string> &board, int &sz){
        int dupRow = curRow;
        int dupCol = curCol;
        // Check curRow
        // while(curCol < sz){
        //     if(board[curRow][curCol++] == 'Q') return false;
        // }

        curCol = dupCol;
        while(curCol >= 0){
            if(board[curRow][curCol--] == 'Q') return false;
        }

        // Check right diagonal
        // curCol = dupCol;
        // while(curRow <sz and curCol < sz){
        //     if(board[curRow++][curCol++] == 'Q') return false;
        // }

        curRow = dupRow;
        curCol = dupCol;
        while(curRow >= 0 and curCol >= 0){
            if(board[curRow--][curCol--] == 'Q') return false;
        }
        
        
        // check left diagonal
        // curRow = dupRow;
        // curCol = dupCol;
        // while(curRow >= 0 and curCol < sz){
        //     if(board[curRow--][curCol++] == 'Q') return false;
        // }

        curRow = dupRow;
        curCol = dupCol;
        while(curRow < sz and curCol >= 0){
            if(board[curRow++][curCol--] == 'Q') return false;
        }

        return true;
    }
};