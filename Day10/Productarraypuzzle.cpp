class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> ans(n, 1);
        vector<long long int> left(n, 1);
        vector<long long int> right(n, 1);

        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int j = n - 2; j >= 0; --j) {
            right[j] = right[j + 1] * nums[j + 1];
        }

        for (int k = 0; k < n; ++k) {
            ans[k] = left[k] * right[k];
        }

        return ans;
    }
};