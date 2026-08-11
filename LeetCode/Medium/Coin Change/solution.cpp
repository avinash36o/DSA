class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>minCoin(amount+1, INT_MAX);
        minCoin[0]=0;

        for(int i=1; i<amount+1; i++){
            for(int coin: coins){
                if(coin<=i && minCoin[i-coin] !=INT_MAX){
                    minCoin[i]=min(minCoin[i], 1+minCoin[i-coin]);
                }
            }
        }
        return minCoin[amount] !=INT_MAX ? minCoin[amount] : -1;
    }
};