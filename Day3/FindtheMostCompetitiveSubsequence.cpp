class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[i]< nums[st.top()] && st.size()+ nums.size()-i > k){
                st.pop();
            }
            if(st.size()<k) st.push(i);
        }

        vector<int> ans(k);
        for (int i=k-1; i>=0; i--){
            int a = st.top(); st.pop();
            ans[i] = nums[a];
        }

        return ans;
    }
};