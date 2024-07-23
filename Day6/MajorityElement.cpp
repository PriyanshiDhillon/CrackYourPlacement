class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int max=0,num;
        for (auto it:freq){
            if (it.second > max){
                max = it.second;
                num = it.first;
            }
        }
        return num;
    }
};