// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size(), cols = image[0].size();
        
        queue<pair<int, int>> q; vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        q.push({sr, sc}); int desColor = image[sr][sc]; 
                
        while(!q.empty()){

            int sz = q.size();
            
            for(int i=0; i<sz; i++){
                int curR = q.front().first, curC = q.front().second; q.pop();
                
                // cout<<curR<<" "<<curC<<endl;
                if(vis[curR][curC]){
                    continue;
                }
                vis[curR][curC] = 1; 
                image[curR][curC] = newColor;
                
                int temp[4][4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
                
                for(int i=0; i<4; i++){
                    int newCurR = curR + temp[i][0];
                    int newCurC = curC + temp[i][1];
                    
                    if(newCurR>=0 and newCurR<rows and newCurC>=0 and newCurC<cols and image[newCurR][newCurC] == desColor 
                       and !vis[newCurR][newCurC]){
                        q.push({newCurR, newCurC});
                    }
                }
                
                
            }
           
        }
        return image;
        
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