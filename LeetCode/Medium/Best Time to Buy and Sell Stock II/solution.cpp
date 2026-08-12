class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(n+1,0);

        for(int i=2; i<n+1; i++){
            int profitToday=prices[i-1]-prices[i-2];
            if(profitToday>0){
                ans[i]=ans[i-1]+profitToday;
            }else{
                ans[i]=ans[i-1];
            }
        }
        return ans[n];
    }
};