class MyStack {
public:
    //Using 2 Queues
    //pop and top in O(1) time
    //push in O(n) time
    
    queue<int> q_one;
    queue<int> q_two;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q_one.empty()){
            q_one.push(x);
            while(!q_two.empty()){
                q_one.push(q_two.front()); q_two.pop();
            }
        }
        else{
            q_two.push(x);
            while(!q_one.empty()){
                q_two.push(q_one.front()); q_one.pop();
            }
        }
        
    }
    
    int pop() {
        if(!q_two.empty()){
            int val = q_two.front(); q_two.pop();
            return val;
        }
        else{
            int val = q_one.front(); q_one.pop();
            return val;
        }

    }
    
    int top() {
        if(!q_two.empty()){
            return q_two.front();
        }
        else{
            return q_one.front(); 
        }
    }
    
    bool empty() {
        if(q_one.empty() and q_two.empty()) return true;
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