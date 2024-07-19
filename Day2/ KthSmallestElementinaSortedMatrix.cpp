class pos{
    public:
    int posx,posy,data;
    pos(int x, int y, int d){
        posx = x;
        posy = y;
        data = d;
    }
};

struct mycomp{
    bool operator()(pos &n1, pos &n2){
        return n1.data > n2.data;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         int n = matrix.size();
        int count = 0;
        priority_queue<pos, vector<pos>, mycomp> heap;
        
        for (int i = 0; i < n; i++) {
            heap.push(pos(i, 0, matrix[i][0]));
        }

        while (!heap.empty()) {
            pos num = heap.top();
            heap.pop();
            count++;
            if (count == k) return num.data;
            if (num.posy < n - 1) {
                heap.push(pos(num.posx, num.posy + 1, matrix[num.posx][num.posy + 1]));
            }
        }

        return -1; 
    }
};