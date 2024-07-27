class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust for 1-based indexing
            int rem = columnNumber % 26;
            ans = char(rem + 'A') + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};