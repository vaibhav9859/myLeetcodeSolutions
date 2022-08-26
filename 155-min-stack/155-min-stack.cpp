// #include<bits/stdc++.h>

class MinStack {
public:
    vector<int> st;
    vector<int> minVal;
    
  
    
    MinStack() {
          // st.push(2);
        // st.pop();
        st.clear();
        minVal.clear();
    }
    
    void push(int val) {
        st.push_back(val);
        
        
        if(minVal.size()==0 or val < minVal[minVal.size()-1]) minVal.push_back(val);
        else minVal.push_back(minVal[minVal.size()-1]);
    }
    
    void pop() {
        if(!st.empty()){
             st.pop_back();
            minVal.pop_back();
        }
        
    }
    
    int top() {
        return st[st.size()-1];
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