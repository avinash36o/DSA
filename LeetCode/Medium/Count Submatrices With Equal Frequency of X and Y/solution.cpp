// p q
// r s

//dp[s]=s+r+{q-p}

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<pair<int, int>>> dp(
            row, vector<pair<int, int>>(col, {0, 0})); // no. of x,y
        if (grid[0][0] == '.') {
            dp[0][0] = {0, 0};
        } else {
            grid[0][0] == 'X' ? dp[0][0] = {1, 0} : dp[0][0] = {0, 1};
        }

        for (int i = 1; i < col; i++) { // stored x,y in 1st row
            pair<int, int> curr;
            if (grid[0][i] == '.') {
                curr = {0, 0};
            } else {
                grid[0][i] == 'X' ? curr = {1, 0} : curr = {0, 1};
            }
            dp[0][i] = {dp[0][i - 1].first + curr.first,dp[0][i - 1].second + curr.second};
            if (dp[0][i].first >= 1 && dp[0][i].first == dp[0][i].second) {
                ans++;
            }
        }

        for (int i = 1; i < row; i++) { // stored x,y in 1st col
            pair<int, int> curr;
            if (grid[i][0] == '.') {
                curr = {0, 0};
            } else {
                grid[i][0] == 'X' ? curr = {1, 0} : curr = {0, 1};
            }
            dp[i][0] = {dp[i - 1][0].first + curr.first,dp[i - 1][0].second + curr.second};
            if (dp[i][0].first >= 1 && dp[i][0].first == dp[i][0].second) {
                ans++;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                pair<int, int> curr;
                if (grid[i][j] == '.') {
                curr = {0, 0};
                } else {
                grid[i][j] == 'X' ? curr = {1, 0} : curr = {0, 1};
                }
                pair<int, int> up;
                up = {dp[i - 1][j].first - dp[i - 1][j - 1].first,
                      dp[i - 1][j].second - dp[i - 1][j - 1].second};
                pair<int, int> left;
                left = dp[i][j - 1];

                dp[i][j] = {curr.first + up.first + left.first,
                            curr.second + up.second + left.second};
                if (dp[i][j].first >= 1 && dp[i][j].first == dp[i][j].second) {
                    ans++;
                }
            }
        }
        return ans;
    }
};