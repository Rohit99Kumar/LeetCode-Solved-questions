class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int min = cost[0];
        for(auto x: cost){
            if(min > x)
                min = x;
            ans.push_back(min);
        }
        return ans;
    }
};