class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // if stops are greater than k+1.. don't consider it
        // if I am at dest.. use it to update dist but don't put it inside the queue

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // create adjList
        vector<pair<int,int>> adjList[n];
        for(auto &flight: flights){
            int srcc = flight[0];
            int dest = flight[1];
            int cost = flight[2];

            adjList[srcc].push_back({dest, cost});
        }

        // {node, dist, stops}
        queue<vector<int>> q; 
        q.push({src,0,0});

        while(!q.empty()){
            // auto [curNode, curDist, curStops] = q.front();
            int curNode = q.front()[0];
            int curDist = q.front()[1];
            int curStops = q.front()[2];
            q.pop();

            if(curStops > k+1) continue;

            for(auto &adjNodePr: adjList[curNode]){
                auto [newNode, newDist] = adjNodePr;

                if(curStops == k and newNode != dst) continue;
                if(newNode == dst){
                    if(curDist + newDist < dist[dst]) dist[dst] = curDist + newDist;
                    continue;
                }

                if(curDist+newDist < dist[newNode]){
                    dist[newNode] = curDist+newDist;
                    q.push({newNode, curDist+newDist, curStops+1});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};