class Solution {
public:
    bool isPalin(string &s, char curChar, int idx){
        if(idx-1 >= 0 and s[idx-1] == curChar) return true;
        // if(idx+1 < s.size() and s[idx+1] == curChar) return true;
        // if(idx-1 >= 0 and idx+1 < s.size() and s[idx-1] == s[idx+1]) return true;
        if(idx-2 >= 0 and s[idx-2] == curChar) return true;
        return false;
    }

    void fixSuffix(string &s, int idx){
        for(int i=idx; i<s.size(); i++){
            for(char chr='a'; chr<='z'; chr++){
                // cout<<"idx: "<<i<<" curChar "<< chr <<" "<<s<<endl; 
                if((i-1 >= 0 and chr == s[i-1]) or (i-2 >= 0 and s[i-2] == chr)) continue;
                
                // cout<<"idx2: "<<i<<" curChar "<< chr<<" "<<s <<endl; 
                
                s[i] = chr;
                break;
                
            }
        }
    }

    string smallestBeautifulString(string s, int k) {
        int sz = s.size();

        for(int end = sz-1; end>=0; end--){
            for(int i=0; i<k; i++){
                char curChar = (char)('a' + i);
                if(curChar <= s[end]) continue;

                // cout<<curChar <<" " <<s[end]<<" "<<end<<endl;
                if(!isPalin(s, curChar, end)){
                    // cout<<"str1 "<<s<<endl;
                    s[end] = curChar;
                    // cout<<"str2 "<<s<<endl;
                    fixSuffix(s, end+1);
                    return s;
                }
            }
        }

        return "";
    }
};