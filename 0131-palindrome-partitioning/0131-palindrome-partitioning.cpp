class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curPart;
        vector<vector<string>> allPart;
        allPartitions(s, 0, curPart, allPart);
        return allPart;
    }

    void allPartitions(string &s, int curIdx, vector<string> curPart, vector<vector<string>> &allPart){
        if(curIdx == s.size()){
            allPart.push_back(curPart);
            return;
        }

        for(int i=curIdx; i < s.size(); i++){
            if(isPalindrome(s, curIdx, i)){
                curPart.push_back(s.substr(curIdx, i-curIdx+1));
                allPartitions(s, i+1, curPart, allPart);
                curPart.pop_back();
            }
        }
    }

    bool isPalindrome(string str, int start, int end){
        while(start <= end){
            if(str[start++] != str[end--]) return false;
        }

        return true;
    }
};