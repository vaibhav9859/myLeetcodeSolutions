class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int start = 0, end = height.size()-1; start < end; ){
            ans = max(ans, ((end - start) * min(height[start], height[end])) );
            
            if(height[start] < height[end]) start++;
            else if(height[start] > height[end]) end--;
            else {start++; end--;}
        }
        
        return ans;
    }
};