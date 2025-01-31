class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allComb;
        vector<int> curComb;
        sort(candidates.begin(), candidates.end());
        findAllComb(candidates, target, 0, curComb, 0, allComb);

        return allComb;
    }

    void findAllComb(vector<int>& cand, int &target, int curSum, vector<int> &curComb, int curIdx, vector<vector<int>> &allComb){
        if(curSum == target){
            allComb.push_back(curComb);
            return;
        }

        if(curIdx == cand.size() or curSum > target){
            return;
        }

        curComb.push_back(cand[curIdx]);
        findAllComb(cand, target, curSum+cand[curIdx], curComb, curIdx+1, allComb);
        curComb.pop_back();

        // Skip duplicates
        while (curIdx + 1 < cand.size() && cand[curIdx] == cand[curIdx + 1]) {
            curIdx++;
        }

        findAllComb(cand, target, curSum, curComb, curIdx+1, allComb);
    }
};