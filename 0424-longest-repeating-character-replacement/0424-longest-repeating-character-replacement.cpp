class Solution {
public:
    int characterReplacement(string s, int k) {
        // 0123456
        // AABABBA
        int maxLen = 0; 
        int sz = s.size(); // 7

        int left = 0, right = 0;

        // char: freq
        unordered_map<char, int> mp;
        /*
        A -> 1
        B -> 2
        */

        while(right < sz){
            char chr = s[right]; // AABAB
            mp[chr]++;

            int maxFreq = 0;
            for(auto &mpPr: mp){
                maxFreq = max(maxFreq, mpPr.second); // 3
            }

            // check for valid substring
            int curLen = right-left+1; // 5
            if(curLen - maxFreq <= k){
                maxLen = max(maxLen, curLen); // 4
            }
            else {
                mp[s[left]]--;
                left++; //1
            }

            right++; // 5
        }

        return maxLen;
    }
};