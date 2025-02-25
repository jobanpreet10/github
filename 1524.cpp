class Solution {
public:
    int MOD = 1e9 +7;
    int numOfSubarrays(vector<int>& arr) {
        int count  = 0;
        int n = arr.size();
        // vector<int>prefixSum(n,0);
        // prefixSum[0] =  arr[0];

        // for(int i = 1; i< n; i++){
        //     prefixSum[i] = prefixSum[i-1] + arr[i];
        // }
        int sum = 0;
        int evenCount = 1, oddCount = 0;
        for(int i =0 ; i < n; i++){
            sum += arr[i];
            if(sum % 2 == 0 ){
                count = (count + oddCount) % MOD;
                evenCount++;
            }
            else{
                count = (count + evenCount) % MOD;
                oddCount++;
            }
        }
        return count % MOD;
    }
};
