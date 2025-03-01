class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        int len = 0;
        int sz = nums.size();
        stack<int> st;

        for(int i=sz-1; i>=0; i--){
            // if new value is lesser than the current top.. put that in stack
            if(st.empty() or nums[i] < nums[st.top()]){
                st.push(i);
            } 
        }

        for(int i=0; i<sz; i++){
            // while top of stack value is lesser than current i value keep popping
            while(!st.empty() and nums[i] > nums[st.top()]){
                len = max(len, st.top()-i+1);
                st.pop();
            }
        }

        return len;
    }
};