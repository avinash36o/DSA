class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans=0, n=intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            while(pq.size()>0 && intervals[i][0]>pq.top()){
                pq.pop();
            }
            ans+=pq.size();
            pq.push(intervals[i][1]);
        }
        return ans;
    }
};