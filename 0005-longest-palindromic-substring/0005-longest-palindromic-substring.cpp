class Solution {
public:
    int maxLen = 1;
    int sIdx = 0;
    int sz;
    string longestPalindrome(string s) {
        sz = s.size();
        for(int i=0; i<sz; i++){
            oddLen(s, i);
            evenLen(s, i);
        }

        return s.substr(sIdx, maxLen);
    }

    void oddLen(string s, int idx){
        int left = idx-1;
        int right = idx+1;

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

    void evenLen(string s, int idx){
        int left = idx;
        int right = idx+1;
        while(left >=0 and right < sz){
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