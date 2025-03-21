#include<bits/stdc++.h>
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> mySet;
        for(auto x: supplies)
            mySet.insert(x);
        vector<bool> cooked(recipes.size(), false);
        int stopper = 0;
        while(1) {
            stopper++;
            int c = 0;
            for(int i = 0; i < recipes.size(); i++) {
                if(!cooked[i]) {
                    bool failed = false;
                    for(auto x: ingredients[i]){
                        if(mySet.find(x) == mySet.end()) {
                            failed = true;
                            break;
                        }
                    }
                    if(!failed){
                        mySet.insert(recipes[i]);
                        cooked[i] = true;
                        ans.push_back(recipes[i]);

                    }
                }
                else{
                    c++;
                }
            }
            if(c == recipes.size()){
                break;
            }
            if(stopper == 1000)
                break;
        }
        return ans;
    }
};