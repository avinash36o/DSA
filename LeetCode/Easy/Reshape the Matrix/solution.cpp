class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        if(m*n != r*c)return mat;
        vector<vector<int>>ans(r,vector<int>(c));
        int currRow=0, currCol=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(currCol>=c){
                    currCol=0;
                    currRow++;
                }
                ans[currRow][currCol]=mat[i][j];
                currCol++;
            }
        }
        return ans;
    }
};