class Solution {
public:
    int f(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        
        if(sum == 0) {
            return 1;
        }
        if(i >= nums.size())
            return 0;
        if(sum < 0)
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        dp[i][sum] = (f(i + 1, sum - nums[i], nums, dp) | f(i + 1, sum, nums, dp));
        return dp[i][sum];

    }


    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums)
            sum += x;
        
        if(sum % 2)
            return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return (bool)f(0, sum, nums, dp);
    }
};