class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        vector<int>ans(queries.size());
     
        for(int i=0; i<queries.size(); i++){
            int curr=abs(queries[i][0])+abs(queries[i][1]);
            pq.push(curr);
            if(pq.size()>k)pq.pop();
            ans[i]=(pq.size()==k) ? pq.top() : -1;
        }
        return ans;
    }
};