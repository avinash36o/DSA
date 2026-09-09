class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size(), currSpeedIdx=n-1,  count=1;
        if(n==1)return 1;

        for(int i=n-2; i>=0; i--){
            if(speed[i]>speed[currSpeedIdx] || position[i+1]-position[i]<=distance){

            }else{
                currSpeedIdx=i;
                count++;
            }
        }
        return count; 
    }
};