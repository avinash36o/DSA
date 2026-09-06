class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long firstHalf=0, secondHalf=0;
        int n=nums.size(), mid=n/2, ans=0;
        if(n==0)return 0;

        for(int i=0; i<n/2; i++){
            firstHalf+=nums[i];
        }
        for(int i=n/2; i<n; i++){
            secondHalf+=nums[i];
        }

        for(int i=0; i<n; i++){
            if(firstHalf>secondHalf)ans++;
            int leaving=nums[i];
            int entering=nums[(i+mid)%n];

            firstHalf=firstHalf-leaving+entering;
            secondHalf=secondHalf-entering+leaving;
        }
        return ans;
    }
};