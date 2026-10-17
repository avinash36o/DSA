class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int bestRowMin = INT_MIN;

        for (int i = 0; i < rows; ++i) {
            int mn = matrix[i][0];

            for (int j = 1; j < cols; ++j) {
                mn = min(mn, matrix[i][j]);
            }

            bestRowMin = max(bestRowMin, mn);
        }

        int bestColMax = INT_MAX;

        for (int j = 0; j < cols; ++j) {
            int mx = matrix[0][j];

            for (int i = 1; i < rows; ++i) {
                mx = max(mx, matrix[i][j]);
            }

            bestColMax = min(bestColMax, mx);
        }

        if (bestRowMin == bestColMax)
            return {bestRowMin};

        return {};
    }
};