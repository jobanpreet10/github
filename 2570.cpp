class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;

        for( vector<int> vec : nums1){
            int id = vec[0];
            int num = vec[1];

            mp[id] = num;
        }

        for(vector<int> vec : nums2){
            int id = vec[0];
            int num = vec[1];
            mp[id] += num;
        }
        vector<vector<int>>ans;

        for(auto it : mp){

            int id = it.first;
            int num = it.second;
            ans.push_back({id,num});   

        }
        return ans;
    }
};
