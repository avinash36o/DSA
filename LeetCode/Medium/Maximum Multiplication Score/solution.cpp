class Solution {
    const long long INF = 1e18;

public:
    long long helper(int i, int j, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp) {
        if (i == a.size()) return 0;
        if (j >= b.size()) return -INF;
        if (dp[i][j] != -1) return dp[i][j];

        long long keep = (long long)a[i] * b[j] + helper(i + 1, j + 1, a, b, dp);
        long long notKeep = helper(i, j + 1, a, b, dp);

        return dp[i][j] = max(keep, notKeep);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(4, vector<long long>(b.size(), -1));
        return helper(0, 0, a, b, dp);
    }
};