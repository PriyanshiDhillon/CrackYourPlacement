class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int maxArea = 0;
        vector<int> left(n), right(n);

        left[0] = -1; 
        for (int i = 1; i < n; ++i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }
        
        right[n - 1] = n;
        for (int i = n - 2; i >= 0; --i) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = right[p];
            }
            right[i] = p;
        }
        
        
        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};
