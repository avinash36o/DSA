class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        int ans=0, topCount=0, xzCount=0, yzCount=0;
        //top
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]>0)topCount++;
            }
        }
        //XZ View
        for(int i=0; i<c; i++){
            int currMax=0;
            for(int j=0; j<r; j++){
                currMax=max(currMax, grid[j][i]);
            }
            xzCount+=currMax;
        }

        //YZ View
        for(int i=0; i<r; i++){ 
            int currMax=0;
            for(int j=0; j<c; j++){
                currMax=max(currMax, grid[i][j]);
            }
            yzCount+=currMax;
        }
        return topCount+xzCount+yzCount;
    }
};