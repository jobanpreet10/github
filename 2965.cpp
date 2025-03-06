class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size();
       unordered_map<int,int >mp;
       int actualSum = 0, duplicate = -1;

        // Calculate the sum and track occurrences
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                actualSum += num;
                mp[num]++;
                if (mp[num] == 2) duplicate = num;
            }
        }
        int expectedSum = (n * n * (n * n + 1)) / 2;

        // Missing number
        int missing = expectedSum - (actualSum - duplicate);

        return {duplicate, missing};

        
    }
};
