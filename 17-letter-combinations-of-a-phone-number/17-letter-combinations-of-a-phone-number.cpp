class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp; vector<string> resVec;
        
        char temp = 'a';
        for(int i='2'; i<='9'; i++){
            mp[i] += temp; temp++;
            mp[i] += temp; temp++;
            mp[i] += temp; temp++;
            
            if(i=='7' or i=='9') {
                mp[i] += temp; temp++;
            }
        }
        
//         for(auto &pr: mp){
//             cout<<pr.first<<" "<<pr.second<<endl;
//         }
        
        
        
        unordered_set<string> output;
        
        
        letComRec(digits, 0, mp, output, "");
        
        for(auto &val: output){
            resVec.push_back(val);
        }
        
        if(resVec.size() == 1 and resVec[0] == "") resVec.pop_back();
        return resVec;
    }
    
    void letComRec(string digits, int curPos, unordered_map<char, string> &mp, unordered_set<string> &output, string curStr){
        if(curPos == digits.size()){
            output.insert(curStr);
            return;
        }
        
        string curCombi = mp[digits[curPos]];
        for(auto &val: curCombi){
            string temp = curStr;
            curStr += val; 
            letComRec(digits, curPos+1, mp, output, curStr);
            curStr = temp;
        }
    }
};