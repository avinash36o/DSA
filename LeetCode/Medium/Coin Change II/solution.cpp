class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int row=coins.size();
        vector<vector<unsigned int>>dp(row+1, vector<unsigned int>(amount+1,0));
        for(int i=0; i<row+1; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<row+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){//valid
                    dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j]; //include + exclude
                }else{//invalid
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[row][amount];
    }
};