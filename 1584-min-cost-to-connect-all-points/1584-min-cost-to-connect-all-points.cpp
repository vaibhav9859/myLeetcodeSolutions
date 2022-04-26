class Solution {
public:
    
    //For video explanation visit this link
    //https://www.youtube.com/watch?v=K7LqWeA9WSg
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        //Creating min heap of distance, startNode, endNode
        //priority queues in STL are always sorted in terms of first value when use pairs or pairs of pairs
        priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int>> > > min_heap;
        
        //Using set to know what all nodes I have already considered and taken in my path
        //I shouldn't take those nodes again
        unordered_set<int> uset; int totalPoints = points.size();
        
        //Initially the cost will be zero
        int ansCost = 0;
        
        //Now in the beginning I am putting 0th node, and the distance from itself will be zero
        //Below {0,{0,0}} is showing zero distance from node zero to node zero
        min_heap.push({0, {0, 0}});
        
        //Now I have to keep doing some tasks till all the nodes have been visited
        //I am making sure that by keeping the check on size of my set
        while(!min_heap.empty() and uset.size() != totalPoints){
            int curCost = min_heap.top().first; int curStart = min_heap.top().second.first, curEnd = min_heap.top().second.second;
            min_heap.pop();  
            
            //If my curNode is already present in the set I shouldn't consider that move to next minimum distance node
            if(uset.find(curEnd) != uset.end()) continue;
            
            //Adding the cost to curCost and inserting the node in set coz now this node has been considered in the path
            ansCost += curCost; uset.insert(curEnd);
            
            
            //Now calculating distance to all the points except the points which are already visited
            //After calculation putting them in heap
            for(int i=0; i<totalPoints; i++){
                if(uset.find(i) != uset.end()) continue;
                
                int curDist = dist(points[curEnd][0], points[curEnd][1], points[i][0], points[i][1]);
                min_heap.push({curDist, {curEnd, i}});
            }
            
        }
        return ansCost;
    }
    
    int dist(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
};