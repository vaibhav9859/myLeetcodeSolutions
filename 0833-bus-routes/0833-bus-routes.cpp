class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        
        // stop to route mapping .. route indices starting from 0
        unordered_map<int, vector<int>> stopToRoute;

        int numRoutes = routes.size();

        for(int i=0; i<numRoutes; i++){
            for(auto &curStp : routes[i]){
                stopToRoute[curStp].push_back(i);
            }
        }

        queue<int> qRouteIdx;
        unordered_set<int> visRouteIdx;
        for(auto &routeIdx : stopToRoute[source]){
            qRouteIdx.push(routeIdx);
            visRouteIdx.insert(routeIdx);
        }

        // qRouteIdx.push(stopToRoute[source][0]);
        // visRouteIdx.insert(stopToRoute[source][0]);

        int busReq = 1;

        while(!qRouteIdx.empty()){
            int qSz = qRouteIdx.size();
            while(qSz--){
                int curRouteIdx = qRouteIdx.front();
                qRouteIdx.pop();
                
                for(auto &stop : routes[curRouteIdx]) {
                    if(stop == target) return busReq;
                    else{
                        for(auto &routeIdx : stopToRoute[stop]){
                            if(visRouteIdx.find(routeIdx) == visRouteIdx.end()){
                                visRouteIdx.insert(routeIdx);
                                qRouteIdx.push(routeIdx);
                            }
                        }
                    }
                }
            }

            // Let's go to a new bus - new Route
            busReq++;
        }

        return -1;
    }
};