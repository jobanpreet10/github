
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxlen = 0;

        unordered_map<int, int>mp;

        for(int i = 0; i < n ; i++){
            mp[arr[i]] = i;
        }
        for(int i = 0;  i < n; i++){
            for(int j = i+1 ; j < n; j++){

                int a = arr[i] , b = arr[j] , len  = 2;
                // cout<< num;
                  while(mp.find(a + b) != mp.end()) {
                    int x = a + b;
                    len++;
                    a = b;
                    b = x;
                }
                maxlen = max(maxlen, len);  
            }
        }
        return (maxlen > 2) ? maxlen : 0;  
    }
};
