class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gSz = g.size();
        int cSz = s.size();
        int count = 0;

        for(int gIdx = 0, cIdx = 0; gIdx < gSz and cIdx < cSz; ){
            if(g[gIdx] <= s[cIdx]){
                count++;
                gIdx++;
                cIdx++;
            }
            else {
                cIdx++;
            }
        }

        return count;
    }
};