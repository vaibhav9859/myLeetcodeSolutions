// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int curCol = KnightPos[1]-1;
	    int curRow = KnightPos[0]-1;
	    int desCol = TargetPos[1]-1;
	    int desRow = TargetPos[0]-1;
	    
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    
	    int ans = minStepCount(curRow, curCol, desRow, desCol, N, N, vis);
	    
	    if(ans == -1) return -1;
	    
	    return ans;
	}
	
    int minStepCount(int curRow, int curCol, int desRow, int desCol, int rows, int cols, vector<vector<int>> &vis){

        int dir[][2] = {{-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-2, -1}, {-2, 1}}; 
        int distance = -1;
        int count = 0;
        queue<pair<int, int>> q;
        
        q.push({curRow, curCol});
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                int presentRow = q.front().first;
                int presentCol = q.front().second;
                q.pop();
                vis[presentRow][presentCol] = 1;
                
                if(presentRow == desRow and presentCol == desCol){
                    return distance = count;
                }
                
                for(int i=0; i<8; i++){
                    int newRow = presentRow + dir[i][0];
                    int newCol = presentCol + dir[i][1];
                    
                    if(newRow>=0 and newRow<rows and newCol>=0 and newCol<cols and !vis[newRow][newCol]){
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }                
            }

            
            count++;
        }
        
        return distance;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends