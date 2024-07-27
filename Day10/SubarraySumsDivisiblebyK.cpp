class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count = 0;
        int sum = 0;
        int rem = 0;
        map[rem]++;
        for(int num:nums){
            sum += num;
            rem = sum%k;
            if(rem<0){
                rem += k;
            }
            if(map.find(rem) != map.end()){
                count += map[rem];
            }
            map[rem] ++;
        }
        return count;
    }
};