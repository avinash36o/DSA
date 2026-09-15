class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        stack<long long>st;
        st.push(nums[0]);

        for(int i=1; i<=n; i++){
            if(i<n && nums[i]>=st.top())st.push(nums[i]);
            else{
                long long countSame=1;
                while(!st.empty() &&(i==n || nums[i]<st.top())){
                    int prev=st.top();
                    st.pop();
                    if(!st.empty() && prev!=st.top()){
                        ans+=(long long)st.size()*countSame;
                        countSame=1;
                    }else if(!st.empty() && prev==st.top()) countSame++;
                }
                if(i<n)st.push(nums[i]);
            }
        }
        return ans;
    }
};