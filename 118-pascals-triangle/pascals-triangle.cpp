
class Solution {
public:
    int nCr(int n, int r) {
        int res = 1;
        for (int i = 0; i < r; i++) {
            res *= n - i;
            res /= i + 1;
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> subset;
            for (int j = 0; j <= i; j++) {
                subset.push_back(nCr(i, j));
            }
            ans.push_back(subset);
        }

        return ans;
    }
};
