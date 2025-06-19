class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(j < n){
            while(j<n && nums[j]-nums[i] <= k){
                j++;
            }
            i = j;
            cnt++;
        }
        return cnt;
    }
};
