class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, currCount=0;
        for(int x: nums){
            if(x==1){
                currCount++;
            }else{
                currCount=0;
            }
            ans=max(ans,currCount);
        }
        return ans;
    }
};