class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(), ans=0;
        vector<int>rowInfo(r,0);
        vector<int>colInfo(c,0);

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    rowInfo[i]++;
                    colInfo[j]++;
                }
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 && (rowInfo[i]>1 || colInfo[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};