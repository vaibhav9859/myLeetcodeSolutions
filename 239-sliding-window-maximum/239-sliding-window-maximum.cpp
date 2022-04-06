class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output; list<int> lst;
        int n = nums.size();

        
        for(int i=0; i<k; i++){
            // for(auto &a: lst) cout<<nums[a]<<" ";
            // cout<<endl;           
            if(lst.empty() or nums[lst.back()] >= nums[i]){
                lst.push_back(i);
            }
            else{
                while(!lst.empty() and nums[lst.back()] < nums[i]) lst.pop_back();
                lst.push_back(i);
            }
        }
        
        output.push_back(nums[lst.front()]);
        
        for(int i=k; i<n; i++){
            if(lst.front() == i-k) lst.pop_front();
            
            if(lst.empty() or nums[lst.back()] >= nums[i]){
                lst.push_back(i);
            }
            else{
                while(!lst.empty() and nums[lst.back()] < nums[i]) lst.pop_back();
                lst.push_back(i);
            }
            
            output.push_back(nums[lst.front()]);
        }
        
        return output;
    }
};