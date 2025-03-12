class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int maxSum = 0;
        int sz = cardPoints.size();
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
        }

        maxSum = max(sum, maxSum);

        for(int r=k-1, l=sz-1; l>=sz-k and r>=0; ){
            sum -= cardPoints[r];
            r--;
            sum+= cardPoints[l];
            l--;
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};