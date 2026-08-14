class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // First column
        for (int r = 1; r < rows; r++) {
            grid[r][0] += grid[r - 1][0];
        }

        // First row
        for (int c = 1; c < cols; c++) {
            grid[0][c] += grid[0][c - 1];
        }

        // Rest of the grid
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
            }
        }

        return grid[rows - 1][cols - 1];
    }
};