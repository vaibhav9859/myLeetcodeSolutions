class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() or (num <= maxHeap.top()) or minHeap.empty()){
            maxHeap.push(num);
        } else if (num <= minHeap.top()) {
            maxHeap.push(num);
        } else if(num > minHeap.top()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(num);
        }

        if(maxHeap.size() - minHeap.size() >= 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() != maxHeap.size()){
            return maxHeap.top();
        } 

        return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */