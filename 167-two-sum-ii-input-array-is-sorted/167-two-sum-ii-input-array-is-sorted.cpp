class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        vector<int> output;
        
        while(start<end){
            int curSum = numbers[start]+numbers[end];
            if(curSum == target){
                output.push_back(start+1);
                output.push_back(end+1);
                return output;
            }
            else if(curSum < target) start++;
            else end--;
        }
        
        return output;
    }
};