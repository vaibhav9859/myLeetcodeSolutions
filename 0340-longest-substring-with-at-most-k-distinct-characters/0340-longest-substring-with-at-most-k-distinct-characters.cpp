class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int, int> mp;
        int sz = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < sz){
            mp[s[r]]++;

            if(mp.size() <= k){
                maxLen = max(maxLen, r-l+1);
            }
            else {
                mp[s[l]]--;

                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }

                l++;
            }

            r++;
        }

        return maxLen;
    }
};