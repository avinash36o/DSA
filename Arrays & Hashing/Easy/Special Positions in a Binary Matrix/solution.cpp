class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row=mat.size(), col=mat[0].size(), ans=0;
        vector<int>rowCount(row,0), colCount(col,0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]==1 && rowCount[i]==1 && colCount[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};