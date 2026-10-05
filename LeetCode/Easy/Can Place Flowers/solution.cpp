class Solution {
public:
    bool isLeftValid(int idx, vector<int>& flowerbed){
        if(idx-1<0)return true;
        if(flowerbed[idx-1]==0)return true;
        return false;
    }

    bool isRightValid(int idx, vector<int>& flowerbed){
        if(idx+1>=flowerbed.size())return true;
        if(flowerbed[idx+1]==0)return true;
        return false;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0 && isLeftValid(i, flowerbed) && isRightValid(i, flowerbed)){
                count++;
                flowerbed[i]=1;
            }
        }
        return count>=n;
    }
};