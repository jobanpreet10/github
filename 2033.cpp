class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> nums;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                nums.push_back(grid[i][j]);
            }
        }
        int result = 0;
        sort(begin(nums), end(nums));
        int l = nums.size();
        int target = nums[l/2];

        for(int num : nums){
            if(target%x != num%x){
                return -1;
            }
            
            result += abs(target-num)/x;
        }
        return result;
    }
};
