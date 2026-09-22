class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int curr = mat[i][j];
                bool peak = true;
                for (int k = 0; k < 4; k++) {
                    int nrow = i + di[k];
                    int ncol = j + dj[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                        if (curr <= mat[nrow][ncol]) {
                            peak = false;
                            break;
                        }
                    }
                }
                if (peak)
                    return {i, j};
            }
        }
        return {};
    }
};