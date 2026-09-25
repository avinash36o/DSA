class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            map[x].push_back(i);
            if (map[x].size() == 3 &&
                (map[x])[1] - (map[x])[0] == (map[x])[2] - (map[x])[1]) {
                ans++;
            }
            if (map[x].size() == 4
                &&(map[x])[1] - (map[x])[0] == (map[x])[2] - (map[x])[1])
                ans--;
        }
        return ans;
    }
};