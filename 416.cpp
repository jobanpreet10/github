class Solution {
public:
    vector<vector<bool>>dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;

        if( sum % 2 != 0) return false;
        dp.assign(n+1,vector<bool>(sum/2 + 1,false));
        for(int i =0; i <= n; i++){
            dp[i][0] = true; 
        }

        for(int i = 1; i <= n; i++){
            for(int k =1; k <= sum/2; k++){
                bool not_take = dp[i-1][k];
                bool take = false;
                if(k >= nums[i-1]) take = dp[i-1][k-nums[i-1]];
                dp[i][k] = take || not_take;
            }
        }
        return dp[n][sum/2];

    }
};
