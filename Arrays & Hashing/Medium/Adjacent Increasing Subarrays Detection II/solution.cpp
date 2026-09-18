class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& A) {
        long long n = A.size(), ans=0, end = 0, b1 = 0, b2 = 0;
        b1=1;end=1;
        while(end<n && A[end]>A[end-1]){
            b1++;end++;
        }
        if(end==n)return b1/2;

        while (end < n) {
            b2=1; end++;
            while(end<n && A[end]>A[end-1]){
                b2++;end++;
            }
            ans=max({ans,b1/2,b2/2, min(b1,b2)});
            b1=b2; b2=0;
        }
        return ans;
    }
};