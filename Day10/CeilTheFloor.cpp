class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int floor = -1;
        int ceil = -1;
        for (int num : arr) {
            if (num <= x && (floor == -1 || num > floor)) {
                floor = num;
            }
            if (num >= x && (ceil == -1 || num < ceil)) {
                ceil = num;
            }
        }
        return {floor, ceil};
    }
};