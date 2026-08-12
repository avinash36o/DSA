class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), buy=prices[0], ans=0;

        for(int i=0; i<n-1; i++){
            if(prices[i]>prices[i+1]){
                ans+=prices[i]-buy;
                buy=prices[i+1];
            }
        }
        if(buy<prices[n-1]){
            ans+=prices[n-1]-buy;
        }
        return ans;
    }
};