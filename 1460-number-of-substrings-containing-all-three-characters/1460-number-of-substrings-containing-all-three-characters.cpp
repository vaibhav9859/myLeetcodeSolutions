class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;

        for(char chr = 'a'; chr <= 'c'; chr++){
            mp[chr] = -1;
        }

        int idx = 0;
        int sz = s.size();
        int sum = 0;

        while(idx < sz){
            mp[s[idx]] = idx;

            int isValidSubStr = true;
            int minIdx = INT_MAX;
            for(char chr = 'a'; chr <= 'c'; chr++){
                if(mp[chr] == -1) isValidSubStr = false;
                minIdx = min(minIdx, mp[chr]);
            }

            if(isValidSubStr){
                sum += (1 + minIdx);
            }

            idx++;
        }
        
        return sum;
    }
}; 