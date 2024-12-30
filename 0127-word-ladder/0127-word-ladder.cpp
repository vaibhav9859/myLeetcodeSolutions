class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust;

        // for(auto &val : wordList){
        //     ust.insert(val);
        // }

        // if(ust.find(endWord) == ust.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        ust.insert(beginWord);

        int dist = 1;

        while(!q.empty()){
            int sz = q.size();

            for(int i=0; i<sz; i++){
                string curWrd = q.front();
                q.pop();

                if(curWrd == endWord) return dist;

                // let's check if 2 words differ by one letter or not
                int wrdListSz = wordList.size();
                for(int wrdItr = 0; wrdItr < wrdListSz; wrdItr++){
                    string newWrd = wordList[wrdItr];
                    int count = 0;
                    if(ust.find(newWrd) != ust.end()) continue;
                    
                    // check if differ by 1 char or not
                    for(int i=0; i<curWrd.size() and i<newWrd.size(); i++){
                        if(curWrd[i] != newWrd[i]){
                            count++;
                            if(count > 1) break;
                        }
                    }

                    if(count == 1) {
                        q.push(newWrd);
                        ust.insert(newWrd);
                    }
                }
            }

            dist++;
        }

        return 0;

    }
};