class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        int a= nums.size();
        for (int i= 0; i<a ; i++){
            numMap[nums[i]] = i;
        }
        for (int i=0 ; i<a ; i++){
            int complement = target - nums[i];
            if( numMap.count(complement)&& numMap[complement] != i){
                return {i, numMap[complement] };
            }
        }
        return {};
    }
};