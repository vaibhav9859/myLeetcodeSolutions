class Solution {
public:
    static bool cmp(string a, string b){
        return (a+b) > (b+a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strs;

        for(int i=0; i<nums.size(); i++){
            strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(), strs.end(), cmp);

        string output;
        int allZeroes = 1;
        for(int i=0; i<strs.size(); i++){
            output += strs[i];

            if(strs[i] != "0") allZeroes = 0;
        }

        if(allZeroes) return "0";
        return output;
    }
};