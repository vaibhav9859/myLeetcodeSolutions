class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> un_set;
        int sz = s.size();
        
        int lngLen = 0;
        
        for(int i=0, j=0; j<sz;){
            if(un_set.find(s[j]) == un_set.end()){
                un_set.insert(s[j]);
                lngLen = max(lngLen, (int)un_set.size());
                j++;
            }
            else{
                un_set.erase(s[i]); i++;
            }
        }
        
        return lngLen;
    }
};