class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<pair<int, int>> st;
        int sz = nums.size();
        int leftBou = -1, rightBou = -1;
        
        //Traversal from left
        for(int i=0; i<sz; i++){
            if(st.empty()) st.push({nums[i], i});
            else{
                while(!st.empty() and st.top().first > nums[i]){
                    if(leftBou == -1) leftBou = st.top().second;
                    else leftBou = min(leftBou, st.top().second);
                    
                    st.pop();
                }
                st.push({nums[i], i});
            }
        }
        
        //Traversal from right
        for(int j=sz-1; j>=0; j--){
            if(st.empty()) st.push({nums[j], j});
            else{
                while(!st.empty() and st.top().first < nums[j]){
                    if(rightBou == -1) rightBou = st.top().second;
                    else rightBou = max(rightBou, st.top().second);
                    
                    st.pop();
                }
                st.push({nums[j], j});
            }
        }
        
        return rightBou - leftBou > 0 ?  rightBou - leftBou + 1 : 0;
    }
};