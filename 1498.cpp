class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        vector<int>power(n);
        power[0] = 1; 
        for(int i = 1; i < n; i++){
            power[i] = power[i-1]*2 % MOD;
        }

        int l = 0, r = n-1;
        int result = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                int diff = r - l;
                result = (result + power[diff]) % MOD;
                l++;
            }
            else{
                r--;
            }
        }
        return result;
        
    }
};
