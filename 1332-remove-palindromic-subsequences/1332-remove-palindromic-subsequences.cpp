class Solution {
public:
    bool isPalin(string s){
        int sPtr = 0, ePtr = s.length()-1;
        
        while(sPtr <= ePtr){
            if(s[sPtr] == s[ePtr]){
                sPtr++; 
                ePtr--;
            }
            else return false;
        }
        
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        
        if(isPalin(s)) return 1;
        
        return 2;
    }
};