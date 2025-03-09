class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> letterLocMap;
        unordered_set<string> alreadyTaken;

        for(int i=0; i<s.size(); i++){
            letterLocMap[s[i]].push_back(i);
        }
        int count = 0;

        for(int i=0; i<words.size(); i++){
            string curWord = words[i];
            if(alreadyTaken.find(curWord) != alreadyTaken.end()){
                count++;
                continue;
            }
            
            int prevLoc = -1;
            int j= 0;
            for(j=0; j<curWord.size(); ){
                if(letterLocMap.find(curWord[j]) == letterLocMap.end()) break;
                vector<int> curLetterLocs = letterLocMap[curWord[j]];
                
                int flag = 0;
                for(auto &loc: curLetterLocs){
                    if(prevLoc < loc){
                        prevLoc = loc;
                        j++;
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) break;
            }

            if(j == curWord.size()){
                count++;
                alreadyTaken.insert(curWord);
            }
        } 

        return count;
    }
};