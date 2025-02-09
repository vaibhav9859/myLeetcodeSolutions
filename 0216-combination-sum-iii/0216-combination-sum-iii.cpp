class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allComb;
        vector<int> curComb;
        combFind(k, n, allComb, curComb, 1);

        return allComb;
    }

    void combFind(int k, int sum, vector<vector<int>> &allComb, vector<int> &curComb, int idx){
        if(sum == 0 and k == 0){
            allComb.push_back(curComb);
            return;
        }

        if(idx > 9 or sum < 0 or k < 0) return;
        
        curComb.push_back(idx);
        combFind(k-1, sum-idx, allComb, curComb, idx+1);
        curComb.pop_back();

        combFind(k, sum, allComb, curComb, idx+1);
    }
};