class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size(), ans=LLONG_MIN;
        vector<long long>preSum(n,nums[0]);
        unordered_map<int,vector<int>>m;
        //built preSum
        for(int i=1; i<n; i++){
            preSum[i]=preSum[i-1] + nums[i];
        }         

        for(int i=0; i<n; i++){
            int x1=nums[i];
            if(m[x1-k].size()>0){
                for(auto idx: m[x1-k]){
                    long long curr= idx>0 ? preSum[i]-preSum[idx-1] : preSum[i];
                    ans=max(ans,curr);
                }
            }
            if(m[x1+k].size()>0){
                for(auto idx: m[x1+k]){
                    long long curr= idx>0 ? preSum[i]-preSum[idx-1] : preSum[i];
                    ans=max(ans,curr);
                }
            }
            if(m[x1].size()==0){
                m[x1].push_back(i);
            }else{
                long long firstNum= m[x1][0]==0 ? 0 : preSum[m[x1][0]-1];
                long long secondNum= i==0 ? 0 : preSum[i-1];
                if(secondNum<firstNum){
                    m[x1].pop_back();
                    m[x1].push_back(i);
                }
            }
        }
        return ans==LLONG_MIN ? 0: ans;
    }
};