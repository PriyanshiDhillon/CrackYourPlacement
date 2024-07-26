class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string a = "";
        sort(strs.begin(),strs.end());
        int n= strs.size();
        string s=strs[0], l= strs[n-1];
        for (int i = 0 ; i< min(s.size(),l.size()) ; i++ ){
            if (s[i]!= l[i]){
                return a;
            }
            a= a+s[i];
        }
        return a;
    }
};