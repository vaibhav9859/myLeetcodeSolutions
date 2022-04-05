class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(); int plen = p.size();
        vector<int> output;
        
        map<char, int> pMap; map<char, int> sMap;
        
        for(int i=0; i<plen; i++){
            pMap[p[i]]++; sMap[s[i]]++;
        }
        
        for(int start = 0, end = plen-1; end < slen; ){
            // cout<<start<<" "<<end<<endl;
            
            if(pMap == sMap) output.push_back(start);
            
            sMap[s[start]]--; if(sMap[s[start]] == 0) sMap.erase(s[start]); 
            start++; 
            
            end++; 
            
            if(end < slen) sMap[s[end]]++;
        }
        
        return output;
    }
};