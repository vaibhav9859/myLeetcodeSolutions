class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mp;
        int sz = s.size();
        int tSz = t.size();
        for(auto &chr: t){
            mp[chr]++;
        }

        int count = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int sIdx = -1;

        while(right < sz){
            mp[s[right]]--;
            if(mp[s[right]] >= 0) count++;

            while(count >= tSz and left <= right){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    sIdx = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) count--;
                left++;
            }
            
            right++;
        }

        return sIdx != -1 ? s.substr(sIdx, minLen) : "";
    }
};