#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }    

    int longestPalindrome(string s, string t) {
        vector<string> subs, subt;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                subs.push_back(s.substr(i, j - i + 1));
            }
        }
        subs.push_back("");
        for(int i= 0; i < t.size(); i++){
            for(int j = i; j < t.size(); j++) {
                subt.push_back(t.substr(i, j - i + 1));
            }
        }
        subt.push_back("");
        int ans = 0;
        for(int i = 0; i < subs.size(); i++) {
            for(int j = 0; j < subt.size(); j++) {
                string st;
                st = subs[i] + subt[j];
                if(isPalindrome(st)){
                    if(ans < st.size())
                        ans = st.size();
                }
            }
        }
        return ans;
    }
};