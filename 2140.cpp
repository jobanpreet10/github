class Solution {
public:
    vector<long long >dp;
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n+1,0);
        for(int i = n-1;i >= 0; i--){
           long long take = questions[i][0]; // If we take this question
            int nextIndex = i + questions[i][1] + 1;
            if (nextIndex < n) {
                take += dp[nextIndex]; // Add points from future valid questions
            }
        
            long long skip = dp[i+1];

            dp[i] = max(take,skip);
        }
        return dp[0];
    }
};
