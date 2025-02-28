class Solution {
public:
    bool isPalin(string &s, char curChar, int idx){
        if(idx-1 >= 0 and s[idx-1] == curChar) return true;
        if(idx-2 >= 0 and s[idx-2] == curChar) return true;
        return false;
    }

    void fixSuffix(string &s, int idx){
        for(int i=idx; i<s.size(); i++){
            for(char chr='a'; chr<='z'; chr++){
                if(isPalin(s, chr, i)) continue;
                s[i] = chr;
                break;
            }
        }
    }

    string smallestBeautifulString(string s, int k) {
        int sz = s.size();

        for(int end = sz-1; end>=0; end--){
            for(char curChar = s[end]+1; curChar < 'a'+k; curChar++){
                // char curChar = (char)('a' + i);
                // if(curChar <= s[end]) continue;

                if(!isPalin(s, curChar, end)){
                    s[end] = curChar;
                    fixSuffix(s, end+1);
                    return s;
                }
            }
        }

        return "";
    }
};