class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll , vector<ll> , greater<ll>>pq(nums.begin(), nums.end());

        
        int operations = 0;
        while( !pq.empty() && pq.top() < k){
            ll  x = pq.top(); 
            pq.pop();
            
            if(pq.empty()){
                operations++;
                break;
            }

            ll   y = pq.top();
            pq.pop();
          
            ll num = x*2 + y;

            pq.push(num);
            operations++;
        }
        
        return operations;
    }
};
