class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> seen;
        heap.push(1);
        seen.insert(1);
        long ugly = 1;

        for(int i=0; i<n; i++){
            ugly = heap.top();
            heap.pop();

            if (seen.insert(ugly * 2).second) heap.push(ugly * 2);
            if (seen.insert(ugly * 3).second) heap.push(ugly * 3);
            if (seen.insert(ugly * 5).second) heap.push(ugly * 5);
        }
        return static_cast<int>(ugly);
    }
};