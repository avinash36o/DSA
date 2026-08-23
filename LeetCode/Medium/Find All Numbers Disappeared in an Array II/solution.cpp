class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int prev=lower;

        for(int x: nums){
            if(x<lower || x>upper)continue;
            if(x>prev){
                ans.push_back({prev, x-1});
            }
            prev=x+1;
        }
        if(prev<=upper){
            ans.push_back({prev, upper});
        }
        return ans;
    }
};