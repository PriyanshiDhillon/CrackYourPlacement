class ds{
    public:
    int pos,freq;
    char c;
    ds(char ch, int f, int p){
        c = ch;
        freq = f;
        pos = p;
    }
};

struct mycomp{
    bool operator()(ds &n1, ds &n2){
        if (n1.freq == n2.freq) {
            return n1.pos > n2.pos;
        }
        return n1.freq < n2.freq;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> map;
        priority_queue<ds, vector<ds>, mycomp> heap;
        string ans = "";

        for(char c : s){
            map[c]++;
        }
        for(auto it : map){
            heap.push(ds(it.first, it.second, -1));
        }

        ds prev('#', -1, -1);
        while(!heap.empty()){
            ds curr = heap.top();
            heap.pop();
            ans = ans + curr.c;
            curr.pos = ans.size() - 1;
            curr.freq --;
            if (prev.freq > 0){
                heap.push(prev);
            }
            prev = curr;
        }

        if(ans.size() != s.size()) return "";
        return ans;
    }
};