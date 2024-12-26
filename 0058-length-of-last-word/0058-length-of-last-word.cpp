class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size();
        int ans = 0;
        int charFound = 0;
        for(int i=sz-1; i>=0 ; i--){
            if(charFound == 0 and s[i] == ' '){
                continue;
            }

            charFound = 1;

            if(s[i] != ' '){
                ans++;
            } else return ans;
        }

        return ans;
    }
};