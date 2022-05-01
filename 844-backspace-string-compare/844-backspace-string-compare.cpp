class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp_one, temp_two;
        
        temp_one = helper(s); temp_two = helper(t);
        return temp_one==temp_two;
    }
    
    string helper(string s){
        string temp;
        
        for(auto &chr: s){
            if(chr == '#'){
                if(temp.empty()) continue;
                else{
                    temp.pop_back();
                }
            }
            else temp += chr;
        }
        
        return temp;
    }
};