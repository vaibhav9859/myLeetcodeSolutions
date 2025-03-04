class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int prov = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                prov++;
                bfs(isConnected, i, vis, n);
            }
        }

        return prov;
    }

    void bfs(vector<vector<int>>& isConn, int curNode, vector<int> &vis, int n){
        queue<int> q;
        q.push(curNode);
        vis[curNode] = 1;

        while(!q.empty()){
            int sz = q.size();
  
            // while(sz--){
                int curNode = q.front();
                q.pop();
                for(int i=0; i<n; i++){
                    if(isConn[curNode][i] == 1 and curNode != i and !vis[i]){
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            // }
            
        }

        return;
    }
};