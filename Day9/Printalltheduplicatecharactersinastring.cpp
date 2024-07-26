#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    // Write your code here.
    unordered_map<char,int> map;
    vector<pair<char,int>> ans;
    for(int i = 0; i < s.size(); i++){
        map[s[i]]++;
    }
    for(auto it : map){
        if(it.second > 1){
            ans.push_back({it.first, it.second});
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}