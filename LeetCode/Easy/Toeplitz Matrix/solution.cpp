class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        for(int i=0; i<col; i++){
            int r=0, c=i;
            int curr=matrix[r][c];
            while(r<row && c<col){
                if(matrix[r][c] !=curr){
                    return false; break;
                }
                r++; c++;
            }
        }

        for(int i=1; i<row; i++){
            int r=i, c=0;
            int curr=matrix[r][c];
            while(r<row && c<col){
                if(matrix[r][c] !=curr){
                    return false; break;
                }
                r++; c++;
            }
        }

        return true;
    }
};