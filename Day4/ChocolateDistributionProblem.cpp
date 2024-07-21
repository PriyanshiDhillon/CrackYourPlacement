class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        int i=0, min= INT_MAX;
        for(int j=m-1; j<a.size(); j++){
            if (a[j]-a[i] < min){
                min = a[j]-a[i];
            }
            i++;
        }
        return min; 
    }
};