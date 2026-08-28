class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(), verticalCut.end(),greater<int>());
        int rowCount=1, colCount=1,ans=0,i=0,j=0;

        while(i<horizontalCut.size() && j<verticalCut.size()){
            if(horizontalCut[i]>=verticalCut[j]){
                ans+=horizontalCut[i]*colCount; //ye saare col ko cross krega
                rowCount++;
                i++;
            }else{
                ans+=verticalCut[j]*rowCount;//ye saare row ko cross krega
                colCount++;
                j++;
            }
        }
        while(i<horizontalCut.size()){
            ans+=horizontalCut[i]*colCount; //ye saare col ko cross krega
            rowCount++;i++;
        }
        while(j<verticalCut.size()){
            ans+=verticalCut[j]*rowCount;//ye saare row ko cross krega
            colCount++;j++;
        }
        return ans;
    }
};