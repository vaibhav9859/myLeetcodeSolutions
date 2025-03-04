class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numCities = isConnected.size();
        vector<int> vis(numCities+1, 0);
        int prov = 0;
        for(int i=0; i<numCities; i++){
            if(vis[i] == 0){
                vis[i] = 1;
                prov++;
                dfs(isConnected, i, numCities, vis);
            }
        }

        return prov;
    }

    void dfs(vector<vector<int>>& isConn, int src, int numCities, vector<int> &vis){

        for(int i=0; i<numCities; i++){
            if(isConn[src][i] == 1 and src != i and vis[i] != 1){
                vis[i] = 1;
                dfs(isConn, i, numCities, vis);
            }
        }
    }
};