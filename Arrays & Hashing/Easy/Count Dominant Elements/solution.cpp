class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size(), ans=0;
        if(n==1)return 1;
        if(nums[0]>=(nums[1])){
            ans++;
        }
        if(nums[n-1]>=nums[n-2]){
            ans++;
        }

        for(int i=1; i<=n-2; i++){
            if((double)nums[i]>=(double)(nums[i-1]+nums[i+1])/2){
                ans++;
            }
        }
        return ans;
    }
};