class Solution {
public:
    int MOD = 1000000000 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;

        // create my graph
        vector<pair<int,int>> graph[n];
        
        for(auto &road: roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        // dist, node
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minHeap;
        minHeap.push({0, 0});

        while(!minHeap.empty()){
            int curNode = minHeap.top()[1];
            long long curDist = minHeap.top()[0];
            minHeap.pop();

            for(auto &adjNodePr: graph[curNode]){
                int adjNode = adjNodePr.first;
                long long edgeWt = adjNodePr.second;

                long long newDist = edgeWt + curDist;
                if(newDist < dist[adjNode]){
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[curNode];
                    minHeap.push({newDist, adjNode});
                }
                else if(newDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] % MOD) +  (ways[curNode] % MOD);
                }
            }
        }

        return ways[n-1] % MOD;
    }
};