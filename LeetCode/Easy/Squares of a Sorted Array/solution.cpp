class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>freq(10001,0);
        for(int x: nums){
            freq[abs(x)]++;
        }
        vector<int>ans;

        for(int i=0; i<freq.size(); i++){
            if(freq[i]>0){
                while(freq[i]>0){
                    ans.push_back(i*i);
                    freq[i]--;
                }
            }
        }
        return ans;
    }
};