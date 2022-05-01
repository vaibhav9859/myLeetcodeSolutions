class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size(), cols = image[0].size();
        
        queue<pair<int, int>> q; vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        q.push({sr, sc}); int desColor = image[sr][sc]; vis[sr][sc] = 1; 
                
        while(!q.empty()){

            // int sz = q.size();
            
            // for(int i=0; i<sz; i++){
                int curR = q.front().first, curC = q.front().second; q.pop();
                
                // cout<<curR<<" "<<curC<<endl;
                // if(vis[curR][curC]){
                //     continue;
                // }
                
                image[curR][curC] = newColor;
                
                int temp[4][4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
                
                for(int i=0; i<4; i++){
                    int newCurR = curR + temp[i][0];
                    int newCurC = curC + temp[i][1];
                    
                    if(newCurR>=0 and newCurR<rows and newCurC>=0 and newCurC<cols and image[newCurR][newCurC] == desColor 
                       and !vis[newCurR][newCurC]){
                        vis[newCurR][newCurC] = 1;
                        q.push({newCurR, newCurC});
                    }
                }
                
                
            // }
           
        }
        return image;
        
    }
    
    
    
};