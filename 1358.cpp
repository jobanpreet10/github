class Solution {
public:
   
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i = 0, j = 0;
        int n = s.length();

        int cnt = 0;
        while( j < n){
            char ch = s[j];
           
            mp[ch]++;
            
            while(mp.size() == 3 ){
                cnt += n -j ;
                // shrinking the window;
                char c = s[i];
                mp[c]--;
                if(mp[c] == 0){
                    mp.erase(c);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};
