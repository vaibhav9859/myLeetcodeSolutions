class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> or_map;
        if(words.size() == 1) return true;
        
        int i=0;
        for(auto chr: order){
            or_map[chr] = i;
            i++;
        }
        
        for(int i=1; i<words.size(); i++){
            string prevString = words[i-1];
            string curString = words[i];
            
            for(int pos = 0; pos<prevString.size() and pos<curString.size(); pos++){
                if(or_map[prevString[pos]] != or_map[curString[pos]]){
                    if(or_map[prevString[pos]] > or_map[curString[pos]]) return false;
                    else break;
                }
                
                if(pos+1 < prevString.size() and pos+1 >= curString.size()){
                    return false;   
                }

            }
            
            
            
        }
        
        return true;
    }
};