class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>v(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int k=rowShift[i];
                int changedIdx=(j-k+n)%n;
                v[i][changedIdx]=grid[i][j];
            }
        }
vector<vector<int>>v2(n, vector<int>(n));
        
        for(int col=0; col<n; col++){
            for(int row=0; row<n; row++){
                int k=colShift[col];
                int chanegdIdx=(row-k+n)%n;
                v2[chanegdIdx][col]=v[row][col];
            }
        }
        return v2;
        
    }
};