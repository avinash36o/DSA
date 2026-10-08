class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //rotate up-down then swap the symmetry
        int r=matrix.size(), c=matrix[0].size();
        for(int i=0; i<c; i++){
            int st=0, end=r-1;
            while(st<=end){
                swap(matrix[st][i], matrix[end][i]);
                st++;end--;
            }
        }

        for(int i=0; i<r; i++){
            for(int j=i+1; j<c; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};