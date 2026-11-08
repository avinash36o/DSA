class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;

        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]=0; right[n-1]=0;

        for(int i=1; i<n; i++){
            left[i]=max(height[i-1], left[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            right[i]=max(height[i+1], right[i+1]);
        }

        for(int i=0; i<n; i++){
            int currHeight=min(left[i], right[i])-height[i];
            if(currHeight>0){
                ans+=currHeight;
            }
        }
        return ans;
    }
};