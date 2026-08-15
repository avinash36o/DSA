class Solution {
public:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool> &vis){
        vis[u]=true;
        vector<int>v=isConnected[u];

        for(int i=0; i<v.size(); i++){
            if(!vis[i] && v[i]!=0){
                dfs(i,isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), ans=0;
        vector<bool>vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;
    }
};