class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestTillNow=-1;
        for(int i=arr.size()-1; i>=0; i--){
            int curr=arr[i];
            arr[i]=greatestTillNow;
            greatestTillNow=max(greatestTillNow,curr);
        }
        return arr;
    }
};