class Solution {
public:
    int maxLen = 1;
    int sIdx = 0;
    int sz;
    string longestPalindrome(string s) {
        sz = s.size();
        for(int i=0; i<sz; i++){
            help(s, i-1, i+1);
            help(s, i, i+1);
        }

        return s.substr(sIdx, maxLen);
    }

    void help(string s, int left, int right){
        while(left >= 0 and right < sz){
            if(s[left] == s[right]){
                if(maxLen < right-left+1){
                    maxLen = right-left+1;
                    sIdx = left;
                }
                else if(maxLen == right-left+1){
                    if(sIdx > left) sIdx = left;
                }
                left--;
                right++;
            }
            else break;
        }
    }
};