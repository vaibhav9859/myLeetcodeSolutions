class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allComb;
        vector<int> curComb;

        allCombi(candidates, target, curComb, 0, 0, allComb);
        return allComb;
    }

    void allCombi(vector<int> &arr, int &target, vector<int> &curComb, int curSum, int curIndex, vector<vector<int>> &allComb){
        if(curIndex >= arr.size() or curSum > target) return;
        if(curSum == target){
            allComb.push_back(curComb);
            return;
        }

        // consider cur value in comb and don't move forward
        curComb.push_back(arr[curIndex]);
        allCombi(arr, target, curComb, curSum+arr[curIndex], curIndex, allComb);
        
        // consider cur value in comb and move ahead
        // allCombi(arr, target, curComb, curSum+arr[curIndex], curIndex+1, allComb);


        curComb.pop_back();
        // don't consider the cur value and move ahead
        allCombi(arr, target, curComb, curSum, curIndex+1, allComb);

    }
};