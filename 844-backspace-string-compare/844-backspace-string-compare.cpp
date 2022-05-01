class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sCount = 0, tCount = 0;
        
        for(int i=s.size()-1, j = t.size()-1; i>=0 or j>=0; i--, j--){
            
            while(i>=0 and (sCount > 0 or s[i] == '#')){
                
                if(s[i] == '#') sCount++;
                else sCount--;
                
                i--;
            }
            
            while(j>=0 and (tCount > 0 or t[j] == '#')){
                if(t[j] == '#') tCount++;
                else tCount--;
                
                j--;
            }
            
            if(i<0 and j<0) return true;
            if(i<0 or j<0) return false;
            
            if(s[i] != t[j]) return false;

        }
        
        return true;
    }
};