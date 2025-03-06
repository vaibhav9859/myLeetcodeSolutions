class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // Create a new vector that includes each task's enqueue time, processing time, and original index.
        vector<vector<int>> sortedTasks;
        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        // Sort tasks by their enqueue time.
        sort(sortedTasks.begin(), sortedTasks.end());
        
        // Min-heap: each element is {processingTime, originalIndex}.
        // The heap will order by processing time (and by index if there's a tie).
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> taskHeap;
        
        vector<int> order;     // To store the final order of task execution.
        long long curTime = 0;       // Tracks the current time.
        int i = 0;             // Index for sortedTasks.
        
        // Process until we've added all tasks and the heap is empty.
        while (i < n || !taskHeap.empty()) {
            // If the heap is empty but the current time is less than the next task's enqueue time,
            // jump forward in time to when the next task becomes available.
            if (taskHeap.empty() && curTime < sortedTasks[i][0]) {
                curTime = sortedTasks[i][0];
            }
            
            // Add all tasks that are available by the current time.
            while (i < n && curTime >= sortedTasks[i][0]) {
                // Push the task with its processing time and original index.
                taskHeap.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }
            
            // Process the next task from the heap.
            if (!taskHeap.empty()) {
                auto task = taskHeap.top(); // task = {processingTime, originalIndex}
                taskHeap.pop();
                order.push_back(task[1]);
                curTime += task[0]; // Increase current time by the processing time of the task.
            }
        }
        
        return order;
    }
};
