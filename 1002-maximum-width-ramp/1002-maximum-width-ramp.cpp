class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int sz = nums.size();
        stack<int> st;

        for(int i=sz-1; i>=0; i--){
            if(st.empty() or nums[i] > nums[st.top()]){
                st.push(i);
            }
        }

        for(int i=0; i<sz; i++){
            while(!st.empty() and nums[i] <= nums[st.top()]){
                if(nums[i] == nums[st.top()] and i == st.top()){
                    st.pop();
                    break;
                }
                ans = max(ans, st.top()-i);
                st.pop();
            }
        }

        return ans;
    }
};