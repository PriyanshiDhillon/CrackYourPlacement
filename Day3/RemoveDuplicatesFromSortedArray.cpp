class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,bool> map;
        int i=0;
        for (int num : nums){
            if(map.find(num) == map.end()){
                map[num] = true;
                nums[i++] = num;
            }
        }
        return i;
    }
};