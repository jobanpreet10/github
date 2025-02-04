class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int inc = nums[0];
        for(int i =1 ; i< nums.size(); i++){
            if(nums[i -1] < nums[i]){
                inc += nums[i];
            }else{ 
                inc = nums[i];
            }
            cout << sum;
            sum = max(sum ,inc );

        }
        return sum;
    }
};
