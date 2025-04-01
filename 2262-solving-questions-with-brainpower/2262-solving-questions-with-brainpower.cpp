class Solution {
public:

    long long f(vector<vector<int>> &q, int i, vector<long long> &dp) {
        // cout << i << endl;
        if(i >= q.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        dp[i] = max(q[i][0] + f(q, q[i][1] + i + 1, dp), f(q, i + 1, dp));
        return dp[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(1000000, -1);
        long long ans = max(questions[0][0] + f(questions, questions[0][1] + 1, dp), f(questions, 1, dp));
        return ans;
    }
};