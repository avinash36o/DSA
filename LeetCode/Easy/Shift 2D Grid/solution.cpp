class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>>ans(r, vector<int>(c));
        k=k%(r*c);

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int idx=i*c+j;

                int newIdx=(idx+k)%(r*c);
                int newRow=newIdx/c;
                int newCol=newIdx%c;

                ans[newRow][newCol]=grid[i][j];
            }
        }
        return ans;
    }
};