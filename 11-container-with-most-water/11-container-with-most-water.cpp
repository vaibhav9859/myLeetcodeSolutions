class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int start = 0, end = height.size()-1; start < end; ){
            int wtr_bw_end_start = (end - start) * min(height[start], height[end]); 
            
            ans = max(ans, wtr_bw_end_start);
            
            if(height[start] < height[end]) start++;
            else if(height[start] > height[end]) end--;
            else {start++; end--;}
        }
        
        return ans;
    }
};