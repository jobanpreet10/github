class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int odd = INT_MIN, even =INT_MAX;
        for(int &i : freq){
           if(i > 0){
               if(i % 2 == 0){
                   even = min(even,i);
               } 
               else{
                   odd = max(odd,i);
               }
           }
        }
        if(odd == INT_MIN || even == INT_MIN){
            return 0;
        }
        return odd - even;
    }
};
