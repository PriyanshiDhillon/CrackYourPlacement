class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        if (n == 0) return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int usedBricks = 0;

        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0) {
                minHeap.push(diff);
                usedBricks += diff;
                if (usedBricks > bricks) {
                    if (ladders > 0) {
                        usedBricks -= minHeap.top();
                        minHeap.pop();
                        --ladders;
                    } else {
                        return i - 1;
                    }
                }
            }
        }

        return n - 1;
    }
};