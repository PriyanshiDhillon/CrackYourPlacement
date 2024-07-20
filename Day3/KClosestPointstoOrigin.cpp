class dt{
    public:
    int pos;
    int dist;
    dt(int p, int d){
        pos = p;
        dist = d;
    }
};

struct mycomp{
    bool operator()(dt &n1, dt &n2){
        return n1.dist > n2.dist;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<dt, vector<dt>, mycomp> heap;
        vector<vector<int>> ans; 
        for (int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = (x*x) + (y*y);
            heap.push(dt(i,distance));
        }
        for(int i=0; i<k; i++){
            dt add = heap.top(); heap.pop();
            ans.push_back(points[add.pos]);
        }
        return ans;
    }
};