class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> m;
        
        for(auto str: strs){
            string temp = str;
            sort(str.begin(), str.end());
            m[str].push_back(temp);
        }
        
        for(auto pr: m){
            output.push_back(pr.second);
        }
        
        return output;
    }
};