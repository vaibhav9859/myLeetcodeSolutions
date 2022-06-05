class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        
        for(auto pr: dislikes){
            adj[pr[0]].push_back(pr[1]);
            adj[pr[1]].push_back(pr[0]);
        }
        
        vector<int> color(n+1, -1);
        
        for(int i=1; i<=n; i++){
            if(color[i] == -1 and  !biparPossible(adj, i, color)){
                return false;
            }
        }
       
        return true;
    }
    
    bool biparPossible(vector<int> adj[], int src, vector<int> &color){
        
        color[src] = 0;
        int col = 0;
        queue<int> q; 
        q.push(src);
        
        while(!q.empty()){
            
            int curNode = q.front();
            q.pop();
            col = color[curNode];
            
            for(auto &adjNode: adj[curNode]){
                if(color[adjNode] == -1){
                    color[adjNode] = 1 - col;
                    q.push(adjNode);
                }
                else if(color[adjNode] == col) return false;
            }
        }
        
        return true;
    }
};