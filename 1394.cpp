class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num : arr){
            mp[num]++;
        }
        int ans = -1;
        for(int num : arr){
            if(mp[num] == num) ans = max(ans,num);
        }
        return ans;
    }
};
