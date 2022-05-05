class MyStack {
public:
    // Using 2 Queues
    // O(n) time for popping or top of element
    // O(1) time for pushing
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()) q1.push(x);
        else if(!q2.empty()) q2.push(x);
        else q1.push(x);
    }
    
    int pop() {
        int ans;
        if(!q1.empty()){
            while(q1.size() != 1){
                int val = q1.front(); q1.pop();
                q2.push(val);
            }
            
            ans = q1.front();
            
            // q2.push(ans);
            q1.pop();
            return ans;
        }
        else if(!q2.empty()){
            while(q2.size() != 1){
                int val = q2.front(); q2.pop();
                q1.push(val);
            }
            
            ans = q2.front();
            q2.pop();
            // q1.push(ans);
            
            return ans;
        }   
        
        return ans;
    }
    
    int top() {
        int ans;
        if(!q1.empty()){
            while(q1.size() != 1){
                int val = q1.front(); q1.pop();
                q2.push(val);
            }
            
            ans = q1.front(); q1.pop();
            
            q2.push(ans);
            
            return ans;
        }
        else if(!q2.empty()){
            while(q2.size() != 1){
                int val = q2.front(); q2.pop();
                q1.push(val);
            }
            
            ans = q2.front(); q2.pop();
            q1.push(ans);
            
            return ans;
        }
        return ans;
    }
    
    bool empty() {
        if(q1.empty() and q2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */