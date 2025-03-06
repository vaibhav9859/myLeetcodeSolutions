class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarCount = 0, tenDollarCount = 0, twentyDollarCount = 0;
        int sz = bills.size();

        for(int i=0; i<sz; i++){
            if(bills[i] == 5){
                fiveDollarCount++;
            }
            else if(bills[i] == 10){
                if(fiveDollarCount){
                    fiveDollarCount--;
                    tenDollarCount++;
                }
                else{
                    return false;
                }
            } 
            else {
                if(tenDollarCount and fiveDollarCount){
                    tenDollarCount--;
                    fiveDollarCount--;
                    twentyDollarCount++;
                }
                else if(fiveDollarCount >= 3){
                    fiveDollarCount -= 3;
                    twentyDollarCount++;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};