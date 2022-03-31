class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int prevBal = 0, curBal = 0;
        int sz = gas.size(); int start = 0;
        int ans = 0;
        
        for(int i=0; i<sz; i++){
            
            int diff = gas[i] - cost[i];
            if(diff >= 0){
                curBal += diff;
            }
            else if(diff + curBal >= 0){
                curBal  = diff + curBal;
            }
            else{
                start = i+1;
                prevBal += diff + curBal; curBal = 0;
            }
        }
        
        if(start<sz and curBal + prevBal >= 0) return start;
        return -1;
    }
};