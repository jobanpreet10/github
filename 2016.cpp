class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int min_val = nums[0];
        for(int i = 1; i < nums.size(); i++){
           if(nums[i] > min_val){
            diff = max(diff,nums[i]-min_val);
           }
           else{
            min_val = nums[i];
           }
        }
        return diff;
    }
};
