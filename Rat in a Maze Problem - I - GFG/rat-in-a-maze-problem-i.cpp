// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> output; 
        unordered_set<string> resultSet;
        
        pathMaker(m, n, 0, 0, "", resultSet);
        
        for(auto &strs: resultSet) output.push_back(strs);
        
        return output;
    }
    
    void pathMaker(vector<vector<int>> &m, int n, int curRow, int curCol, string curPath, unordered_set<string> &resultSet){
        if(m[curRow][curCol] != 1) return;
        if(curRow == n-1 and curCol == n-1){
            resultSet.insert(curPath);
        }
        
        m[curRow][curCol] = -1;
        
        int paths[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        string pathLetter = "RDLU";

        for(int i=0; i<4; i++){
            int newRow = curRow + paths[i][0];
            int newCol = curCol + paths[i][1];
            if(newRow >=0 and newRow < n and newCol >=0 and newCol < n){
                pathMaker(m, n, newRow, newCol, curPath + pathLetter[i], resultSet);
            }
        }
        
        m[curRow][curCol] = 1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends