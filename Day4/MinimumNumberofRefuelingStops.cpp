class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0, ans;
        priority_queue<int> heap;
        for(ans =0; startFuel<target; ans++){
            while(i<stations.size() && stations[i][0]<=startFuel){
                heap.push(stations[i++][1]);
            }
            if(heap.empty()) return -1;
            startFuel += heap.top(); heap.pop();
        }
        return ans;
    }

};