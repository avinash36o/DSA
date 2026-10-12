class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size(), c=img[0].size();
        vector<vector<int>>ans(r,vector<int>(c));

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int sum=img[i][j], count=1;
                //up
                if(i-1>=0){
                    sum+=img[i-1][j];
                    count++;
                }
                //down
                if(i+1<r){
                    sum+=img[i+1][j];
                    count++;
                }
                //left
                if(j-1>=0){
                    sum+=img[i][j-1];
                    count++;
                }
                //right
                if(j+1<c){
                    sum+=img[i][j+1];
                    count++;
                }
                //up-left
                if(i-1>=0 && j-1>=0){
                    sum+=img[i-1][j-1];
                    count++;
                }
                //up-right
                if(i-1>=0 && j+1<c){
                    sum+=img[i-1][j+1];
                    count++;
                }
                //down-left
                if(i+1<r && j-1>=0){
                    sum+=img[i+1][j-1];
                    count++;
                }
                //down-right
                if(i+1<r && j+1<c){
                    sum+=img[i+1][j+1];
                    count++;
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};