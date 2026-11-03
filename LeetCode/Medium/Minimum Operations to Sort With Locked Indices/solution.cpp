class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size(), res=0, maxNum=0, cn=0;

        for(int i=0; i<n-1; i++){
            maxNum=max(maxNum, nums[i]);
            if(maxNum>i+1){
                res+=locked[i]+locked[i+1];
                locked[i]=locked[i+1]=0;
            }
        }
        if(res>k)return -1;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]>nums[j]){
                    cn++;
                }
            }
        }
        return res+cn;
    }
};