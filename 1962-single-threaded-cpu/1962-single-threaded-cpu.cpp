class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> tasksSorted;
        int sz = tasks.size();

        for(int i=0; i<sz; i++){
            tasksSorted.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(tasksSorted.begin(), tasksSorted.end());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<int> order;
        long long curTime = 0;

        for(int i=0; i<sz; ){
            if(minHeap.empty() and curTime < tasksSorted[i][0]){
                curTime = tasksSorted[i][0];
            }

            while(i<sz and curTime >= tasksSorted[i][0]){
                minHeap.push({tasksSorted[i][1], tasksSorted[i][2]});
                i++;
            }

            if(!minHeap.empty()){
                order.push_back(minHeap.top()[1]);
                curTime += minHeap.top()[0];

                minHeap.pop();
            }            
        }

        while(!minHeap.empty()){
            order.push_back(minHeap.top()[1]);
            curTime += minHeap.top()[0];

            minHeap.pop();
        }

        return order;
    }
}; 