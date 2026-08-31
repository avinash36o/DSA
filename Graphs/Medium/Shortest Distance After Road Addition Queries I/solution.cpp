class Solution {
public:
    int bfs(vector<vector<int>>& graph, int n) {
        queue<int>q;
        vector<int>dis(n,-1);
        q.push(0);
        dis[0]=0;

        while(!q.empty()){
            int src=q.front();
            q.pop();
            if(src==n-1)return dis[src];
            for(int x:graph[src]){
                if(dis[x]==-1){
                    q.push(x);
                    dis[x]=dis[src]+1;
                }
            }
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<int> ans;

        vector<vector<int>> graph(n);

        // Initial roads
        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }

        // Process queries
        for (int i = 0; i < queries.size(); i++) {

            int u = queries[i][0];
            int v = queries[i][1];

            graph[u].push_back(v);

            // Find shortest path after this query
            ans.push_back(bfs(graph, n));
        }

        return ans;
    }
};