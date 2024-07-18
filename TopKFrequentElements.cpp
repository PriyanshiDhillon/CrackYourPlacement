class Pair{
    public: 
    int num1;
    int num2;
    Pair(int n1, int n2){
        num1 = n1;
        num2 = n2;
    }
};

struct comp{
    bool operator()(Pair &n1, Pair &n2){
        return n1.num2 < n2.num2;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<Pair, vector<Pair>, comp> heap;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        for (auto it = map.begin(); it != map.end(); ++it){
            heap.push(Pair(it->first, it->second));
        }

        while(k>=1){
            Pair p = heap.top(); heap.pop();
            ans.push_back(p.num1);
            k--;
        }
        return ans;

    }
};
