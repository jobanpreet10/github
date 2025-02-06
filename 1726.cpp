class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n  = nums.size();
        map<int,int>mp;
        for(int i =0 ; i< n ; i++){
            for(int j = i+1; j < n; j++){
                int prod = nums[i]*nums[j];
                mp[prod] ++;
             }
        }
        int count  = 0;
        for(auto it : mp){
            int freq = it.second;
             if (freq > 1) {
            count += (freq * (freq - 1) / 2) * 8;  // Formula explained above
        }
        }
       
    return count;
    }
};
