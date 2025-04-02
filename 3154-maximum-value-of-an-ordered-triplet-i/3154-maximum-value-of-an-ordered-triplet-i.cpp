#include<bits/stdc++.h>
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        int a, b, c;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    long long temp = (long long)(((long long)nums[i] - (long long)nums[j]) * (long long)nums[k]); 
                    // ans = max(ans, temp);
                    if(ans < temp) {
                        ans = temp;
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }
        if(ans < 0)
            return 0;
        cout << a  << " " << b << " " << c ;
        return ans;
    }
};