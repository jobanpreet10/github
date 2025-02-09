class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        for(int i = 0; i< nums.size(); i++){
            nums[i] = nums[i] - i;
        }
        unordered_map<int,int>mp;
        for(int j = 0; j < nums.size(); j++){
           int diff = nums[j];
           int goodPair = mp[diff];
           int totalPair = j;
           int badPairs = totalPair - goodPair;
           result += badPairs;
           mp[diff]++;
        }
        return result;
    }
};
