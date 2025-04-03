class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mi = INT_MAX, idx;
        long long ans = INT_MIN;
        long long diff = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                mi = nums[i];
            }
            else if(mi > nums[i])
                mi = nums[i];
            diff = max((long long)mx - mi, diff);
            ans = max(ans, diff * nums[i + 1]);
        }
        if(ans <= 0)
            return 0;
        return ans;
    }
};