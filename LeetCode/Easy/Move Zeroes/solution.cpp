class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = 0;
        while (zeroIdx<nums.size() && nums[zeroIdx] != 0) {
            zeroIdx++;
        }
        for (int i =zeroIdx; i < nums.size(); i++) {
            if (nums[i] != 0 && zeroIdx<nums.size()) {
                swap(nums[i], nums[zeroIdx]);
                while (zeroIdx<nums.size() && nums[zeroIdx] != 0) {
                    zeroIdx++;
                }
            }
        }
    }
};