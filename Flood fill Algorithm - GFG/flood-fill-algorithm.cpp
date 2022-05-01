// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int rows = image.size(), cols = image[0].size();
        
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        ffHelper(image, sr, sc, newColor, image[sr][sc], rows, cols, vis);
        
        return image;
    }
    
    
    void ffHelper(vector<vector<int>>& image, int sr, int sc, int newColour, int desColour, int rows, int cols, 
    vector<vector<int>> &vis){
        
        if(sr < 0 or sc < 0 or sr >= rows or sc >= cols or vis[sr][sc] or image[sr][sc] != desColour) return;
        
        vis[sr][sc] = 1;
        image[sr][sc] = newColour;
        
        ffHelper(image, sr, sc+1, newColour, desColour, rows, cols, vis);
        ffHelper(image, sr+1, sc, newColour, desColour, rows, cols, vis);
        ffHelper(image, sr, sc-1, newColour, desColour, rows, cols, vis);
        ffHelper(image, sr-1, sc, newColour, desColour, rows, cols, vis);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends