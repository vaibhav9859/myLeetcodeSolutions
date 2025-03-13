class Solution {
public:
    int kmp(string txt, string patt){
        int sz = patt.size();
        // create lps array
        vector<int> lps(sz, 0);
        int len = 0, itr = 1;

        while(itr < sz){
            if(patt[itr] == patt[len]){
                len++;
                lps[itr] = len;
                itr++;
            }
            else {
                if(len == 0){
                    lps[itr] = 0;
                    itr++;
                }
                else {
                    len = lps[len-1];
                }
            }
        }

        // let's match

        int patItr = 0, txtItr=0;
        while(txtItr < txt.size()){
            if(txt[txtItr] == patt[patItr]){
                txtItr++;
                patItr++;

                if(patItr == sz){
                    // I got the pattern inside text
                    return 1;
                }
            }
            else{
                if(patItr == 0){
                    txtItr++;
                }
                else {
                    patItr = lps[patItr-1];
                }
            }
        }

        return 0;
    }

    int repeatedStringMatch(string a, string b) {
        string src = a;
        int count = 1;

        while(src.size() < b.size()){
            src += a;
            count++;
        }

        if(src == b) return count;

        if(kmp(src, b)){
            return count;
        }

        if(kmp(src + a, b)) return count+1;

        return -1;
    }
};