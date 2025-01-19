class Solution {
public:
    // 5 2 3 1
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int> &nums, int start, int end){ // 5 2 3 1 start=0, end=3
        if(start >= end) return;

        int mid = (start + (end-start)/2); // mid = 1
        mergeSort(nums, start, mid); // (nums, 0, 1)
        mergeSort(nums, mid+1, end); // (nums, 0, 1)

        merge(nums, start, mid, end);
    }

    void merge(vector<int> &nums, int start, int mid, int end){
        vector<int> temp;
        int itr1 = 0, itr2 = 0;

        for(itr1 = start, itr2 = mid+1; itr1 <= mid and itr2 <= end;){
            if(nums[itr1] <= nums[itr2]){
                temp.push_back(nums[itr1]);
                itr1++;
            } else{
                temp.push_back(nums[itr2]);
                itr2++;
            }
        }

        while(itr1 <= mid){
            temp.push_back(nums[itr1]);
            itr1++;
        }

        while(itr2 <= end){
            temp.push_back(nums[itr2]);
            itr2++;
        }

        for(int k=0, itr=start; itr<=end; itr++, k++){
            nums[itr] = temp[k];
        }
    }
};