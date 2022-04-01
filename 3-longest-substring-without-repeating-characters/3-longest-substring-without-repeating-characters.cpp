class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        
        for(int fi = 0, si = 0; si<s.size(); ){
            if(!m[s[si]]) {m[s[si]] = 1;  ans = max(ans, si-fi+1); si++;}
            else{
                m[s[fi]] = 0;
                fi++;
            }
            
            
        }
        
        return ans;
    }
};