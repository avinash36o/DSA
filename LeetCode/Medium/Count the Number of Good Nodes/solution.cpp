class Solution {
public:
    int ans=0;
    vector<vector<int>>neighbour;

    int dfs(int node, int par){
        int size=1;
        unordered_map<int,int>m;//freq of each size child
        for(auto child: neighbour[node]){
            if(child!=par){
                int subtree=dfs(child,node);
                size+=subtree;//saare subtree k size ka sum
                m[subtree]++;
            }
        }
        if(m.size()<=1)ans++;//saare child ka same size
        return size;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        neighbour.resize(n);
        for(auto x: edges){
            neighbour[x[0]].push_back(x[1]);
            neighbour[x[1]].push_back(x[0]);
        }
        dfs(0,-1);
        return ans;
    }
};