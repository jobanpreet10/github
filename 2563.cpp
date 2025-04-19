class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
         long long pairCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            // Use binary search to find the bounds for pairs that add up within [lower, upper]
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] < lower) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            int leftBound = l;

            l = i + 1;
            r = nums.size() - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] > upper) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            int rightBound = r;

            if (rightBound >= leftBound) {
                pairCount += (rightBound - leftBound + 1);
            }
        }
        return pairCount;
    }
};
