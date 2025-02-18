class Solution {
public:
    int climbStairs(int n) {
        int prev = 2, prev2 = 1;
        if(n == 1 or n == 2) return n;
        int curVal = prev + prev2;

        for(int i=4; i<=n; i++){
            prev2 = prev;
            prev = curVal;
            curVal = prev + prev2;
        }

        return curVal;
    }

    
};