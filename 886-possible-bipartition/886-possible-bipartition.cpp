class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1]; vector<int> colour(n+1, -1);
        
        for(int i=0; i<dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i=1; i<=n; i++){
            cout<<i<<"-->";
            for(auto a: adj[i]) cout<<a<<" ";
            cout<<endl;
        }
        
        for(int i=1; i<=n; i++){
            if(colour[i] == -1){
                if(bfs(adj, i, colour) == false) return false;
            }
        }

        
        return true;
    }
    
    bool bfs(vector<int> adj[], int startNode, vector<int> &colour){
        queue<int> q; q.push(startNode); colour[startNode] = 1; int assCol = 1;
        
        while(!q.empty()){
            int sz = q.size(); int curCol = 1 - assCol; assCol = curCol;
            for(int i=0; i<sz; i++){
                int cur = q.front(); q.pop(); 
                for(auto &node: adj[cur]){
                    if(colour[node] == -1){
                        colour[node] = curCol;
                        q.push(node);
                    }
                    else{
                        if(colour[node] != curCol) return false;
                    }
                }
            }
        }
        return true;
    }
};