class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int prevBal = 0, curBal = 0;
        int sz = gas.size(); int start = 0;
        
        for(int i=0; i<sz; i++){
            
            curBal += gas[i] - cost[i];
            if(curBal < 0){
                prevBal += curBal; curBal = 0;
                start = i+1;
            }

        }
        
        if(start<sz and curBal + prevBal >= 0) return start;
        return -1;
    }
};