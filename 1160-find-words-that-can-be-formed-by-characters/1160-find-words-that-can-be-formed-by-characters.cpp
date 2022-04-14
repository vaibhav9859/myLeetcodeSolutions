class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> orgMap;
        unordered_map<char, int> curMap;
        
        int ans = 0;
        
        for(auto &chr: chars){
            orgMap[chr]++; curMap[chr]++;
        }
        
        for(auto &curStr: words){
            curMap = orgMap; int flag = 0;
            for(auto &chr: curStr){
                if(!curMap[chr]) {flag = 1; break;}
                curMap[chr]--;
            }
            
            if(flag) continue;
            
            ans += curStr.size();
        }      
        
        return ans;
        
    }
};