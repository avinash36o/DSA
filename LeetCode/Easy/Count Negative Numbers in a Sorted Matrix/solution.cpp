class Solution {
public:
    int leftmostIdx(int row,int e, vector<vector<int>>& grid){
        int st=0, end=e, ans=-1, r=row;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(grid[r][mid]<0){
                ans=mid;
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        return ans;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        int count=0, end=c-1;

        for(int i=0; i<r; i++){
            int tarIdx=leftmostIdx(i,end,grid);
            if(tarIdx==-1)continue;
            else{
                count+=(end-tarIdx+1)*(r-i);
                end=tarIdx-1;
                if(end<0)break;
            }
        }
        return count;
    }
};