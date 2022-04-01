class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        
        for(int start = 0, end = 0; end<s.size(); ){

            if(!m[s[end]]) {
                m[s[end]] = 1;  
                ans = max(ans, end-start+1); 
                end++;
            }
            else{
                m[s[start]] = 0;
                start++;
            } 
            
        }
        
        return ans;
    }
};