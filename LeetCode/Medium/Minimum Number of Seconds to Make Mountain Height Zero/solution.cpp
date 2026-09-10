class Solution {
public:
    int h;
    bool canFinish(long long time, vector<int>& workerTimes){
        long long ans=0;

        for(int x: workerTimes){
            long long work=(sqrt(1+(8*time/x))-1)/2;
            ans+=work;
            if(ans>=h)return true;
        }
        return ans>=h;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long st=0, end=1e18, ans=1e18;
        h=mountainHeight;
        while(st<=end){
            long long mid=st + (end-st)/2;
            if(canFinish(mid, workerTimes)){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};