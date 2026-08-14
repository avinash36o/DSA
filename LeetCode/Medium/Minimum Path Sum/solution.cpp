class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid,vector<vector<bool>> &vis){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0){
            return (200*200*200)+1;
        }
        if(dp[i][j] !=-1)return dp[i][j];
        if(vis[i][j])return (200*200*200)+1;
        vis[i][j]=true;
        
        //right
        int right=helper(i, j+1, dp, grid,vis);
        //down
        int down=helper(i+1, j, dp, grid,vis);
        // //left
        // int left=helper(i, j-1,dp,grid,vis);
        // //up
        // int up=helper(i-1, j, dp, grid,vis);

        return dp[i][j]=min(right,down) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        dp[m-1][n-1]=grid[m-1][n-1];
        return helper(0,0,dp,grid,vis) ;
    }
};