// #include<bits/stdc++.h>

class MinStack {
public:
    stack<int> st;
    vector<int> minVal;
    
  
    
    MinStack() {
    
    }
    
    void push(int val) {
        st.push(val);
        
        if(minVal.size() == 0 or val < minVal[minVal.size()-1]) minVal.push_back(val);
        else minVal.push_back(minVal[minVal.size()-1]);
    }
    
    void pop() {
        if(!st.empty()){
             st.pop();
            minVal.pop_back();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal[minVal.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */