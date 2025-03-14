class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        mp['a'] = mp['b'] = mp['c'] = -1;

        int idx = 0;
        int sz = s.size();
        int sum = 0;

        while(idx < sz){
            mp[s[idx]] = idx;

            if(mp['a'] != -1 and mp['b'] != -1 and mp['c'] != -1){
                sum += 1 + min(mp['a'], min(mp['b'], mp['c']));
            }

            idx++;
        }
        
        return sum;
    }
}; 