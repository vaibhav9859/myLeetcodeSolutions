class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<string> board(n, str);
        vector<vector<string>> allComb;

        vector<int> checkRow(n, 0);
        vector<int> checkLowDiag(2*n, 0);
        vector<int> checkUpDiag(2*n, 0);

        solve(board, 0, n, allComb, checkRow, checkLowDiag, checkUpDiag);
        return allComb;
    }

    void solve(vector<string> &board, int curCol, int &sz, vector<vector<string>> &allComb, vector<int> &checkRow, vector<int> &checkLowDiag, vector<int> &checkUpDiag){
        if(curCol == sz){
            allComb.push_back(board);
            return;
        }

        for(int row = 0; row < sz; row++){
            if(isSafe(row, curCol, board, sz, checkRow, checkLowDiag, checkUpDiag)){
                board[row][curCol] = 'Q';
                checkRow[row] = 1;
                checkLowDiag[row + curCol] = 1;
                checkUpDiag[(sz-1)+(curCol-row)] = 1;
                solve(board, curCol+1, sz, allComb, checkRow, checkLowDiag, checkUpDiag);
                checkRow[row] = 0;
                checkLowDiag[row + curCol] = 0;
                checkUpDiag[(sz-1)+(curCol-row)] = 0;
                board[row][curCol] = '.';
            }
        }
    }

    bool isSafe(int curRow, int curCol, vector<string> &board, int &sz,vector<int> &checkRow, vector<int> &checkLowDiag, vector<int> &checkUpDiag){
        if(checkRow[curRow] or checkLowDiag[curRow + curCol] or checkUpDiag[(sz-1)+(curCol - curRow)]) return false;
        return true;
    }
};