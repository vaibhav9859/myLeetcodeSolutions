class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIdxMap;
        int sz = s.size();
        int globalLen = 0;
        int localLen = 0;
        int lPointer = 0, rPointer = 0;

        while(rPointer < sz){
            int curChar = s[rPointer];

            if(charIdxMap.find(curChar) == charIdxMap.end()){
                charIdxMap[curChar] = rPointer;
            }
            else {
                int prevIdx = charIdxMap[curChar];

                if(prevIdx >= lPointer){
                    lPointer = prevIdx+1;
                }

                charIdxMap[curChar] = rPointer;
            }
            
            localLen = (rPointer-lPointer+1);
            globalLen = max(globalLen, localLen);
            rPointer++;
        }

        return globalLen;
    }
};