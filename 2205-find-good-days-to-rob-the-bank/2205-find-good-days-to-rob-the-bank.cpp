class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int sz = security.size();

        // below vectors to track for how long array was increasing or decreasing
        vector<int> trackIncreasing(sz, 0);
        vector<int> trackDecreasing(sz, 0);

        vector<int> goodDaysIdx;

        // below we can write 2 different for loops as well
        for(int i=0; i<sz; i++){
            if(i==0){
                trackIncreasing[i] = 0;
                trackDecreasing[sz-i-1] = 0;
            }
            else {
                if(security[i] <= security[i-1]){
                    trackIncreasing[i] = trackIncreasing[i-1] + 1;
                }
                else {
                    trackIncreasing[i] = 0;
                }
                
                if(security[sz-i-1] <= security[sz-i]) {
                    trackDecreasing[sz-i-1] = trackDecreasing[sz-i] + 1;
                }
                else {
                    trackDecreasing[sz-i-1] = 0;
                }
            }
        }

        // using those arrays
        for(int i=0; i<sz; i++){
            if(trackIncreasing[i] >= time and trackDecreasing[i] >= time){
                goodDaysIdx.push_back(i);
            }
        }

        return goodDaysIdx;
    }
};